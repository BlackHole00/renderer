#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <strings.h>

#include <std/lang/comparators.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef _Float16 f16;
typedef float f32;
typedef double f64;

typedef ssize_t isize;
typedef size_t  usize;

typedef uint8_t byte;
typedef wchar_t rune;

typedef char* rawstring;

typedef f32 vec2f32 __attribute__((ext_vector_type(2)));
typedef f32 vec3f32 __attribute__((ext_vector_type(3)));
typedef f32 vec4f32 __attribute__((ext_vector_type(4)));

typedef f64 vec2f64 __attribute__((ext_vector_type(2)));
typedef f64 vec3f64 __attribute__((ext_vector_type(3)));
typedef f64 vec4f64 __attribute__((ext_vector_type(4)));

#define unicode_literal(_literal) (L"_literal")

#define atomic _Atomic

#define countof(_array) (sizeof(_array) / sizeof(*_array))

#define before_main __attribute__((constructor))
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

