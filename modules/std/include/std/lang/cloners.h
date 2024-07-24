/**
 * @module STD
 * @file modules/std/include/lang/std/cloners.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <strings.h>
#include <memory.h>
#include <std/macro/macros.h>
#include <std/runtime/allocator.h>

#define STD_SHALLOW_CLONE_SIGNATURE(T) void (*)(const T*, T*, Allocator)
#define STD_DEEP_CLONE_SIGNATURE(T) void (*)(const T*, T*, Allocator)

#define shallow_cloner_of(T) STD_CAT(T, _shallow_cloner)
#define cloner_of(T) shallow_cloner_of(T)
#define clone(T) shallow_cloner_of(T)

#define deep_cloner_of(T) STD_CAT(T, _deep_cloner)
#define deep_clone(T) deep_cloner_of(T)

#define STD_DECLARE_STANDARD_SHALLOW_CLONER_OF(T) \
static inline void shallow_cloner_of(T)(const T* source, T* destination, Allocator) { \
	*destination = *source; \
} \

#define STD_DECLARE_STANDANRD_DEEP_CLONER_OF(T) \
static inline void deep_cloner_of(T)(const T* source, T* destination, Allocator) { \
	*destination = *source; \
} \

#define STD_DECLARE_STANDARD_CLONERS_OF(T) \
	STD_DECLARE_STANDARD_SHALLOW_CLONER_OF(T) \
	STD_DECLARE_STANDANRD_DEEP_CLONER_OF(T)


STD_DECLARE_STANDARD_CLONERS_OF(i8)
STD_DECLARE_STANDARD_CLONERS_OF(u8)
STD_DECLARE_STANDARD_CLONERS_OF(i16)
STD_DECLARE_STANDARD_CLONERS_OF(u16)
STD_DECLARE_STANDARD_CLONERS_OF(i32)
STD_DECLARE_STANDARD_CLONERS_OF(u32)
STD_DECLARE_STANDARD_CLONERS_OF(i64)
STD_DECLARE_STANDARD_CLONERS_OF(u64)
STD_DECLARE_STANDARD_CLONERS_OF(f64)
STD_DECLARE_STANDARD_CLONERS_OF(f32)
STD_DECLARE_STANDARD_CLONERS_OF(isize)
STD_DECLARE_STANDARD_CLONERS_OF(usize)
STD_DECLARE_STANDARD_CLONERS_OF(byte)
STD_DECLARE_STANDARD_CLONERS_OF(rune)

static inline void shallow_cloner_of(rawstring)(const rawstring* source, rawstring* destination, Allocator allocator) {
	static_typecheck(STD_SHALLOW_CLONE_SIGNATURE(rawstring), shallow_cloner_of(rawstring));
	if (source == nullptr || destination == nullptr) {
		return;
	}

	usize source_len = strlen(*source);
	*destination = allocator_alloc_single(allocator, source_len + 1);
	memcpy(*destination, *source, source_len + 1);
}

static inline void deep_cloner_of(rawstring)(const rawstring* source, rawstring* destination, Allocator allocator) {
	static_typecheck(STD_DEEP_CLONE_SIGNATURE(rawstring), deep_cloner_of(rawstring));
	shallow_cloner_of(rawstring)(source, destination, allocator);
}

