#pragma once

#include <memory.h>
#include <std/macro/macros.h>
#include <std/runtime/allocator.h>
#include <std/runtime/slice.h>

#define slice_clone(T) STD_CAT(slice_, T, _clone)
#define slice_make(T) STD_CAT(slice_, T, _make)
#define slice_delete(T) STD_CAT(slice_, T, _delete)

#define STD_DECLARE_SLICE_UTILS_OF(T) \
static inline Slice(T) slice_make(T)(usize length, Allocator allocator) { \
	Slice(byte) allocation = allocator_alloc(allocator, length * sizeof(T)); \
	return slice_from_bytes_slice(T)(allocation); \
} \
static inline Slice(T) slice_clone(T)(Slice(T) slice, Allocator allocator) { \
	Slice(byte) new_slice = allocator_alloc(allocator, slice.length * sizeof(T)); \
	memcpy(new_slice.data, slice.data, slice.length * sizeof(T)); \
	return slice_from_bytes_slice(T)(new_slice); \
} \
static inline void slice_delete(T)(Slice(T) slice, Allocator allocator) { \
	allocator_dealloc(allocator, slice_as_bytes_slice(T)(slice)); \
}

STD_DECLARE_SLICE_UTILS_OF(byte)
STD_DECLARE_SLICE_UTILS_OF(i8)
STD_DECLARE_SLICE_UTILS_OF(i16)
STD_DECLARE_SLICE_UTILS_OF(i32)
STD_DECLARE_SLICE_UTILS_OF(i64)
STD_DECLARE_SLICE_UTILS_OF(u8)
STD_DECLARE_SLICE_UTILS_OF(u16)
STD_DECLARE_SLICE_UTILS_OF(u32)
STD_DECLARE_SLICE_UTILS_OF(u64)
STD_DECLARE_SLICE_UTILS_OF(f32)
STD_DECLARE_SLICE_UTILS_OF(f64)
STD_DECLARE_SLICE_UTILS_OF(isize)
STD_DECLARE_SLICE_UTILS_OF(usize)
STD_DECLARE_SLICE_UTILS_OF(rune)
STD_DECLARE_SLICE_UTILS_OF(rawstring)

