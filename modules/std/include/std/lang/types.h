/**
 * @module STD
 * @file modules/std/include/std/lang/types.h
 * @author Vicix (www.github.com/BlackHole00)
 * @brief This file defines more explicit types
 */
#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <strings.h>

#include <std/lang/comparators.h>

/**
 * @typedef int8_t i8
 * @brief A signed 8 bit integer
 */
typedef int8_t i8;

/**
 * @typedef int16_t i16
 * @brief A signed 16 bit integer
 */
typedef int16_t i16;

/**
 * @typedef int32_t i32
 * @brief A signed 32 bit integer
 * @note Prefer using isize when 32 bit are not required
 */
typedef int32_t i32;

/**
 * @typedef int64_t i64
 * @brief A signed 64 bit integer
 */
typedef int64_t i64;

/**
 * @typedef uint8_t u8
 * @brief Am unsigned 8 bit integer
 */
typedef uint8_t u8;

/**
 * @typedef uint16_t u16
 * @brief Am unsigned 16 bit integer
 */
typedef uint16_t u16;

/**
 * @typedef uint32_t u32
 * @brief Am unsigned 32 bit integer
 * @note Prefer using usize when 32 bit are not required
 */
typedef uint32_t u32;

/**
 * @typedef uint64_t u64
 * @brief Am unsigned 64 bit integer
 */
typedef uint64_t u64;

/**
 * @typedef _Float16 f16
 * @brief A half precision 16 bit float
 */
typedef _Float16 f16;

/**
 * @typedef float f32
 * @brief A standard 32 bit float
 */
typedef float f32;

/**
 * @typedef double f64
 * @brief A double precision 64 bit float
 */
typedef double f64;

/**
 * @typedef ssize_t isize
 * @brief A register-size signed integer
 * @note Prefer using this instead of int, i32 or i64, when a specific size is
 *       not required
 */
typedef ssize_t isize;

/**
 * @typedef size_t usize
 * @brief A register-size unsigned integer
 * @note Prefer using this instead of unsigned int, u32 or u64, when a specific
 *       size is not required
 */
typedef size_t  usize;

/**
 * @typedef uint8_t byte
 * @brief An unsigned 8-bit byte
 */
typedef uint8_t byte;

/**
 * @typedef wchar_t rune
 * @brief An utf8 codified character
 */
typedef wchar_t rune;

/**
 * @typedef char* rawstring
 * @brief A standard c string
 */
typedef char* rawstring;

// typedef f32 vec2f32 __attribute__((ext_vector_type(2)));
// typedef f32 vec3f32 __attribute__((ext_vector_type(3)));
// typedef f32 vec4f32 __attribute__((ext_vector_type(4)));

// typedef f64 vec2f64 __attribute__((ext_vector_type(2)));
// typedef f64 vec3f64 __attribute__((ext_vector_type(3)));
// typedef f64 vec4f64 __attribute__((ext_vector_type(4)));

/**
 * @def atomic(...)
 * @brief An attribute that turns a type into an atomic one
 * @param ... The type to turn into an atomic
 * Turns any type into an atomic one. Follows an example:
 *     {@code atomic(usize) variable_name;}
 */
#define atomic(...) _Atomic(__VA_ARGS__)

/**
 * @def countof(_array)
 * @brief Returns the number of elements contained in a static array
 */
#define countof(_array) (sizeof(_array) / sizeof(*_array))

/**
 * @def before_main
 * @brief An attribute that allows a function to be called before the main()
 *        entry point
 */
#define before_main __attribute__((constructor))

/**
 * @def after_main
 * @brief An attribute that allows a function to be called after the main()
 *        entry point
 */
#define after_main  __attribute__((destructor))

STD_DECLARE_STANDARD_COMPARATORS_OF(i8)
STD_DECLARE_STANDARD_COMPARATORS_OF(u8)
STD_DECLARE_STANDARD_COMPARATORS_OF(i16)
STD_DECLARE_STANDARD_COMPARATORS_OF(u16)
STD_DECLARE_STANDARD_COMPARATORS_OF(i32)
STD_DECLARE_STANDARD_COMPARATORS_OF(u32)
STD_DECLARE_STANDARD_COMPARATORS_OF(i64)
STD_DECLARE_STANDARD_COMPARATORS_OF(u64)
STD_DECLARE_STANDARD_COMPARATORS_OF(f64)
STD_DECLARE_STANDARD_COMPARATORS_OF(f32)
STD_DECLARE_STANDARD_COMPARATORS_OF(isize)
STD_DECLARE_STANDARD_COMPARATORS_OF(usize)
STD_DECLARE_STANDARD_COMPARATORS_OF(byte)
STD_DECLARE_STANDARD_COMPARATORS_OF(rune)

STD_DECLARE_STRING_COMPARATORS_OF(rawstring)

