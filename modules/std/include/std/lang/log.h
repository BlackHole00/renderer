#pragma once

#include <std/macro/macros.h>
#include <std/lang/source_code_location.h>
#include <std/runtime/logger.h>
#include <std/runtime/context.h>

#define log_fatal(...) _Generic(STD_GET_FIRST_VA_ARGS(__VA_ARGS__), \
	Context*: context_fatal_ex, \
	Logger: logger_fatal_ex \
)(sourcecodelocation_current(), __VA_ARGS__)
#define log_error(...) _Generic(STD_GET_FIRST_VA_ARGS(__VA_ARGS__), \
	Context*: context_error_ex, \
	Logger: logger_error_ex \
)(sourcecodelocation_current(), __VA_ARGS__)
#define log_warn(...) _Generic(STD_GET_FIRST_VA_ARGS(__VA_ARGS__), \
	Context*: context_warn_ex, \
	Logger: logger_warn_ex \
)(sourcecodelocation_current(), __VA_ARGS__)
#define log_info(...) _Generic(STD_GET_FIRST_VA_ARGS(__VA_ARGS__), \
	Context*: context_info_ex, \
	Logger: logger_info_ex \
)(sourcecodelocation_current(), __VA_ARGS__)
#define log_debug(...) _Generic(STD_GET_FIRST_VA_ARGS(__VA_ARGS__), \
	Context*: context_debug_ex, \
	Logger: logger_debug_ex \
)(sourcecodelocation_current(), __VA_ARGS__)
#define log_trace(...) _Generic(STD_GET_FIRST_VA_ARGS(__VA_ARGS__), \
	Context*: context_trace_ex, \
	Logger: logger_trace_ex \
)(sourcecodelocation_current(), __VA_ARGS__)

#define log_flush(...) _Generic(__VA_ARGS__,  \
	Context*: context_logger_flush, \
	Logger: logger_flush \
)(__VA_ARGS__)

