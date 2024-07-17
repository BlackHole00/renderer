/**
 * @module STD
 * @file modules/std/include/std/runtime/allocators/system_allocator.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <std/lang/singleton.h>
#include <std/runtime/allocator.h>

typedef Allocator SystemAllocator;
extern singleton SystemAllocator singleton_of(SystemAllocator);
