#pragma once

#include <std/lang/types.h>
#include <std/lang/vtable.h>
#include <std/lang/singleton.h>

#include <std/runtime/slice.h>

typedef Slice(byte) (*Allocator_AllocFn)(void* allocator_data, usize size, bool zeroed);
typedef void  (*Allocator_DeallocFn)(void* allocator_data, Slice(byte) slice);
typedef Slice(byte) (*Allocator_ReallocFn)(void* allocator_data, Slice(byte) slice, usize size, bool zeroed);
typedef void  (*Allocator_DeallocAllFn)(void* allocator_data);

typedef struct {
	Allocator_AllocFn alloc;
	Allocator_DeallocFn dealloc;
	Allocator_ReallocFn realloc;
	Allocator_DeallocAllFn dealloc_all;
} vtable_of(Allocator);

typedef struct {
	const vtable_of(Allocator)* vtable;
	void* allocator_data;
} Allocator;

static inline Slice(byte) allocator_alloc(Allocator allocator, usize size) {
	return allocator.vtable->alloc(allocator.allocator_data, size, true);
}

static inline void* allocator_alloc_single(Allocator allocator, usize size) {
	return allocator_alloc(allocator, size).data;
}

static inline void allocator_dealloc(Allocator allocator, Slice(byte) slice) {
	allocator.vtable->dealloc(allocator.allocator_data, slice);
}

static inline void allocator_dealloc_single(Allocator allocator, void* ptr) {
	allocator_dealloc(allocator, slice_make(byte)(ptr, 1));
}

static inline Slice(byte) allocator_realloc(Allocator allocator, Slice(byte) slice, usize size) {
	return allocator.vtable->realloc(allocator.allocator_data, slice, size, true);
}

static inline void allocator_dealloc_all(Allocator allocator) {
	allocator.vtable->dealloc_all(allocator.allocator_data);
}

