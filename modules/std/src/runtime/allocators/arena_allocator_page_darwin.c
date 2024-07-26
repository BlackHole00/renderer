/**
 * @module STD
 * @file modules/std/src/runtime/allocators/system_allocator_page_darwin.c
 * @author Vicix (www.github.com/BlackHole00)
 */
#include <std/runtime/allocators/arena_allocator.h>
#ifdef BUILD_OS_DARWIN

#include <sys/mman.h>

static usize get_required_page_size(usize required_size) {
	// NOTE(Vicix): required_size + header
	usize actual_required_size_bytes = required_size + 3 * sizeof(usize);
	if (actual_required_size_bytes < PAGE_SIZE) {
		return PAGE_SIZE / sizeof(usize);
	}

	usize page_count = ((actual_required_size_bytes - 1) / PAGE_SIZE) + 1;
	usize aligned_size_bytes = page_count * PAGE_SIZE;
	usize aligned_size_words = aligned_size_bytes / sizeof(usize);

	return aligned_size_words;
}

ArenaAllocatorPage arenaallocatorpage_create(usize required_size) {
	usize page_size = get_required_page_size(required_size);

	ArenaAllocatorPage page;
 	page.base_address = mmap(
		nullptr, 
		page_size,
		PROT_READ | PROT_WRITE, 
		MAP_ANONYMOUS | MAP_PRIVATE, 
		-1, 
		0
	);

	page.contents->next_page = nullptr;
	page.contents->first_free_index = 0;
	page.contents->page_size = page_size;

	return page;
}

void arenaallocatorpage_delete(ArenaAllocatorPage page) {
	munmap(page.base_address, 0);
}

#endif
