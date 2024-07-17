/**
 * @module STD
 * @file modules/std/include/std/lang/trap.h
 * @author Vicix (www.github.com/BlackHole00)
 * @brief This file checks for compatibility issues with the compiler. If the 
 *        compiler is not valid, an error will be thrown
 */
#pragma once

#if !defined(__clang__) || __clang_major__ < 18
	#error STD only supports the clang 18 compiler or newer
#endif

#if __STDC_VERSION__ < 202311L
	#error STD only supports c23. Please build with the -std=c23 compile flag
#endif
