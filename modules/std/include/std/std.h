/**
 * @module STD
 * @file modules/std/include/std.h
 * @author Vicix (www.github.com/BlackHole00)
 * @brief A Better standard library for C
 *
 * STD is an alternative standard library built on top of the default standard
 * library. Its main purpose is to make C a more modern language without
 * changing its principles.
 * 
 * STD implements usefull things like:
 *     - usefull macros, especially for managing variadic argument macros
 *	   - improved, more explicit types (link u32 and i64)
 *	   - new language utilities (like defer and lambda)
 *	   - improved data structures (like descriptors, singletons, vtables...)
 *     - improved logging
 *     - improved memory management (using slices, allocators and arenas)
 *     - a context system
 *     - generic templated types (like optionals, slices and vectors)
 *	   - a typesafe trait-like system for implementing generic data structures
 *     - and a lot more...
 * 
 * @note STD required clang 18 (or newer) and the c23 standard of C. This is
 *       because both c23 features and clang specific extensions are used.
 */
#pragma once

#include <std/lang/trap.h>

#include <std/macro/macros.h>

#include <std/lang/types.h>
#include <std/lang/defer.h>
#include <std/lang/singleton.h>
#include <std/lang/descriptor.h>
#include <std/lang/vtable.h>
#include <std/lang/comparators.h>
#include <std/lang/cloners.h>
#include <std/lang/lambda.h>
#include <std/lang/mem.h>
#include <std/lang/log.h>
#include <std/lang/source_code_location.h>

#include <std/math/bits.h>

#include <std/runtime/optional.h>
#include <std/runtime/slice.h>
#include <std/runtime/slice_utils.h>
#include <std/runtime/allocator.h>
#include <std/runtime/logger.h>
#include <std/runtime/context.h>

#include <std/runtime/allocators/system_allocator.h>
#include <std/runtime/allocators/arena_allocator.h>
#include <std/runtime/loggers/console_logger.h>

#include <std/containers/vector.h>

