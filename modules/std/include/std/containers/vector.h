#pragma once

#include <std/macro/macros.h>
#include <std/lang/cloners.h>
#include <std/runtime/slice.h>
#include <std/runtime/optional.h>
#include <std/runtime/allocator.h>
#include <std/math/bits.h>

static const usize STD_DEFAULT_VECTOR_CAPACITY = 8;

#define Vector(T) STD_CAT(Vector_, T)
#define vector_make(T) STD_CAT(vector_, T, _make)
#define vector_make_with_capacity(T) STD_CAT(vector_, T, _make_with_capacity)
#define vector_clone(T) STD_CAT(vector_, T, _clone)
#define vector_destroy(T) STD_CAT(vector_, T, _destroy)
#define vector_reserve(T) STD_CAT(vector_, T, _reserve)
#define vector_resize(T) STD_CAT(vector_, T, _resize)
#define vector_is_index_valid(T) STD_CAT(vector_, T, _is_index_valid)
#define vector_get(T) STD_CAT(vector_, T, _get)
#define vector_set(T) STD_CAT(vector_, T, _set)
#define vector_append(T) STD_CAT(vector_, T, _append)
#define vector_remove(T) STD_CAT(vector_, T, _remove)
#define vector_insert(T) STD_CAT(vector_, T, _insert)
#define vector_as_slice(T) STD_CAT(vector_, T, _as_slice)

#define _vector_from_allocation(T) STD_CAT(_vector_, T, _from_allocation)

#define STD_DECLARE_VECTOR_OF(T) \
typedef struct { \
	Allocator allocator; \
	usize length; \
	union { \
		Slice(T) allocation; \
		struct { \
			T* data; \
			usize capacity; \
		}; \
	}; \
} Vector(T); \
static inline Vector(T) _vector_from_allocation(T)(Slice(byte) allocation, Allocator allocator) { \
	return (Vector(T)){ \
		.allocator = allocator, \
		.length = 0, \
		.allocation = slice_from_bytes_slice(T)(allocation), \
	}; \
} \
static inline Vector(T) vector_make_with_capacity(T)(usize capacity, Allocator allocator) { \
	Slice(byte) allocation = allocator_alloc(allocator, capacity * sizeof(T)); \
	assert(capacity == 0 || !slice_is_null(byte)(allocation)); \
	return _vector_from_allocation(T)(allocation, allocator); \
} \
static inline Vector(T) vector_make(T)(Allocator allocator) { \
	return vector_make_with_capacity(T)(STD_DEFAULT_VECTOR_CAPACITY, allocator); \
} \
static inline Vector(T) vector_clone(T)(const Vector(T)* vector, Allocator allocator) { \
	Vector(T) result = vector_make_with_capacity(T)(vector->length, allocator); \
	memcpy(&result.data[0], &vector->data[0], sizeof(T) * vector->length); \
	return result; \
} \
static inline void vector_destroy(T)(Vector(T)* vector) { \
	Slice(byte) allocation = slice_as_bytes_slice(T)(vector->allocation); \
	allocator_dealloc(vector->allocator, allocation); \
	vector->length = 0; \
	vector->allocation = slice_make_null(T)(); \
} \
static inline void vector_reserve(T)(Vector(T)* vector, usize capacity) { \
	usize allocation_capacity = next_power_of_2(capacity) * sizeof(T); \
	Slice(byte) previous_allocation = slice_as_bytes_slice(T)(vector->allocation); \
	Slice(byte) allocation = allocator_realloc(vector->allocator, previous_allocation, allocation_capacity); \
	assert(capacity == 0 || !slice_is_null(byte)(allocation)); \
	vector->allocation = slice_from_bytes_slice(T)(allocation); \
} \
static inline void vector_resize(T)(Vector(T)* vector, usize length) { \
	if (vector->capacity < length) { \
		vector_reserve(T)(vector, length); \
	} \
	vector->length = length; \
} \
static inline bool vector_is_index_valid(T)(const Vector(T)* vector, usize index) { \
	return vector->length < index; \
} \
static inline T* vector_get(T)(const Vector(T)* vector, usize index) { \
	if (vector->length < index) { \
		return &vector->data[index]; \
	} \
	return nullptr; \
} \
static inline void vector_set(T)(const Vector(T)* vector, usize index, T value) { \
	assert(vector_is_index_valid(T)(vector, index)); \
	vector->data[index] = value; \
} \
static inline void vector_append(T)(Vector(T)* vector, T value) { \
	vector_resize(T)(vector, vector->length + 1); \
	vector->data[vector->length - 1] = value; \
} \
static inline Optional(T) vector_remove(T)(Vector(T)* vector, usize index) { \
	if (index >= vector->length) { \
		return optional_none(T)(); \
	} \
	T value = vector->data[index]; \
	for (usize i = vector->length - 2; i >= index; i++) { \
		vector->data[i + 1] = vector->data[i]; \
	} \
	vector->length -= 1; \
	return optional_from(T)(value); \
} \
static inline void vector_insert(T)(Vector(T)* vector, usize index, T value) { \
	assert(index <= vector->length); \
	for (usize i = index; i < vector->length; i++) { \
		vector->data[i] = vector->data[i + 1]; \
	} \
	vector_append(T)(vector, value); \
} \
static inline Slice(T) vector_as_slice(T)(const Vector(T)* vector) { \
	return slice_from(T)(vector->allocation.data, vector->length); \
} \
static inline void cloner_of(Vector(T))(const Vector(T)* source, Vector(T)* destination, Allocator allocator) { \
	if (source == nullptr || destination == nullptr) { \
		return; \
	} \
	*destination = vector_clone(T)(source, allocator); \
}

STD_DECLARE_VECTOR_OF(byte)
STD_DECLARE_VECTOR_OF(i8)
STD_DECLARE_VECTOR_OF(i16)
STD_DECLARE_VECTOR_OF(i32)
STD_DECLARE_VECTOR_OF(i64)
STD_DECLARE_VECTOR_OF(u8)
STD_DECLARE_VECTOR_OF(u16)
STD_DECLARE_VECTOR_OF(u32)
STD_DECLARE_VECTOR_OF(u64)
STD_DECLARE_VECTOR_OF(f32)
STD_DECLARE_VECTOR_OF(f64)
STD_DECLARE_VECTOR_OF(isize)
STD_DECLARE_VECTOR_OF(usize)
STD_DECLARE_VECTOR_OF(rune)
STD_DECLARE_VECTOR_OF(rawstring)
