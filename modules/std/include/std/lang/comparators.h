#pragma once

#include <std/macro/macros.h>
#include <strings.h>

#define equality_comparator(T) STD_CAT(T, _equality_comparator)
#define scalar_comparator(T) STD_CAT(T, _scalar_comparator)

#define STD_DECLARE_STANDARD_EQUALITY_COMPARATOR_OF(T) \
static inline bool equality_comparator(T)(T left, T right) { \
	return left == right; \
}

#define STD_DECLARE_STANDARD_SCALAR_COMPARATOR_OF(T) \
static inline isize scalar_comparator(T)(T left, T right) { \
	if (left > right) { \
		return -1; \
	} else if (right > left) { \
		return 1; \
	} else { \
		return 0; \
	} \
}

#define STD_DECLARE_STRING_EQUALITY_COMPARATOR_OF(T) \
static inline bool equality_comparator(T)(T left, T right) { \
	return strcmp(left, right) == 0; \
}

#define STD_DECLARE_STRING_SCALAR_COMPARATOR_OF(T) \
static inline isize scalar_comparator(T)(T left, T right) { \
	return strcmp(left, right); \
}

#define STD_DECLARE_STANDARD_COMPARATORS_OF(T) \
	STD_DECLARE_STANDARD_EQUALITY_COMPARATOR_OF(T) \
	STD_DECLARE_STANDARD_SCALAR_COMPARATOR_OF(T)

#define STD_DECLARE_STRING_COMPARATORS_OF(T) \
	STD_DECLARE_STRING_EQUALITY_COMPARATOR_OF(T) \
	STD_DECLARE_STRING_SCALAR_COMPARATOR_OF(T)
	
