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
