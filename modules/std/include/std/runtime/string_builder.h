#pragma once

#include <std/runtime/string.h>
#include <std/containers/vector.h>

typedef struct {
	Allocator allocator;
	Vector(char) buffer;
	bool has_been_built;
} StringBuilder;

void stringbuilder_make(StringBuilder* builder, Allocator allocator);

string stringbuilder_build(StringBuilder* builder);
string stringbuilder_build_substring(StringBuilder* builder, usize start, usize end);
void stringbuilder_clean(StringBuilder* builder);

static inline string stringbuilder_peek(const StringBuilder* builder) {
	return string_from_slice(vector_as_slice(char)(&builder->buffer));
}
static inline string stringbuilder_peek_substring(const StringBuilder* builder, usize start, usize end) {
	return string_from_slice(vector_as_subslice(char)(&builder->buffer, start, end));
}
Optional(char) stringbuilder_charat(const StringBuilder* builder, usize index);

static inline usize stringbuilder_length(const StringBuilder* builder) {
	return builder->buffer.length;
}

static inline void stringbuilder_resize(StringBuilder* builder, usize length) {
	vector_resize(char)(&builder->buffer, length);
}
void stringbuilder_append(StringBuilder* builder, string str);
static inline void stringbuilder_append_char(StringBuilder* builder, char chr) {
	vector_append(char)(&builder->buffer, chr);
}

[[gnu::format(printf, 2, 3)]]
void stringbuilder_append_format(StringBuilder* builder, rawstring format, ...);

void stringbuilder_replace_all(StringBuilder* builder, string find, string replace);

