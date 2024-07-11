#pragma once

#include <std/lang/types.h>
#include <std/runtime/slice.h>
#include <std/runtime/logger.h>
#include <std/runtime/allocator.h>

typedef struct {
	Allocator allocator;
	Allocator temp_allocator;
	Logger logger;
} Context;

static inline Slice(byte) context_alloc(Context* context, usize size) {
	Allocator allocator = context->allocator;
	return allocator.vtable->alloc(allocator.allocator_data, size, true);
}

static inline void* context_alloc_single(Context* context, usize size) {
	Allocator allocator = context->allocator;
	return allocator_alloc_single(allocator, size);
}

static inline void context_dealloc(Context* context, Slice(byte) slice) {
	Allocator allocator = context->allocator;
	allocator.vtable->dealloc(allocator.allocator_data, slice);
}

static inline void context_dealloc_single(Context* context, void* ptr) {
	Allocator allocator = context->allocator;
	allocator_dealloc_single(allocator, ptr);
}

static inline Slice(byte) context_realloc(Context* context, Slice(byte) slice, usize size) {
	Allocator allocator = context->allocator;
	return allocator.vtable->realloc(allocator.allocator_data, slice, size, true);
}

static inline void context_dealloc_all(Context* context) {
	Allocator allocator = context->allocator;
	allocator.vtable->dealloc_all(allocator.allocator_data);
}


