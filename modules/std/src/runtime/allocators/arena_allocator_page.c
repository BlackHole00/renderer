/**
 * @module STD
 * @file modules/std/src/runtime/allocators/system_allocator_page.c
 * @author Vicix (www.github.com/BlackHole00)
 */
#include <std/runtime/allocators/arena_allocator_page.h>

#include <unistd.h>

usize PAGE_SIZE = 0;
static before_main void init_page_size() {
	PAGE_SIZE = sysconf(_SC_PAGESIZE);
}

