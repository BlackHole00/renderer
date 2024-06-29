#pragma once

#include <std/runtime/optional.h>
#include <std/runtime/slice.h>

#define STD_DECLARE_STANDARD_TYPES_OF(T) STD_DECLARE_SLICE_OF(T) \
	STD_DECLARE_OPTIONAL_OF(T)

