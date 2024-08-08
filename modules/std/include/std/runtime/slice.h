/**
 * @module STD
 * @file modules/std/include/std/runtime/slice.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <assert.h>
#include <std/macro/macros.h>
#include <std/lang/types.h>
#include <std/runtime/optional.h>

#define Slice(T) STD_CAT(Slice$, T)
#define slice_from(T) STD_CAT(slice$, T, _from)
#define slice_make_null(T) STD_CAT(slice$, T, _make_null)
#define slice_from_bytes_slice(T) STD_CAT(slice$, T, _from_bytes_slice)
#define slice_get(T) STD_CAT(slice$, T, _get)
#define slice_is_index_valid(T) STD_CAT(slice$, T, _is_index_valid)
#define slice_as_bytes_slice(T) STD_CAT(slice$, T, _as_bytes_slice)
#define slice_is_null(T) STD_CAT(slice$, T, _is_null)
#define slice_subslice(T) STD_CAT(slice$, T, _subslice)
#define slice_contains(T) STD_CAT(slice$, T, _contains)
#define slice_index_of(T) STD_CAT(slice$, T, _index_of)
#define slice_find(T) STD_CAT(slice$, T, _find)
// Heap sort
#define slice_sort(T) STD_CAT(slice$, T, _sort)
#define _slice_heapify(T) STD_CAT(_slice, T, _heapify)

#define STD_DECLARE_SLICE_OF(T)                                         	   \
typedef struct {                                                        	   \
	T* data;                                                            	   \
	usize length;                                                       	   \
} Slice(T);                                                             	   \
                                                                        	   \
static inline Slice(T) slice_from(T)(T* data, usize length) {           	   \
	return (Slice(T)){                                                  	   \
		.data = data,                                                   	   \
		.length = length                                                	   \
	};                                                                  	   \
}                                                                       	   \
static inline Slice(T) slice_make_null(T)() { \
	return (Slice(T)){                                                  	   \
		.data = nullptr,                                                   	   \
		.length = 0                                     					   \
	};                                                                  	   \
} \
static inline Slice(T) slice_from_bytes_slice(T)(Slice(byte) slice) { \
	return (Slice(T)){ \
		.data = (T*)(slice.data), \
		.length = slice.length / sizeof(T) \
	}; \
} \
static inline bool slice_is_null(T)(Slice(T) slice) { \
	return slice.data == nullptr; \
} \
static inline bool slice_is_index_valid(T)(Slice(T) slice, usize idx) { 	   \
	return idx < slice.length;                                          	   \
}                                                                       	   \
static inline T* slice_get(T)(Slice(T) slice, usize idx) {              	   \
	if (!slice_is_null(T)(slice) && slice_is_index_valid(T)(slice, idx)) {	   \
		return &slice.data[idx];                                        	   \
	}                                                                   	   \
	return nullptr;                                                     	   \
} \
static inline Slice(byte) slice_as_bytes_slice(T)(Slice(T) slice) { \
	return (Slice(byte)){ \
		.data = (byte*)(slice.data), \
		.length = slice.length * sizeof(T) \
	}; \
} \
static inline Slice(T) slice_subslice(T)(Slice(T) slice, usize start, usize end) { \
	assert(start < slice.length); \
	assert(end < slice.length + 1); \
	assert(start <= end); \
 	return (Slice(T)){ \
		.data = &slice.data[start], \
		.length = end - start \
	}; \
} \
static inline bool slice_contains(T)(Slice(T) slice, bool (^search_predicate)(const T*)) { \
	for (usize i = 0; i < slice.length; i++) { \
		if (search_predicate(&slice.data[i])) { \
			return true; \
		} \
	} \
	return false; \
} \
static inline Optional(usize) slice_index_of(T)(Slice(T) slice, bool (^search_predicate)(const T*)) { \
	for (usize i = 0; i < slice.length; i++) { \
		if (search_predicate(&slice.data[i])) { \
			return optional_from(usize)(i); \
		} \
	} \
	return optional_none(usize)(); \
} \
static inline T* slice_find(T)(Slice(T) slice, bool (^search_predicate)(const T*)) { \
	for (usize i = 0; i < slice.length; i++) { \
		if (search_predicate(&slice.data[i])) { \
			return &slice.data[i]; \
		} \
	} \
	return nullptr; \
} \
static inline void _slice_heapify(T)(Slice(T) slice, usize start, usize end, isize (^equality_predicate)(const T*, const T*)) { \
	usize root = start; \
	while ((2 * root + 1) < end) { \
		usize left_child = 2 * root + 1; \
		usize right_child = left_child + 1; \
		usize swap_idx = root; \
		if (equality_predicate(&slice.data[swap_idx], &slice.data[left_child]) > 0) { \
			swap_idx = left_child; \
		} \
		if (right_child < end && equality_predicate(&slice.data[swap_idx], &slice.data[right_child]) > 0) { \
			swap_idx = right_child; \
		} \
		if (swap_idx == root) { \
			return; \
		} \
		swap(&slice.data[root], &slice.data[swap_idx]); \
		root = swap_idx; \
	} \
} \
static inline void slice_sort(T)(Slice(T) slice, isize (^equality_predicate)(const T*, const T*)) { \
	usize start = slice.length / 2; \
	usize end = slice.length; \
	while (start > 0) { \
		start--; \
		_slice_heapify(T)(slice, start, end, equality_predicate); \
	} \
	while (end > 1) { \
		end--; \
		swap(&slice.data[end], &slice.data[0]); \
		_slice_heapify(T)(slice, 0, end, equality_predicate); \
	} \
}

STD_DECLARE_SLICE_OF(byte)
STD_DECLARE_SLICE_OF(char)
STD_DECLARE_SLICE_OF(i8)
STD_DECLARE_SLICE_OF(i16)
STD_DECLARE_SLICE_OF(i32)
STD_DECLARE_SLICE_OF(i64)
STD_DECLARE_SLICE_OF(u8)
STD_DECLARE_SLICE_OF(u16)
STD_DECLARE_SLICE_OF(u32)
STD_DECLARE_SLICE_OF(u64)
STD_DECLARE_SLICE_OF(f32)
STD_DECLARE_SLICE_OF(f64)
STD_DECLARE_SLICE_OF(isize)
STD_DECLARE_SLICE_OF(usize)
STD_DECLARE_SLICE_OF(rune)
STD_DECLARE_SLICE_OF(rawstring)

