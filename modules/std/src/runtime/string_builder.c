#include <std/runtime/string_builder.h>

#include <std/lang/assert.h>
#include <stdarg.h>

void stringbuilder_make(StringBuilder* builder, Allocator allocator) {
	builder->allocator = allocator;
	builder->buffer = vector_make(char)(allocator);
	builder->has_been_built = false;
}

string stringbuilder_build(StringBuilder* builder) {
	builder->has_been_built = true;
	return stringbuilder_peek(builder);
}

string stringbuilder_build_substring(StringBuilder* builder, usize start, usize end) {
	builder->has_been_built = true;
	return stringbuilder_peek_substring(builder, start, end);
}

void stringbuilder_clean(StringBuilder* builder) {
	if (!builder->has_been_built) {
		vector_delete(char)(&builder->buffer);
	}
	builder->has_been_built = false;
}

Optional(char) stringbuilder_charat(const StringBuilder* builder, usize index) {
	char* char_ptr = vector_get(char)(&builder->buffer, index);

	if (char_ptr == nullptr) {
		return optional_none(char)();
	}
	return optional_from(char)(*char_ptr);
}

void stringbuilder_append(StringBuilder* builder, string str) {
	usize starting_length = stringbuilder_length(builder);
	if (starting_length > 0) { // NOTE(Vicix): Account for previous null terminator character
		starting_length -= 1;
	}
	usize required_length = starting_length + str.length;

	vector_resize(char)(&builder->buffer, required_length);
	memcpy(&builder->buffer.data[starting_length], &str.raw_string[0], str.length);
}

void stringbuilder_append_format(StringBuilder* builder, rawstring format, ...) {
	va_list args;
	va_start(args, format);

	usize format_length = vsnprintf(nullptr, 0, format, args);

	usize starting_length = stringbuilder_length(builder);
	if (starting_length > 0) { // NOTE(Vicix): Account for previous null terminator character
		starting_length -= 1;
	}
	usize required_length = starting_length + format_length;

	vector_resize(char)(&builder->buffer, required_length);

	rawstring first_free_space = &builder->buffer.data[starting_length];
	vsprintf(first_free_space, format, args);

	va_end(args);
}

void stringbuilder_replace_all(StringBuilder* builder, string find, string replace) {
	unimplemented();
}
