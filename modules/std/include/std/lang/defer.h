#pragma once

#include <std/macro/macros.h>

static inline void _std_defer_resolution(void (^*defer_block)(void)) {
	(*defer_block)();
}

#define _STD_DEFER_BLOCK_NAME() STD_CAT(_std_defer_block, __COUNTER__)
#define defer(...) __attribute__((cleanup(_std_defer_resolution))) void (^_STD_DEFER_BLOCK_NAME())(void) = ^{ __VA_ARGS__; }
