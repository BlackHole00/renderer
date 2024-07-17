#pragma once

#include <std/macro/macros.h>
#include <std/runtime/context.h>
#include <std/runtime/allocator.h>

#define new(...) (STD_VAARGS_GET_EXCEPT_LAST(__VA_ARGS__)*)_Generic(STD_VAARGS_GET_LAST(__VA_ARGS__), \
	Allocator: allocator_alloc_single \
)(STD_VAARGS_GET_LAST(__VA_ARGS__), sizeof(STD_VAARGS_GET_EXCEPT_LAST(__VA_ARGS__)))
#define delete(...) _Generic(STD_VAARGS_GET_LAST(__VA_ARGS__), \
	Allocator: allocator_dealloc_single \
)(STD_VAARGS_GET_LAST(__VA_ARGS__), STD_VAARGS_GET_EXCEPT_LAST(__VA_ARGS__))

