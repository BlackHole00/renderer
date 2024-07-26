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

#define Slice(T) STD_CAT(Slice_, T)
#define slice_from(T) STD_CAT(slice_, T, _from)
#define slice_make_null(T) STD_CAT(slice_, T, _make_null)
#define slice_from_bytes_slice(T) STD_CAT(slice_, T, _from_bytes_slice)
#define slice_get(T) STD_CAT(slice_, T, _get)
#define slice_is_index_valid(T) STD_CAT(slice_, T, _is_index_valid)
#define slice_as_bytes_slice(T) STD_CAT(slice_, T, _as_bytes_slice)
#define slice_is_null(T) STD_CAT(slice_, T, _is_null)
#define slice_subslice(T) STD_CAT(slice_, T, _subslice)
#define slice_contains(T) STD_CAT(slice_, T, _contains)
#define slice_index_of(T) STD_CAT(slice_, T, _index_of)
#define slice_find(T) STD_CAT(slice_, T, _find)
// Heap sort
#define slice_sort(T) STD_CAT(slice_, T, _sort)

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
static inline void slice_sort(T)(Slice(T) slice, usize (^equality_predicate)(const T*, const T*)) { \
	usize start = slice.length / 2; \
	usize end = slice.length; \
	while (end > 1) { \
		if (start > 0) { \
			start--;\
		} else { \
			end--; \
			swap(&slice.data[end], &slice.data[0]); \
		} \
		usize root = start; \
		usize left_child = (2 * root) + 1; \
		while (left_child < end) { \
			usize child = left_child; \
			if ((child + 1 < end) &&  \
				(equality_predicate(&slice.data[child], &slice.data[child + 1]) < 0) \
			) { \
				child = child + 1; \
			} \
			if (equality_predicate(&slice.data[root], &slice.data[child]) < 0) { \
				swap(&slice.data[root], &slice.data[child]); \
				root = child; \
			} else { \
				break; \
			} \
		} \
	} \
}

STD_DECLARE_SLICE_OF(byte)
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

