#pragma once

#include <std/lang/descriptor.h>
#include <std/runtime/allocator.h>
#include <std/runtime/allocators/arena_allocator_page.h>

typedef struct {
	Allocator backing_allocator;
	ArenaAllocatorPage first_page;
	ArenaAllocatorPage last_page;
} ArenaAllocatorData;

typedef Allocator ArenaAllocator;

ArenaAllocator arenaallocator_create(Allocator backing_allocator);
void arenaallocator_delete(ArenaAllocator allocator);

