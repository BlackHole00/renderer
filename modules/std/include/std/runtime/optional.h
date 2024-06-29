#pragma once

#include <assert.h>
#include <std/macro/macros.h>

#define Optional(T) STD_CAT(Optional_, T)
#define optional_from(T) STD_CAT(optional_, T, _from)
#define optional_none(T) STD_CAT(optional_, T, _none)
#define optional_is_valid(T) STD_CAT(optional_, T, _is_valid)
#define optional_value(T) STD_CAT(optional_, T, _value)

#define STD_DECLARE_OPTIONAL_OF(T)                                     		   \
typedef struct {                                                       		   \
	T value;                                                           		   \
	bool valid;                                                        		   \
} Optional(T);                                                         		   \
																			   \
static inline Optional(T) optional_from(T)(T value) {                  		   \
	return (Optional(T)){                                              		   \
		.value = value;                                                		   \
		.valid = true;                                                 		   \
	};                                                                 		   \
}                                                                      		   \
static inline Optional(T) optional_none(T)() {                         		   \
	return (Optional(T)){                                              		   \
		.valid = false;                                                		   \
	};                                                                 		   \
}                                                                      		   \
static inline Optional(T) optional_is_valid(T)(Optional(T) optional) { 		   \
	return optional.valid;                                             		   \
}                                                                      		   \
static inline T optional_value(T)(Optional(T) optional) {              		   \
	assert(optional.valid);                                            		   \
	return optional.value;                                             		   \
} 

