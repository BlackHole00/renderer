#pragma once

#include <std/lang/singleton.h>
#include <std/runtime/allocator.h>

typedef Allocator SystemAllocator;
extern singleton SystemAllocator singleton_of(SystemAllocator);
