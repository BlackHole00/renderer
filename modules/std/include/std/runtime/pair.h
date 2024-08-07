#pragma once

#include <std/macro/macros.h>

#define Pair(T, U) STD_CAT(Pair_, T, _, U)
#define pair_make(T, U) STD_CAT(pair_, T, _, U, _make)

#define STD_DECLARE_PAIR(T, U) typedef struct {                                \
	T first;                                                                   \
	U second;                                                                  \
} Pair(T, U);                                                                  \
                                                                               \
static inline Pair(T, U) pair_make(T, U)(T first, U second) {                  \
	return (Pair(T, U)){                                                       \
		.first = first,                                                        \
		.second = second                                                       \
	};                                                                         \
}                                                                              \

