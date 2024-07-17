/**
 * @module STD
 * @file modules/std/include/std/lang/source_code_location.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <std/lang/types.h>

typedef struct {
	rawstring file;
	rawstring function;
	usize line;
} SourceCodeLocation;

#define sourcecodelocation_current() ((SourceCodeLocation){\
	.file = (rawstring)(__FILE__),\
	.line = __LINE__,\
	.function = (rawstring)(__FUNCTION__),\
})


