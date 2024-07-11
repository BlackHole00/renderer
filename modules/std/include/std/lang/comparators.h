#pragma once

#include <std/macro/macros.h>
#include <strings.h>

#define equality_comparator_of(T) STD_CAT(T, _equality_comparator)
#define scalar_comparator_of(T) STD_CAT(T, _scalar_comparator)

#define equality_comparator(T) equality_comparator_of(T)
#define scalar_comparator(T) scalar_comparator_of(T)

#define STD_DECLARE_STANDARD_EQUALITY_COMPARATOR_OF(T) \
static inline bool equality_comparator_of(T)(const T* left, const T* right) { \
	return left != nullptr && right != nullptr && *left == *right; \
}

#define STD_DECLARE_STANDARD_SCALAR_COMPARATOR_OF(T) \
static inline isize scalar_comparator_of(T)(const T* left, const T* right) { \
	if (left == nullptr || right == nullptr) { \
		return -1; \
	} \
	if (*left > *right) { \
		return -1; \
	} else if (*right > *left) { \
		return 1; \
	} else { \
		return 0; \
	} \
}

#define STD_DECLARE_STRING_EQUALITY_COMPARATOR_OF(T) \
static inline bool equality_comparator_of(T)(const T* left, const T* right) { \
	return left != nullptr && right != nullptr && strcmp(*left, *right) == 0; \
}

#define STD_DECLARE_STRING_SCALAR_COMPARATOR_OF(T) \
static inline isize scalar_comparator_of(T)(const T* left, const T* right) { \
	if (left == nullptr || right == nullptr) { \
		return -1; \
	} \
	return strcmp(*left, *right); \
}

#define STD_DECLARE_STANDARD_COMPARATORS_OF(T) \
	STD_DECLARE_STANDARD_EQUALITY_COMPARATOR_OF(T) \
	STD_DECLARE_STANDARD_SCALAR_COMPARATOR_OF(T)

#define STD_DECLARE_STRING_COMPARATORS_OF(T) \
	STD_DECLARE_STRING_EQUALITY_COMPARATOR_OF(T) \
	STD_DECLARE_STRING_SCALAR_COMPARATOR_OF(T)
	
