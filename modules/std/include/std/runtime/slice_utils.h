/**
 * @module STD
 * @file modules/std/include/std/runtime/slice_utils.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <memory.h>
#include <std/macro/macros.h>
#include <std/lang/types.h>
#include <std/lang/comparators.h>
#include <std/lang/cloners.h>
#include <std/runtime/allocator.h>
#include <std/runtime/slice.h>
#include <std/runtime/optional.h>

#define slice_clone(T) STD_CAT(slice$, T, _clone)
#define slice_deep_clone(T) STD_CAT(slice$, T, _deep_clone)
#define slice_make(T) STD_CAT(slice$, T, _make)
#define slice_make_from_data(T) STD_CAT(slice$, T, _make_from_data)
#define slice_delete(T) STD_CAT(slice$, T, _delete)

#define slice_contains_element(T) STD_CAT(slice$, T, _contains_element)
#define slice_index_of_element(T) STD_CAT(slice$, T, _index_of_element)
#define slice_find_element(T) STD_CAT(slice$, T, _find_element)

#define slice_sort_elements(T) STD_CAT(slice$, T, _sort_elements)

#define _slice_heapify_elements(T) STD_CAT(_slice$, T, _heapify_elements)

#define STD_DECLARE_SLICE_MEM_UTILS_OF(T) \
static inline Slice(T) slice_make(T)(usize length, Allocator allocator) { \
	Slice(byte) allocation = allocator_alloc(allocator, length * sizeof(T)); \
	return slice_from_bytes_slice(T)(allocation); \
} \
static inline Slice(T) slice_make_from_data(T)(T* data, usize length, Allocator allocator) { \
	Slice(T) slice = slice_make(T)(length, allocator); \
	memcpy(slice.data, data, length * sizeof(T)); \
	return slice; \
} \
static inline Slice(T) slice_clone(T)(Slice(T) slice, Allocator allocator) { \
	Slice(byte) new_slice = allocator_alloc(allocator, slice.length * sizeof(T)); \
	memcpy(new_slice.data, slice.data, slice.length * sizeof(T)); \
	return slice_from_bytes_slice(T)(new_slice); \
} \
static inline void slice_delete(T)(Slice(T) slice, Allocator allocator) { \
	if (!slice_is_null(T)) { \
		allocator_dealloc(allocator, slice_as_bytes_slice(T)(slice)); \
	} \
} \
static inline void cloner_of(Slice(T))(const Slice(T)* source, Slice(T)* destination, Allocator allocator) { \
	if (source == nullptr || destination == nullptr) { \
		return; \
	} \
	*destination = slice_clone(T)(*source, allocator); \
}

#define STD_DECLARE_SLICE_COMMON_UTILS_OF(T, T_equality_comparator) \
static_typecheck(STD_EQUALITY_COMPARATOR_SIGNATURE(T), T_equality_comparator); \
static inline bool slice_contains_element(T)(Slice(T) slice, T* value) { \
	for (usize i = 0; i < slice.length; i++) { \
		if (T_equality_comparator(value, &slice.data[i])) { \
			return true; \
		} \
	} \
	return false; \
} \
static inline Optional(usize) slice_index_of_element(T)(Slice(T) slice, T* value) { \
	for (usize i = 0; i < slice.length; i++) { \
		if (T_equality_comparator(value, &slice.data[i])) { \
			return optional_from(usize)(i); \
		} \
	} \
	return optional_none(usize)(); \
} \
static inline T* slice_find_element(T)(Slice(T) slice, T* value) { \
	for (usize i = 0; i < slice.length; i++) { \
		if (T_equality_comparator(value, &slice.data[i])) { \
			return &slice.data[i]; \
		} \
	} \
	return nullptr; \
}

#define STD_DECLARE_SLICE_SORTING_UTILS_OF(T, T_scalar_comparator) \
static_typecheck(STD_SCALAR_COMPARATOR_SIGNATURE(T), T_scalar_comparator); \
static inline void _slice_heapify_elements(T)(Slice(T) slice, usize start, usize end) { \
	usize root = start; \
	while ((2 * root + 1) < end) { \
		usize left_child = 2 * root + 1; \
		usize right_child = left_child + 1; \
		usize swap_idx = root; \
		if (T_scalar_comparator(&slice.data[swap_idx], &slice.data[left_child]) > 0) { \
			swap_idx = left_child; \
		} \
		if (right_child < end && T_scalar_comparator(&slice.data[swap_idx], &slice.data[right_child]) > 0) { \
			swap_idx = right_child; \
		} \
		if (swap_idx == root) { \
			return; \
		} \
		swap(&slice.data[root], &slice.data[swap_idx]); \
		root = swap_idx; \
	} \
} \
static inline void slice_sort_elements(T)(Slice(T) slice) { \
	usize start = slice.length / 2; \
	usize end = slice.length; \
	while (start > 0) { \
		start--; \
		_slice_heapify_elements(T)(slice, start, end); \
	} \
	while (end > 1) { \
		end--; \
		swap(&slice.data[end], &slice.data[0]); \
		_slice_heapify_elements(T)(slice, 0, end); \
	} \
}

#define STD_DECLARE_SLICE_DEEP_CLONE_OF(T, T_deep_cloner) \
static_typecheck(STD_DEEP_CLONE_SIGNATURE(T), T_deep_cloner); \
static inline Slice(T) slice_deep_clone(T)(Slice(T) source, Allocator allocator) { \
	Slice(T) result = slice_make(T)(source.length, allocator); \
	for (usize i = 0; i < source.length; i++) { \
		T_deep_cloner(&souce.data[i], &result.data[i], allocator); \
	} \
	return result; \
} \
static inline void deep_cloner_of(Slice(T))(const Slice(T)* source, Slice(T)* destination, Allocator allocator) { \
	if (source == nullptr || destination == nullptr) { \
		return; \
	} \
	*destination = slice_deep_clone(T)(*source, allocator); \
}

STD_DECLARE_SLICE_MEM_UTILS_OF(byte)
STD_DECLARE_SLICE_MEM_UTILS_OF(char)
STD_DECLARE_SLICE_MEM_UTILS_OF(i8)
STD_DECLARE_SLICE_MEM_UTILS_OF(i16)
STD_DECLARE_SLICE_MEM_UTILS_OF(i32)
STD_DECLARE_SLICE_MEM_UTILS_OF(i64)
STD_DECLARE_SLICE_MEM_UTILS_OF(u8)
STD_DECLARE_SLICE_MEM_UTILS_OF(u16)
STD_DECLARE_SLICE_MEM_UTILS_OF(u32)
STD_DECLARE_SLICE_MEM_UTILS_OF(u64)
STD_DECLARE_SLICE_MEM_UTILS_OF(f32)
STD_DECLARE_SLICE_MEM_UTILS_OF(f64)
STD_DECLARE_SLICE_MEM_UTILS_OF(isize)
STD_DECLARE_SLICE_MEM_UTILS_OF(usize)
STD_DECLARE_SLICE_MEM_UTILS_OF(rune)
STD_DECLARE_SLICE_MEM_UTILS_OF(rawstring)

STD_DECLARE_SLICE_COMMON_UTILS_OF(byte,      equality_comparator_of(byte))
STD_DECLARE_SLICE_COMMON_UTILS_OF(char,      equality_comparator_of(char))
STD_DECLARE_SLICE_COMMON_UTILS_OF(i8,        equality_comparator_of(i8))
STD_DECLARE_SLICE_COMMON_UTILS_OF(i16,       equality_comparator_of(i16))
STD_DECLARE_SLICE_COMMON_UTILS_OF(i32,       equality_comparator_of(i32))
STD_DECLARE_SLICE_COMMON_UTILS_OF(i64,       equality_comparator_of(i64))
STD_DECLARE_SLICE_COMMON_UTILS_OF(u8,        equality_comparator_of(u8))
STD_DECLARE_SLICE_COMMON_UTILS_OF(u16,       equality_comparator_of(u16))
STD_DECLARE_SLICE_COMMON_UTILS_OF(u32,       equality_comparator_of(u32))
STD_DECLARE_SLICE_COMMON_UTILS_OF(u64,       equality_comparator_of(u64))
STD_DECLARE_SLICE_COMMON_UTILS_OF(f32,       equality_comparator_of(f32))
STD_DECLARE_SLICE_COMMON_UTILS_OF(f64,       equality_comparator_of(f64))
STD_DECLARE_SLICE_COMMON_UTILS_OF(isize,     equality_comparator_of(isize))
STD_DECLARE_SLICE_COMMON_UTILS_OF(usize,     equality_comparator_of(usize))
STD_DECLARE_SLICE_COMMON_UTILS_OF(rune,      equality_comparator_of(rune))
STD_DECLARE_SLICE_COMMON_UTILS_OF(rawstring, equality_comparator_of(rawstring))

STD_DECLARE_SLICE_SORTING_UTILS_OF(byte,      scalar_comparator_of(byte))
STD_DECLARE_SLICE_SORTING_UTILS_OF(char,      scalar_comparator_of(char))
STD_DECLARE_SLICE_SORTING_UTILS_OF(i8,        scalar_comparator_of(i8))
STD_DECLARE_SLICE_SORTING_UTILS_OF(i16,       scalar_comparator_of(i16))
STD_DECLARE_SLICE_SORTING_UTILS_OF(i32,       scalar_comparator_of(i32))
STD_DECLARE_SLICE_SORTING_UTILS_OF(i64,       scalar_comparator_of(i64))
STD_DECLARE_SLICE_SORTING_UTILS_OF(u8,        scalar_comparator_of(u8))
STD_DECLARE_SLICE_SORTING_UTILS_OF(u16,       scalar_comparator_of(u16))
STD_DECLARE_SLICE_SORTING_UTILS_OF(u32,       scalar_comparator_of(u32))
STD_DECLARE_SLICE_SORTING_UTILS_OF(u64,       scalar_comparator_of(u64))
STD_DECLARE_SLICE_SORTING_UTILS_OF(f32,       scalar_comparator_of(f32))
STD_DECLARE_SLICE_SORTING_UTILS_OF(f64,       scalar_comparator_of(f64))
STD_DECLARE_SLICE_SORTING_UTILS_OF(isize,     scalar_comparator_of(isize))
STD_DECLARE_SLICE_SORTING_UTILS_OF(usize,     scalar_comparator_of(usize))
STD_DECLARE_SLICE_SORTING_UTILS_OF(rune,      scalar_comparator_of(rune))
STD_DECLARE_SLICE_SORTING_UTILS_OF(rawstring, scalar_comparator_of(rawstring))

