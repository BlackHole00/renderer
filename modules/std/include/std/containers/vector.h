#pragma once

#include <std/macro/macros.h>
#include <std/lang/container.h>
#include <std/runtime/slice.h>
#include <std/runtime/allocator.h>

static const usize STD_DEFAULT_VECTOR_CAPACITY = 8;

#define Vector(T) STD_CAT(Vector_, T)
#define vector_make(T) STD_CAT(vector_, T, _make)
#define vector_make_with_capacity(T) STD_CAT(vector_, T, _make_with_capacity)
#define vector_destroy(T) STD_CAT(vector_, T, _destroy)

#define _vector_from_allocation(T) STD_CAT(_vector_, T, _from_allocation)
#define _vector_get_allocation_slice(T) STD_CAT(_vector_, T, _get_allocation_slice)

#define STD_DECLARE_VECTOR_OF(T) typedef T* Vector(T);                                                     			   \
                                                                                                           			   \
typedef struct {                                                                                           			   \
	Allocator allocator;                                                                                   			   \
	usize length;                                                                                          			   \
	usize capacity;                                                                                        			   \
} container_of(Vector(T));                                                                                 			   \
                                                                                                           			   \
static inline Vector(T) _vector_from_allocation(T)(Slice(byte) allocation, Allocator allocator) {\
	auto container = (container_of(Vector(T))*)(allocation.data); 			   \
 	container->allocator = allocator;                                                                      			   \
	container->length = 0;                                                                                 			   \
	container->capacity = allocation.length / sizeof(T);\
 	return as_contained(Vector(T), container);                                                             			   \
} \
static inline Vector(T) vector_make_with_capacity(T)(usize initial_capacity, Allocator allocator) {        			   \
	usize size = sizeof(container_of(Vector(T))) + initial_capacity * sizeof(T);                       			   \
	Slice(byte) allocation = allocator_alloc(allocator, size); \
	return _vector_from_allocation(T)(allocation, allocator); \
}                                                                                                          			   \
static inline Vector(T) vector_make(T)(Allocator allocator) {                                              			   \
	return vector_make_with_capacity(T)(STD_DEFAULT_VECTOR_CAPACITY, allocator);                           			   \
}                                                                                                          			   \
static inline void vector_destroy(T)(Vector(T) vector) {                                                   			   \
	container_of(Vector(T))* container = as_container(Vector(T), vector);                                  			   \
	allocator_dealloc_single(container->allocator, container);                                                			   	   \
}

STD_DECLARE_VECTOR_OF(int)
