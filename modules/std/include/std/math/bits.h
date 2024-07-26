/**
 * @module STD
 * @file modules/std/include/std/math/bits.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <std/lang/types.h>

static inline u8 next_power_of_2_u8(u8 x) {
	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	return ++x;
}
static inline u16 next_power_of_2_u16(u16 x) {
	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	return ++x;
}
static inline u32 next_power_of_2_u32(u32 x) {
	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return ++x;
}
static inline u64 next_power_of_2_u64(u64 x) {
	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x |= x >> 16;
	x |= x >> 32;
	return ++x;
}

// TODO(Vicix): Support 32 bits
#define next_power_of_2(...) (_Generic(__VA_ARGS__,\
	u8: next_power_of_2_u8, \
	u16: next_power_of_2_u16, \
	u32: next_power_of_2_u32, \
	usize: next_power_of_2_u64, \
	u64: next_power_of_2_u64 \
)(__VA_ARGS__))
