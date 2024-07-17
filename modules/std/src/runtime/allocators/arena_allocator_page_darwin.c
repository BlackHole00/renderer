#ifdef BUILDER_OS_DARWIN
#include <std/runtime/allocators/arena_allocator.h>

#include <sys/mman.h>

ArenaAllocatorPage arenaallocatorpage_create() {
	ArenaAllocatorPage page;
 	page.base_address = mmap(
		nullptr, 
		PAGE_SIZE, 
		PROT_READ | PROT_WRITE, 
		MAP_ANONYMOUS | MAP_PRIVATE, 
		-1, 
		0
	);

	page.contents->next_page = nullptr;
	page.contents->first_free_index = 0;
	page.contents->page_size = PAGE_SIZE;

	return page;
}

void arenaallocatorpage_delete(ArenaAllocatorPage page) {
	munmap(page.base_address, 0);
}

#endif
