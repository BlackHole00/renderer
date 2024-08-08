#pragma once

#include <std/runtime/optional.h>
#include <std/runtime/slice.h>
#include <std/runtime/slice_utils.h>
#include <std/runtime/allocator.h>
#include <string.h>

// TODO(Vicix): Turn into UTF8 string
typedef union {
	Slice(char) slice;
	struct {
		rawstring raw_string;
		usize length;
	};
} string;

static inline string string_from_slice(Slice(char) slice) {
	return (string){ slice };
}

static inline string string_from_length(rawstring raw_string, usize length) {
	return (string){
		.raw_string = raw_string,
		.length = length,
	};
}

static inline string string_from(rawstring raw_string) {
	return string_from_length(raw_string, strlen(raw_string));
}

static inline string string_make_with_length(rawstring raw_string, usize length, Allocator allocator) {
	Slice(char) backing_slice = slice_make_from_data(char)((char*)(raw_string), length, allocator);
	return (string){ backing_slice };
}

static inline string string_make(rawstring raw_string, Allocator allocator) {
	return string_make_with_length(raw_string, strlen(raw_string), allocator);
}

static inline string string_make_empty(usize length, Allocator allocator) {
	Slice(char) backing_slice = slice_make(char)(length, allocator);
	return (string){ backing_slice };
}

static inline Optional(char) string_charat(string str, usize index) {
	if (str.length >= index) {
		return optional_none(char)();
	}
	return optional_from(char)(str.raw_string[index]);
}

static inline string string_substring(string str, usize start, usize end) {
	Slice(char) backing_slice = slice_subslice(char)(str.slice, start, end);
	return (string){ backing_slice };
}
