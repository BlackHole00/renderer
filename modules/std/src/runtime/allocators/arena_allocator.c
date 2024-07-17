/**
 * @module STD
 * @file modules/std/src/runtime/allocators/arena_allocator.c
 * @author Vicix (www.github.com/BlackHole00)
 */
#include <std/runtime/allocators/arena_allocator.h>

#include <std/lang/mem.h>

static Slice(byte) arenaallocator_alloc(void* data, usize size, bool zeroed) {
	ArenaAllocatorData* arena = (ArenaAllocatorData*)(data);
	void* allocation;

	// Tries to allocate from the last page
	ArenaAllocatorPage current_page = arena->last_page;
	while (arenaallocatorpage_is_valid(current_page)) {
		allocation = arenaallocatorpage_alloc(arena->last_page, size);
		current_page.base_address = current_page.contents->prev_page;

		if (allocation == nullptr) {
			continue;
		}

		if (zeroed) {
			memset(allocation, 0, size);
		}
		return slice_from(byte)(allocation, size);
	}

	// There are no pages free. Allocate a new one
	ArenaAllocatorPage new_page = arenaallocatorpage_create(size);
	if (!arenaallocatorpage_is_valid(arena->first_page)) {
		return slice_make_null(byte)();
	}

	new_page.contents->prev_page = arena->last_page.contents->page_content;
	arena->last_page.contents->next_page = new_page.base_address;

	// Try to allocate in the last page
	allocation = arenaallocatorpage_alloc(arena->last_page, size);
	if (allocation == nullptr) {
		return slice_make_null(byte)();
	}

	if (zeroed) {
		memset(allocation, 0, size);
	}
	return slice_from(byte)(allocation, size);
}

// TODO(Vicix): Implement warnings
static void arenaallocator_dealloc(void*, Slice(byte)) {}

static Slice(byte) arenaallocator_realloc(void* data, Slice(byte) slice, usize size, bool zeroed) {
	Slice(byte) allocation = arenaallocator_alloc(data, size, false);
	memcpy(allocation.data, slice.data, (size > slice.length) ? size : slice.length);

	if (zeroed && slice.length < size) {
		memset(&allocation.data[slice.length], 0, size - slice.length);
	}

	return allocation;
}

static void arenaallocator_dealloc_all(void* data) {
	ArenaAllocatorData* arena = (ArenaAllocatorData*)(data);

	ArenaAllocatorPage current_page = arena->last_page;
	while (current_page.contents->prev_page != nullptr) {
		void* next_page = current_page.contents->prev_page;
		arenaallocatorpage_delete(current_page);
		
		current_page.base_address = next_page;
	}

	current_page.contents->next_page = nullptr;
	current_page.contents->first_free_index = 0;

	arena->first_page = current_page;
	arena->last_page = current_page;
}

static auto singleton_of(vtable_of(ArenaAllocator)) = (vtable_of(Allocator)){
	.alloc = arenaallocator_alloc,
	.dealloc = arenaallocator_dealloc,
	.realloc = arenaallocator_realloc,
	.dealloc_all = arenaallocator_dealloc_all,
};

ArenaAllocator arenaallocator_create(Allocator backing_allocator) {
	ArenaAllocatorData* arena = new(ArenaAllocatorData, backing_allocator);
	// TODO(Vicix): Do not assert
	assert(arena != nullptr);

	ArenaAllocatorPage page = arenaallocatorpage_create(0);
	// TODO(Vicix): Do not assert
	assert(arenaallocatorpage_is_valid(page));

	arena->backing_allocator = backing_allocator;
	arena->first_page = page;
	arena->last_page = page;

	return (ArenaAllocator){
		.allocator_data = arena,
		.vtable = &singleton_of(vtable_of(ArenaAllocator)),
	};
}

void arenaallocator_delete(ArenaAllocator allocator) {
	ArenaAllocatorData* arena = (ArenaAllocatorData*)(allocator.allocator_data);

	ArenaAllocatorPage current_page = arena->last_page;
	while (arenaallocatorpage_is_valid(current_page)) {
		void* next_page = current_page.contents->prev_page;
		arenaallocatorpage_delete(current_page);
		
		current_page.base_address = next_page;
	}

	delete(arena, arena->backing_allocator);
}


