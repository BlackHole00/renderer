/**
 * @module STD
 * @file modules/std/include/std/macro/macros.h
 * @author Vicix (www.github.com/BlackHole00)
 * @brief Usefull macros used across the project
 *
 * This file contains some of macros usefull to implement macro template coding.
 * 
 * @note The majority of the macros do not expect more than 31 macro
 * 		 arguments. This will be fixed when metaprogramming will be implemented.
 * @note This file is reliant on C23 (__VA_OPT__ usage) and clang specifically
 *       (specific pragmas)
 */
#pragma once

#include <std/macro/private.h>

/** STD_EMPTY_MACRO is a macro that expands to nothing */
#define STD_EMPTY_MACRO  
/** STD_EMPTY_EXPRESSION is a macro that expands to the empty expression ((void)0) */
#define STD_EMPTY_EXPRESSION ((void)(0))

/** STD_COMMA is a macro that expands to the comma ',' token */
#define STD_COMMA ,

/**
 * @def STD_EVAL(...)
 * @brief Evals (expands) the inputed expression
 */
#define STD_EVAL(...) __VA_ARGS__

/**
 * @def STD_BEGIN
 * @brief Expands to `do {` used for inline macros
 */
#define STD_BEGIN do {

/**
 * @def STD_END
 * @brief Expands to `} while (false)` used for inline macros
 */
#define STD_END } while (false);

/**
 * @def STD_STRINGIFY(_x)
 * @brief Evals and stringifies an inputed expression
 */
#define STD_STRINGIFY(_x) _STD_STRINGIFY(_x)

/**
 * @def STD_VAARGS_COUNT(...)
 * @brief Returns the count of the arguments in the provided expression
 */
#define STD_VAARGS_COUNT(...) _STD_VAARGS_COUNT( __VA_OPT__(__VA_ARGS__ ,) \
    31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, \
    13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 \
)

/**
 * @def STD_PREV(_n)
 * @brief Returns the previous number of the provided one
 * @param _n A number as a compile time token
 * @return _n - 1 as a compile time token
 */
#define STD_PREV(_n) STD_CAT(_STD_PREV_, _n)

/**
 * @def STD_CAT(...)
 * @brief Concatenated together multiple tokes
 * @param ... A list of tokes (as variadic arguments)
 * @return The concatenated tokens
 * @note The provided tokens will be expanded
 */
#define STD_CAT(...) _STD_CAT_SELECT(STD_VAARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)

/**
 * @def STD_VAARGS_GET_ELEM(_n, ...)
 * @brief Gets the n-th element of a token list
 * @param _n The desired element index
 * @param ... A list of tokens (as variadic arguments)
 */
#define STD_VAARGS_GET_ELEM(_n, ...) STD_CAT(_STD_VAARGS_GET_ELEM_, _n)(__VA_ARGS__)

/**
 * @def STD_VAARGS_GET_LAST(...)
 * @brief Gets the first element of a token list
 * @param ... A list of tokens (as variadic arguments)
 */
#define STD_VAARGS_GET_FIRST(...) _STD_VAARGS_GET_ELEM_0(__VA_ARGS__)

/**
 * @def STD_VAARGS_GET_LAST(...)
 * @brief Gets the last element of a token list
 * @param ... A list of tokens (as variadic arguments)
 */
#define STD_VAARGS_GET_LAST(...) STD_VAARGS_GET_ELEM(STD_VAARGS_COUNT(__VA_ARGS__), _ignored, __VA_ARGS__,)

/**
 * @def STD_VAARGS_IS_EMPTY(...)
 * @brief Checks if a provided token list is empty
 * @param ... A list of tokens (as variadic arguments)
 * @return 0 if the list is not empty, 1 is the list is empty. Both as compile
 *		   time tokens
 */
#define STD_VAARGS_IS_EMPTY(...) STD_VAARGS_GET_FIRST(__VA_OPT__(0,) 1)

/**
 * @def STD_VAARGS_CAT_EXCEPT_FIRST(...)
 * @brief Returns all the tokes concatenated together 
 * @param ... A list of tokens (as variadic arguments)
 * @note The provided tokens will be expanded
 */
#define STD_VAARGS_CAT(...) STD_CAT(_STD_VAARGS_CAT_, STD_VAARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)

/**
 * @def STD_VAARGS_CAT_EXCEPT(_n, ...)
 * @brief Returns all the tokes concatenated together except the n-th
 * @param _n The index of the parameter to exclude
 * @param ... A list of tokens (as variadic arguments)
 * @note The provided tokens will be expanded
 */
#define STD_VAARGS_CAT_EXCEPT(_n, ...) STD_CAT(_STD_VAARGS_CAT_EXCEPT_, _n)(__VA_ARGS__)

/**
 * @def STD_VAARGS_CAT_EXCEPT_LAST(...)
 * @brief Returns all the tokes concatenated together except the last
 * @param ... A list of tokens (as variadic arguments)
 * @note The provided tokens will be expanded
 */
#define STD_VAARGS_CAT_EXCEPT_LAST(...) STD_VAARGS_CAT_EXCEPT(STD_PREV(STD_VAARGS_COUNT(__VA_ARGS__)), __VA_ARGS__, )

/**
 * @def STD_VAARGS_CAT_EXCEPT_FIRST(...)
 * @brief Returns all the tokes concatenated together except the first
 * @param ... A list of tokens (as variadic arguments)
 * @note The provided tokens will be expanded
 */
#define STD_VAARGS_CAT_EXCEPT_FIRST(...) _STD_VAARGS_CAT_EXCEPT_0(__VA_ARGS__, )

/**
 * @def STD_VAARGS_GET_EXCEPT(_n, ...)
 * @brief Returns a list of the tokes, excluding the n-th
 * @param _n The index of the parameter to exclude
 * @param ... A list of tokens (as variadic arguments)
 * @note The provided tokens will be expanded
 */
#define STD_VAARGS_GET_EXCEPT(_n, ...) STD_CAT(_STD_VAARGS_GET_EXCEPT_, _n)(__VA_ARGS__)

/**
 * @def STD_VAARGS_GET_EXCEPT_LAST(...)
 * @brief Returns a list of the provided tokens, excluding the last one
 * @param ... A list of tokens (as variadic arguments)
 * @note The provided tokens will be expanded
 */
#define STD_VAARGS_GET_EXCEPT_LAST(...) STD_VAARGS_GET_EXCEPT(STD_PREV(STD_VAARGS_COUNT(__VA_ARGS__)), __VA_ARGS__,)


/**
 * @def STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS(...)
 * @brief Returns a list of the tokes, subdivided by semicolons
 * @param _n The index of the parameter to exclude
 * @param ... A list of tokens (as variadic arguments)
 * @note The provided tokens will be expanded
 */
#define STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS(...) STD_CAT(_STD_VAARGS_REPLACE_COMMAS_WITH_SEMICOLONS_, STD_VAARGS_COUNT(__VA_ARGS__))(__VA_ARGS__, )

/**
 * @def STD_IGNORED_UNUSED_VAR_BLOCK(...)
 * @brief Creates a block of code where unused variable do not issue warnings
 * @param ... The code block
 */
#define STD_IGNORE_UNUSED_VAR_BLOCK(...) \
	_Pragma("clang diagnostic push") \
	_Pragma("clang diagnostic ignored \"-Wunused-variable\"") \
	__VA_ARGS__ \
	_Pragma("clang diagnostic pop")

/**
 * @def static_typecheck(...)
 * @brief Causes a compile error if the type of a provided variable is not the
 *        same as the one specified
 * @param ... (except last token) The type
 * @param ... (last token) The variable
 */
#define static_typecheck(...) STD_IGNORE_UNUSED_VAR_BLOCK( \
	static const int STD_CAT(__STD_STATIC_TYPECHECK_, __COUNTER__) = (_Generic(STD_VAARGS_GET_LAST(__VA_ARGS__), STD_VAARGS_GET_EXCEPT_LAST(__VA_ARGS__): 0)) \
)

/**
 * @def transmute(_type, _x)
 * @brief Equivalent to cpp's static_cast. Converts a value mantaining its bits
 * @param _type The resulting type
 * @param _x The variable to transmute
 */
//TODO(Vicix): Change to use va_args
#define transmute(_type, _x) (*((_type*)(&(_x))));static_assert(sizeof(_x) == sizeof(_type), "Cannot trasmute variable " #_x " to type of different size")
