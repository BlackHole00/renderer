/**
 * @module STD
 * @file modules/std/include/std/lang/defer.h
 * @author Vicix (www.github.com/BlackHole00)
 * @brief This file implements a simple defer solution for the clang compiler
 *
 * Defer is a statement common in more modern languages (it behaves logically 
 * the same as D's scope(exit) and odin and zig's defer).
 * The defer statement allows the programmer to defer the execution of a 
 * statement to the end of the block. Note that if more defers are used in the
 * same block, the defer statements will be resolved in reverse order. 
 *
 * An example follows:
 * @{code 
 *     void function1() { // prints "acdb"
 *	       printf("a");
 *         defer(printf("b"));
 *         printf("c");
 *         defer(printf("d"));
 *     }
 *     void function2(Allocator allocator) { // will not crash
 *	       isize* num = make(isize, allocator);
 *         defer delete(num, allocator);
 *
 *		   *num = 42;
 *     }
 * }
 *
 * TODO(Vicix): Implement a better __attribute((cleanup)) as a defer alternative
 * @warning The defer statement is an hack. It does use the clang-only block
 *          feature and thus has a small performance impact. Please use the 
 *          defer statement only for prototyping. Consider using instead the
 *          temporary allocator or goto statements.
 */
#pragma once

#include <std/macro/macros.h>

/** @private Helper for @see defer */
static inline void _std_defer_resolution(void (^*defer_block)(void)) {
	(*defer_block)();
}

/** @private Helper for @see defer */
#define _STD_DEFER_BLOCK_NAME() STD_CAT(_std_defer_block, __COUNTER__)

/**
 * @def defer(...)
 * @brief Defers the execution of a statement to the end of the block
 * @param ... The statement
 * @warning defer has a small performance impact. Consider using the temporary
 *          allocator or goto statements instead
 */
#define defer(...) __attribute__((cleanup(_std_defer_resolution))) void (^_STD_DEFER_BLOCK_NAME())(void) = ^{ __VA_ARGS__; }
