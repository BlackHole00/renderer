#include <std/runtime/allocators/arena_allocator_page.h>

#include <unistd.h>

usize PAGE_SIZE = 0;
static before_main void init_page_size() {
	PAGE_SIZE = sysconf(_SC_PAGESIZE);
}

