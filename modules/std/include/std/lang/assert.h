#pragma once

#include <std/lang/types.h>
#include <std/lang/source_code_location.h>
#include <stdarg.h>
#include <stdlib.h>

#define panic(...) panic_ex(sourcecodelocation_current(), __VA_ARGS__)

[[noreturn, gnu::format(printf, 2, 3)]]
static inline void panic_ex(SourceCodeLocation location, rawstring message, ...) {
	va_list args;
	va_start(args, message);

	printf("[PANIC] Program panicked at function %s:%lu for reason: ", location.function, location.line);
	vprintf(message, args);
	printf("\n");

	exit(-1);
}

#define unimplemented() panic("Function not implemented")
