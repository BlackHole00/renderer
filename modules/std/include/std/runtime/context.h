/**
 * @module STD
 * @file modules/std/include/std/runtime/context.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <std/lang/types.h>
#include <std/runtime/slice.h>
#include <std/runtime/logger.h>
#include <std/runtime/allocator.h>

typedef struct {
	Allocator allocator;
	Allocator temp_allocator;
	Allocator global_allocator;
	Logger logger;
} Context;

#define context_log(...)   context_log_ex   (sourcecodelocation_current(), __VA_ARGS__)
#define context_fatal(...) context_fatal_ex (sourcecodelocation_current(), __VA_ARGS__)
#define context_error(...) context_error_ex (sourcecodelocation_current(), __VA_ARGS__)
#define context_warn(...)  context_warn_ex  (sourcecodelocation_current(), __VA_ARGS__)
#define context_info(...)  context_info_ex  (sourcecodelocation_current(), __VA_ARGS__)
#define context_debug(...) context_debug_ex (sourcecodelocation_current(), __VA_ARGS__)
#define context_trace(...) context_trace_ex (sourcecodelocation_current(), __VA_ARGS__)

static inline void context_log_ex(SourceCodeLocation location, Context* context, LogLevel level, rawstring format, va_list args) {
	logger_log_ex(location, context->logger, level, format, args);
}
static inline STD_PRINTF_LIKE(3, 4) void context_fatal_ex(SourceCodeLocation location, Context* context, rawstring format, ...) {
	va_list args;
	va_start(args, format);

	logger_log_ex(location, context->logger, LOG_LEVEL_FATAL, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void context_error_ex(SourceCodeLocation location, Context* context, rawstring format, ...) {
	if (context->logger.minimum_log_level > LOG_LEVEL_ERROR) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, context->logger, LOG_LEVEL_ERROR, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void context_warn_ex(SourceCodeLocation location, Context* context, rawstring format, ...) {
	if (context->logger.minimum_log_level > LOG_LEVEL_WARN) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, context->logger, LOG_LEVEL_WARN, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void context_info_ex(SourceCodeLocation location, Context* context, rawstring format, ...) {
	if (context->logger.minimum_log_level > LOG_LEVEL_INFO) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, context->logger, LOG_LEVEL_INFO, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void context_debug_ex(SourceCodeLocation location, Context* context, rawstring format, ...) {
	if (context->logger.minimum_log_level > LOG_LEVEL_DEBUG) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, context->logger, LOG_LEVEL_DEBUG, format, args);

	va_end(args);
}
static inline STD_PRINTF_LIKE(3, 4) void context_trace_ex(SourceCodeLocation location, Context* context, rawstring format, ...) {
	if (context->logger.minimum_log_level > LOG_LEVEL_TRACE) {
		return;
	}

	va_list args;
	va_start(args, format);

	logger_log_ex(location, context->logger, LOG_LEVEL_TRACE, format, args);

	va_end(args);
}

static inline void context_logger_flush(Context* context) {
	logger_flush(context->logger);
}

