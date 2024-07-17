#pragma once

#include <std/lang/types.h>

extern usize PAGE_SIZE;

// A block of mmapped memory. The first 64 bits are reserved for the address of
// the next block. The 65th to 128th bits are reserved to the pointer to the 
// first free address in the block;
typedef union {
	void* base_address;
	struct{
		// NOTE(Vicix): Should be of type ArenaAllocatorPage, but C complains, 
		// since it wants ArenaAllocatorPage* and it cannot see that 
		// ArenaAllocatorPage is itself a pointer;
		void* next_page;
		void* prev_page;
		// @index_of ArenaAllocatorPage->contents.page_content
		usize first_free_index;
		byte page_content[1];
	}* contents;
} ArenaAllocatorPage;

ArenaAllocatorPage arenaallocatorpage_create();
void arenaallocatorpage_delete(ArenaAllocatorPage page);

static inline bool arenaallocatorpage_is_valid(ArenaAllocatorPage page) {
	return page.base_address != nullptr;
}
static inline void* arenaallocatorpage_get_first_free_address(ArenaAllocatorPage page) {
	return (void*)(page.contents->page_content + page.contents->first_free_index);
}
static inline bool arenaallocatorpage_can_alloc(ArenaAllocatorPage page, usize size) {
	return (page.contents->first_free_index + 2 + size) >= PAGE_SIZE;
}
static inline void* arenaallocatorpage_alloc(ArenaAllocatorPage page, usize size) {
	if (!arenaallocatorpage_can_alloc(page, size)) {
		return nullptr;
	}

	void* ptr = arenaallocatorpage_get_first_free_address(page);
	page.contents->first_free_index += size;
	return ptr;
}

