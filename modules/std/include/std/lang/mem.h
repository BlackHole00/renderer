#pragma once

#include <std/macro/macros.h>
#include <std/runtime/context.h>
#include <std/runtime/allocator.h>

#define new(...) (STD_GET_ALL_BUT_LAST_VA_ARGS_WITH_COMMAS(__VA_ARGS__)*)_Generic(STD_GET_LAST_VA_ARGS(__VA_ARGS__), \
	Allocator: allocator_alloc_single \
)(STD_GET_LAST_VA_ARGS(__VA_ARGS__), sizeof(STD_GET_ALL_BUT_LAST_VA_ARGS_WITH_COMMAS(__VA_ARGS__)))
#define delete(...) _Generic(STD_GET_LAST_VA_ARGS(__VA_ARGS__), \
	Allocator: allocator_dealloc_single \
)(STD_GET_LAST_VA_ARGS(__VA_ARGS__), STD_GET_ALL_BUT_LAST_VA_ARGS_WITH_COMMAS(__VA_ARGS__))

