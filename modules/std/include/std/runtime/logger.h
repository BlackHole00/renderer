/**
 * @module STD
 * @file modules/std/include/std/runtime/logger.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <std/lang/types.h>
#include <std/lang/source_code_location.h>
#include <std/lang/vtable.h>
#include <std/runtime/allocator.h>

#include <stdarg.h>

#define STD_PRINTF_LIKE(FMT_ARG, FIRST_VA_ARG) __attribute__((__format__ (__printf__, FMT_ARG, FIRST_VA_ARG)))

typedef enum {
	LOG_LEVEL_FATAL = 5,
	LOG_LEVEL_ERROR = 4,
	LOG_LEVEL_WARN  = 3,
	LOG_LEVEL_INFO  = 2,
	LOG_LEVEL_DEBUG = 1,
	LOG_LEVEL_TRACE = 0
} LogLevel;

extern const rawstring* LOG_LEVEL_NAMES;
extern const rawstring* LOG_LEVEL_ESCAPE_COLORS;
extern const rawstring  LOG_DEFAULT_TEXT_ESCAPE_COLOR;

typedef void (*Logger_LogFn)(void* logger_data, LogLevel level, rawstring message, SourceCodeLocation location);
typedef void (*Logger_FlushFn)(void* logger_data);

typedef struct {
	Logger_LogFn log;
	Logger_FlushFn flush;
} vtable_of(Logger);

typedef struct {
	const vtable_of(Logger)* vtable;
	void* logger_data;
	TempAllocator temp_allocator;
	LogLevel minimum_log_level;
} Logger;

#define logger_log(...)   logger_log_ex   (sourcecodelocation_current(), __VA_ARGS__)
#define logger_fatal(...) logger_fatal_ex (sourcecodelocation_current(), __VA_ARGS__)
#define logger_error(...) logger_error_ex (sourcecodelocation_current(), __VA_ARGS__)
#define logger_warn(...)  logger_warn_ex  (sourcecodelocation_current(), __VA_ARGS__)
#define logger_info(...)  logger_info_ex  (sourcecodelocation_current(), __VA_ARGS__)
#define logger_debug(...) logger_debug_ex (sourcecodelocation_current(), __VA_ARGS__)
#define logger_trace(...) logger_trace_ex (sourcecodelocation_current(), __VA_ARGS__)

void logger_log_ex(SourceCodeLocation location, Logger logger, LogLevel level, rawstring format, va_list args);
static inline STD_PRINTF_LIKE(3, 4) void logger_fatal_ex(SourceCodeLocation location, Logger logger, rawstring format, ...) {
	va_list args;
	va_start(args, format);

	logger_log_ex(location, logger, LOG_LEVEL_FATAL, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void logger_error_ex(SourceCodeLocation location, Logger logger, rawstring format, ...) {
	if (logger.minimum_log_level > LOG_LEVEL_ERROR) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, logger, LOG_LEVEL_ERROR, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void logger_warn_ex(SourceCodeLocation location, Logger logger, rawstring format, ...) {
	if (logger.minimum_log_level > LOG_LEVEL_WARN) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, logger, LOG_LEVEL_WARN, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void logger_info_ex(SourceCodeLocation location, Logger logger, rawstring format, ...) {
	if (logger.minimum_log_level > LOG_LEVEL_INFO) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, logger, LOG_LEVEL_INFO, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void logger_debug_ex(SourceCodeLocation location, Logger logger, rawstring format, ...) {
	if (logger.minimum_log_level > LOG_LEVEL_DEBUG) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, logger, LOG_LEVEL_DEBUG, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void logger_trace_ex(SourceCodeLocation location, Logger logger, rawstring format, ...) {
	if (logger.minimum_log_level > LOG_LEVEL_TRACE) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, logger, LOG_LEVEL_TRACE, format, args);

	va_end(args);
}

static inline void logger_flush(Logger logger) {
	logger.vtable->flush(logger.logger_data);
}

