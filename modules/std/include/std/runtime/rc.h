#pragma once

#include <std/macro/macros.h>
#include <std/lang/types.h>
#include <std/lang/mem.h>
#include <std/lang/cloners.h>
#include <std/runtime/allocator.h>

// NOTE(Vicix): Not thread safe
// NOTE(Vicix): cloner_of(Rc(T)) is the same as calling rc_clone. The allocator
//              is thus unused and the copy is shallow (the underlying data is
//              the same). deep_cloner_of(Rc(T)) is a deep clone, thus allocates
//              more memory. It is the same as rc_from.
// TODO(Vicix): Implement also Arc
#define Rc(T) STD_CAT(Rc_, T)

#define rc_new(T) STD_CAT(rc_, T, _new)
#define rc_from(T) STD_CAT(rc_, T, _from)
#define rc_delete(T) STD_CAT(rc_, T, _delete)
#define rc_clone(T) STD_CAT(rc_, T, _clone)
#define rc_increment_reference_count(T) STD_CAT(rc_, T, _increment_reference_count)
#define rc_decrement_reference_count(T) STD_CAT(rc_, T, _decrement_reference_count)

#define _Rc_Container(T) STD_CAT(_Rc_Container_, T)
#define _rc_as_container(T) STD_CAT(_rc_, T, _as_container)
#define _rc_from_container(T) STD_CAT(_rc_, T, _from_container)

#define STD_DECLARE_RC_OF(T) \
typedef struct { \
	 T data; \
	 usize reference_count; \
	 Allocator allocator; \
} _Rc_Container(T); \
typedef T* Rc(T); \
static_assert(offsetof(_Rc_Container(T), data) == 0); \
static inline _Rc_Container(T)* _rc_as_container(T)(Rc(T) rc) { \
	return (_Rc_Container(T)*)(rc); \
} \
static inline Rc(T) _rc_from_container(T)(_Rc_Container(T)* container) { \
	return (Rc(T))(container); \
} \
static inline Rc(T) rc_new(T)(Allocator allocator) { \
	_Rc_Container(T)* container = new(_Rc_Container(T), allocator); \
	container->allocator = allocator; \
	return _rc_from_container(T)(container); \
} \
static inline Rc(T) rc_from(T)(T* value, Allocator allocator) { \
	Rc(T) rc = rc_new(T)(allocator); \
	*rc = *value; \
	return rc; \
} \
static inline usize rc_decrement_reference_count(T)(Rc(T) rc) { \
	_Rc_Container(T)* container = _rc_as_container(T)(rc); \
	usize old_reference_count = container->reference_count; \
	container->reference_count--; \
	return old_reference_count; \
} \
static inline usize rc_increment_reference_count(T)(Rc(T) rc) { \
	_Rc_Container(T)* container = _rc_as_container(T)(rc); \
	usize old_reference_count = container->reference_count; \
	container->reference_count++; \
	return old_reference_count; \
} \
static inline void rc_delete(T)(Rc(T) rc) { \
	_Rc_Container(T)* container = _rc_as_container(T)(rc); \
	container->reference_count--; \
	if (container->reference_count == 0) { \
		delete(container, container->allocator); \
	} \
} \
static inline Rc(T) rc_clone(T)(Rc(T) rc) { \
	_Rc_Container(T)* container = _rc_as_container(T)(rc); \
	container->reference_count++; \
	return rc; \
} \
static inline void cloner_of(Rc(T))(const Rc(T)* source, Rc(T)* destination, Allocator) { \
	static_typecheck(STD_SHALLOW_CLONE_SIGNATURE(rawstring), shallow_cloner_of(rawstring)); \
	*destination = rc_clone(T)(*source); \
} \

#define STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(T, T_deep_cloner) \
static inline void deep_cloner_of(Rc(T))(const Rc(T)* source, Rc(T)* destination, Allocator allocator) { \
	static_typecheck(STD_DEEP_CLONE_SIGNATURE(rawstring), shallow_cloner_of(rawstring)); \
	T temp; \
	T_deep_cloner(*source, &temp, allocator); \
	*destination = rc_from(T)(&temp, allocator); \
}

STD_DECLARE_RC_OF(byte)
STD_DECLARE_RC_OF(i8)
STD_DECLARE_RC_OF(i16)
STD_DECLARE_RC_OF(i32)
STD_DECLARE_RC_OF(i64)
STD_DECLARE_RC_OF(u8)
STD_DECLARE_RC_OF(u16)
STD_DECLARE_RC_OF(u32)
STD_DECLARE_RC_OF(u64)
STD_DECLARE_RC_OF(f32)
STD_DECLARE_RC_OF(f64)
STD_DECLARE_RC_OF(isize)
STD_DECLARE_RC_OF(usize)
STD_DECLARE_RC_OF(rune)
STD_DECLARE_RC_OF(rawstring)

STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(byte, deep_cloner_of(byte))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(i8, deep_cloner_of(i8))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(i16, deep_cloner_of(i16))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(i32, deep_cloner_of(i32))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(i64, deep_cloner_of(i64))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(u8, deep_cloner_of(u8))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(u16, deep_cloner_of(u16))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(u32, deep_cloner_of(u32))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(u64, deep_cloner_of(u64))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(f32, deep_cloner_of(f32))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(f64, deep_cloner_of(f64))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(isize, deep_cloner_of(isize))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(usize, deep_cloner_of(usize))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(rune, deep_cloner_of(rune))
STD_DECLARE_RC_DEEP_CLONE_UTILS_OF(rawstring, deep_cloner_of(rawstring))

