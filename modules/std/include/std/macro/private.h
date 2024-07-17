/**
 * @module STD
 * @file modules/std/include/std/macro/private.h
 * @author Vicix (www.github.com/BlackHole00)
 * @brief Helper functions for the macros located in @see macros.h
 * @private
 */
#pragma once

/** @private Helper of @see STD_VAARGS_COUNT */
#define _STD_VAARGS_COUNT(_31, _30, _29, _28, _27, _26, _25, _24, _23, _22, \
	_21, _20, _19, _18, _17, _16, _15, _14, _13, _12, _11, _10, _9, _8, _7, \
	_6, _5, _4, _3, _2, _1, N, ... \
) N

/** @private Helper of @see STD_PREV */
#define _STD_PREV_0 static_assert(false)
/** @private Helper of @see STD_PREV */
#define _STD_PREV_1 0
/** @private Helper of @see STD_PREV */
#define _STD_PREV_2 1
/** @private Helper of @see STD_PREV */
#define _STD_PREV_3 2
/** @private Helper of @see STD_PREV */
#define _STD_PREV_4 3
/** @private Helper of @see STD_PREV */
#define _STD_PREV_5 4
/** @private Helper of @see STD_PREV */
#define _STD_PREV_6 5
/** @private Helper of @see STD_PREV */
#define _STD_PREV_7 6
/** @private Helper of @see STD_PREV */
#define _STD_PREV_8 7
/** @private Helper of @see STD_PREV */
#define _STD_PREV_9 8
/** @private Helper of @see STD_PREV */
#define _STD_PREV_10 9
/** @private Helper of @see STD_PREV */
#define _STD_PREV_11 10
/** @private Helper of @see STD_PREV */
#define _STD_PREV_12 11
/** @private Helper of @see STD_PREV */
#define _STD_PREV_13 12
/** @private Helper of @see STD_PREV */
#define _STD_PREV_14 13
/** @private Helper of @see STD_PREV */
#define _STD_PREV_15 14
/** @private Helper of @see STD_PREV */
#define _STD_PREV_16 15
/** @private Helper of @see STD_PREV */
#define _STD_PREV_17 16
/** @private Helper of @see STD_PREV */
#define _STD_PREV_18 17
/** @private Helper of @see STD_PREV */
#define _STD_PREV_19 18
/** @private Helper of @see STD_PREV */
#define _STD_PREV_20 19
/** @private Helper of @see STD_PREV */
#define _STD_PREV_21 20
/** @private Helper of @see STD_PREV */
#define _STD_PREV_22 21
/** @private Helper of @see STD_PREV */
#define _STD_PREV_23 22
/** @private Helper of @see STD_PREV */
#define _STD_PREV_24 23
/** @private Helper of @see STD_PREV */
#define _STD_PREV_25 24
/** @private Helper of @see STD_PREV */
#define _STD_PREV_26 25
/** @private Helper of @see STD_PREV */
#define _STD_PREV_27 26
/** @private Helper of @see STD_PREV */
#define _STD_PREV_28 27
/** @private Helper of @see STD_PREV */
#define _STD_PREV_29 28
/** @private Helper of @see STD_PREV */
#define _STD_PREV_30 29
/** @private Helper of @see STD_PREV */
#define _STD_PREV_31 30

/** @private Helper of @see STD_STRINGIFY */
#define _STD_STRINGIFY(_x) #_x

/** @private Helper of @see STD_CAT */
#define __STD_CAT_0() 
/** @private Helper of @see STD_CAT */
#define __STD_CAT_1(_1) _1
/** @private Helper of @see STD_CAT */
#define __STD_CAT_2(_1, _2) _1 ## _2
/** @private Helper of @see STD_CAT */
#define __STD_CAT_3(_1, _2, _3) _1 ## _2 ## _3
/** @private Helper of @see STD_CAT */
#define __STD_CAT_4(_1, _2, _3, _4) _1 ## _2 ## _3 ## _4
/** @private Helper of @see STD_CAT */
#define __STD_CAT_5(_1, _2, _3, _4, _5) _1 ## _2 ## _3 ## _4 ## _5
/** @private Helper of @see STD_CAT */
#define __STD_CAT_6(_1, _2, _3, _4, _5, _6) _1 ## _2 ## _3 ## _4 ## _5 ## _6
/** @private Helper of @see STD_CAT */
#define __STD_CAT_7(_1, _2, _3, _4, _5, _6, _7) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7
/** @private Helper of @see STD_CAT */
#define __STD_CAT_8(_1, _2, _3, _4, _5, _6, _7, _8) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8
/** @private Helper of @see STD_CAT */
#define __STD_CAT_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9
/** @private Helper of @see STD_CAT */
#define __STD_CAT_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10
/** @private Helper of @see STD_CAT */
#define __STD_CAT_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11
/** @private Helper of @see STD_CAT */
#define __STD_CAT_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12
/** @private Helper of @see STD_CAT */
#define __STD_CAT_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13
/** @private Helper of @see STD_CAT */
#define __STD_CAT_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14
/** @private Helper of @see STD_CAT */
#define __STD_CAT_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15
/** @private Helper of @see STD_CAT */
#define __STD_CAT_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16
/** @private Helper of @see STD_CAT */
#define __STD_CAT_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17
/** @private Helper of @see STD_CAT */
#define __STD_CAT_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18
/** @private Helper of @see STD_CAT */
#define __STD_CAT_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19
/** @private Helper of @see STD_CAT */
#define __STD_CAT_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20
/** @private Helper of @see STD_CAT */
#define __STD_CAT_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21
/** @private Helper of @see STD_CAT */
#define __STD_CAT_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22
/** @private Helper of @see STD_CAT */
#define __STD_CAT_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23
/** @private Helper of @see STD_CAT */
#define __STD_CAT_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24
/** @private Helper of @see STD_CAT */
#define __STD_CAT_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24 ## _25
/** @private Helper of @see STD_CAT */
#define __STD_CAT_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24 ## _25 ## _26
/** @private Helper of @see STD_CAT */
#define __STD_CAT_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24 ## _25 ## _26 ## _27
/** @private Helper of @see STD_CAT */
#define __STD_CAT_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24 ## _25 ## _26 ## _27 ## _28
/** @private Helper of @see STD_CAT */
#define __STD_CAT_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24 ## _25 ## _26 ## _27 ## _28 ## _29
/** @private Helper of @see STD_CAT */
#define __STD_CAT_30(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24 ## _25 ## _26 ## _27 ## _28 ## _29 ## _30
/** @private Helper of @see STD_CAT */
#define __STD_CAT_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16 ## _17 ## _18 ## _19 ## _20 ## _21 ## _22 ## _23 ## _24 ## _25 ## _26 ## _27 ## _28 ## _29 ## _30 ## _31
/** @private Helper of @see STD_CAT */
#define _STD_CAT_0() __STD_CAT_0()
/** @private Helper of @see STD_CAT */
#define _STD_CAT_1(_1) __STD_CAT(_1)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_2(_1, _2) __STD_CAT_2(_1, _2)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_3(_1, _2, _3) __STD_CAT_3(_1, _2, _3)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_4(_1, _2, _3, _4) __STD_CAT_4(_1, _2, _3, _4)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_5(_1, _2, _3, _4, _5) __STD_CAT_5(_1, _2, _3, _4, _5)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_6(_1, _2, _3, _4, _5, _6) __STD_CAT_6(_1, _2, _3, _4, _5, _6)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_7(_1, _2, _3, _4, _5, _6, _7) __STD_CAT_7(_1, _2, _3, _4, _5, _6, _7)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_8(_1, _2, _3, _4, _5, _6, _7, _8) __STD_CAT_8(_1, _2, _3, _4, _5, _6, _7, _8)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) __STD_CAT_9(_1, _2, _3, _4, _5, _6, _7, _8, _9)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) __STD_CAT_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) __STD_CAT_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) __STD_CAT_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) __STD_CAT_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) __STD_CAT_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) __STD_CAT_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) __STD_CAT_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) __STD_CAT_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) __STD_CAT_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) __STD_CAT_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) __STD_CAT_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) __STD_CAT_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) __STD_CAT_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) __STD_CAT_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) __STD_CAT_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) __STD_CAT_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) __STD_CAT_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) __STD_CAT_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) __STD_CAT_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) __STD_CAT_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_30(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) __STD_CAT_30(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) __STD_CAT_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31)
/** @private Helper of @see STD_CAT */
#define _STD_CAT_SELECT(_n) __STD_CAT_2(_STD_CAT_, _n)

/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_0(_0, ...) _0
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_1(_0, _1, ...) _1
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_2(_0, _1, _2, ...) _2
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_3(_0, _1, _2, _3, ...) _3
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_4(_0, _1, _2, _3, _4, ...) _4
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_5(_0, _1, _2, _3, _4, _5, ...) _5
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_6(_0, _1, _2, _3, _4, _5, _6, ...) _6
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_7(_0, _1, _2, _3, _4, _5, _6, _7, ...) _7
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) _8
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) _11
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) _12
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) _13
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) _14
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) _15
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) _16
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) _17
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) _18
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) _19
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, ...) _20
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_21(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, ...) _21
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_22(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, ...) _22
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_23(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, ...) _23
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_24(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, ...) _24
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_25(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, ...) _25
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_26(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, ...) _26
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_27(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, ...) _27
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_28(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, ...) _28
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_29(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, ...) _29
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_30(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, ...) _30
/** @private Helper of @see STD_VAARGS_GET_ELEM */
#define _STD_VAARGS_GET_ELEM_31(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, ...) _31

/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_0(_0, ...) STD_CAT(STD_EMPTY_MACRO, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_1(_0, _1, ...) STD_CAT(_0, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_2(_0, _1, _2, ...) STD_CAT(_0, _1, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_3(_0, _1, _2, _3, ...) STD_CAT(_0, _1, _2, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_4(_0, _1, _2, _3, _4, ...) STD_CAT(_0, _1, _2, _3, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_5(_0, _1, _2, _3, _4, _5, ...) STD_CAT(_0, _1, _2, _3, _4, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_6(_0, _1, _2, _3, _4, _5, _6, ...) STD_CAT(_0, _1, _2, _3, _4, _5, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_7(_0, _1, _2, _3, _4, _5, _6, _7, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_21(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_22(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_23(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_24(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_25(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_26(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_27(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_28(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_29(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_30(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_CAT_EXCEPT */
#define _STD_VAARGS_CAT_EXCEPT_31(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, ...) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, __VA_ARGS__)

/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_0(_0) _0
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_1(_0, _1) STD_CAT(_0, _1)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_2(_0, _1, _2) STD_CAT(_0, _1, _2)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_3(_0, _1, _2, _3) STD_CAT(_0, _1, _2, _3)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_4(_0, _1, _2, _3, _4) STD_CAT(_0, _1, _2, _3, _4)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_5(_0, _1, _2, _3, _4, _5) STD_CAT(_0, _1, _2, _3, _4, _5)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_6(_0, _1, _2, _3, _4, _5, _6) STD_CAT(_0, _1, _2, _3, _4, _5, _6)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_7(_0, _1, _2, _3, _4, _5, _6, _7) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_8(_0, _1, _2, _3, _4, _5, _6, _7, _8) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_21(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_22(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_23(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_24(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_25(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_26(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_27(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_28(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_29(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_30(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30)
/** @private Helper of @see STD_VAARGS_CAT */
#define _STD_VAARGS_CAT_31(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) STD_CAT(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31)

/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_0(_0, ...) __VA_OPT__(__VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_1(_0, _1, ...) _0 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_2(_0, _1, _2, ...) _0, _1 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_3(_0, _1, _2, _3, ...) _0, _1, _2 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_4(_0, _1, _2, _3, _4, ...) _0, _1, _2, _3 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_5(_0, _1, _2, _3, _4, _5, ...) _0, _1, _2, _3, _4 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_6(_0, _1, _2, _3, _4, _5, _6, ...) _0, _1, _2, _3, _4, _5 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_7(_0, _1, _2, _3, _4, _5, _6, _7, ...) _0, _1, _2, _3, _4, _5, _6 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) _0, _1, _2, _3, _4, _5, _6, _7 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_21(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_22(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_23(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_24(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_25(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_26(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_27(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_28(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_29(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_30(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29 __VA_OPT__(, __VA_ARGS__)
/** @private Helper of @see STD_VAARGS_GET_EXCEPT */
#define _STD_VAARGS_GET_EXCEPT_31(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, ...) _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _3 __VA_OPT__(, __VA_ARGS__)

/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_0(_0) _0
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_1(_0, _1) _0; _1
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_2(_0, _1, _2) _0; _1; _2
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_3(_0, _1, _2, _3) _0; _1; _2; _3
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_4(_0, _1, _2, _3, _4) _0; _1; _2; _3; _4
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_5(_0, _1, _2, _3, _4, _5) _0; _1; _2; _3; _4; _5
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_6(_0, _1, _2, _3, _4, _5, _6) _0; _1; _2; _3; _4; _5; _6
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_7(_0, _1, _2, _3, _4, _5, _6, _7) _0; _1; _2; _3; _4; _5; _6; _7
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_8(_0, _1, _2, _3, _4, _5, _6, _7, _8) _0; _1; _2; _3; _4; _5; _6; _7; _8
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _9
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _10
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_21(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_22(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_23(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_24(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_25(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24; _25
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_26(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24; _25; _26
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_27(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24; _25; _26; _27
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_28(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24; _25; _26; _27; _28
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_29(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24; _25; _26; _27; _28; _29
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_30(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24; _25; _26; _27; _28; _29; _30
/** @private Helper of STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS */
#define _STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_31(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) _0; _1; _2; _3; _4; _5; _6; _7; _8; _9; _10; _11; _12; _13; _14; _15; _16; _17; _18; _19; _20; _21; _22; _23; _24; _25; _26; _27; _28; _29; _30; _31

