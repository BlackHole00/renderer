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
		.length = length + 1,
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

static inline string string_clone(string str, Allocator allocator) {
	return string_make_with_length(str.raw_string, str.length, allocator);
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

static inline bool equality_comparator_of(string)(const string* left, const string* right) {
	static_typecheck(STD_EQUALITY_COMPARATOR_SIGNATURE(string), equality_comparator_of(string));
	return strcmp(left->raw_string, right->raw_string) == 0;
}

static inline isize scalar_comparator_of(string)(const string* left, const string* right) {
	static_typecheck(STD_SCALAR_COMPARATOR_SIGNATURE(string), scalar_comparator_of(string));
	return strcmp(left->raw_string, right->raw_string);
}

static inline void cloner_of(string)(const string* source, string* destination, Allocator allocator) {
	*destination = string_clone(*source, allocator);
}

STD_DECLARE_SLICE_OF(string)
STD_DECLARE_SLICE_MEM_UTILS_OF(string)
STD_DECLARE_SLICE_COMMON_UTILS_OF(string, equality_comparator_of(string))
STD_DECLARE_OPTIONAL_OF(string)

