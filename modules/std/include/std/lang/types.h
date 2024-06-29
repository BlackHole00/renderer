#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef ssize_t isize;
typedef size_t  usize;

typedef uint8_t byte;
typedef wchar_t rune;

typedef char* rawstring;

#define unicode_literal(_literal) (L"_literal")
