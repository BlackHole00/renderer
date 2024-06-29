#pragma once

#include <std/macro/macros.h>
#include <std/lang/types.h>

#define Slice(T) STD_CAT(Slice_, T)
#define slice_make(T) STD_CAT(slice_, T, _make)
#define slice_from_bytes_slice(T) STD_CAT(slice_, T, _from_bytes_slice)
#define slice_get(T) STD_CAT(slice_, T, _get)
#define slice_is_index_valid(T) STD_CAT(slice_, T, _is_index_valid)
#define slice_as_bytes_slice(T) STD_CAT(slice_, T, _as_bytes_slice)

#define STD_DECLARE_SLICE_OF(T)                                         	   \
typedef struct {                                                        	   \
	T* data;                                                            	   \
	usize length;                                                       	   \
} Slice(T);                                                             	   \
                                                                        	   \
static inline Slice(T) slice_make(T)(T* data, usize length) {           	   \
	return (Slice(T)){                                                  	   \
		.data = data,                                                   	   \
		.length = length                                                	   \
	};                                                                  	   \
}                                                                       	   \
static inline Slice(T) slice_from_bytes_slice(T)(Slice(byte) slice) { \
	return (Slice(T)){ \
		.data = (T*)(slice.data), \
		.length = slice.length / sizeof(T) \
	}; \
} \
static inline bool slice_is_index_valid(T)(Slice(T) slice, usize idx) { 	   \
	return idx < slice.length;                                          	   \
}                                                                       	   \
static inline T* slice_get(T)(Slice(T) slice, usize idx) {              	   \
	if (slice_is_index_valid(T)(slice, idx)) {                          	   \
		return &slice.data[idx];                                        	   \
	}                                                                   	   \
	return nullptr;                                                     	   \
} \
static inline Slice(byte) slice_as_bytes_slice(T)(Slice(T) slice) { \
	return (Slice(byte)){ \
		.data = (byte*)(slice.data), \
		.length = slice.length * sizeof(T) \
	}; \
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

