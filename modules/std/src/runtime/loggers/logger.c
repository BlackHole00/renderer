#include <std/runtime/logger.h>

#include <stdio.h>

const rawstring* LOG_LEVEL_NAMES = (const rawstring[]){
	[LOG_LEVEL_FATAL] = "FATAL",
	[LOG_LEVEL_ERROR] = "ERROR",
	[LOG_LEVEL_WARN]  = " WARN",
	[LOG_LEVEL_INFO]  = " INFO",
	[LOG_LEVEL_DEBUG] = "DEBUG",
	[LOG_LEVEL_TRACE] = "TRACE"
};

const rawstring* LOG_LEVEL_ESCAPE_COLORS = (const rawstring[]){
	[LOG_LEVEL_FATAL] = "\033[31m",
	[LOG_LEVEL_ERROR] = "\033[91m",
	[LOG_LEVEL_WARN]  = "\033[93m",
	[LOG_LEVEL_INFO]  = "\033[36m",
	[LOG_LEVEL_DEBUG] = "\033[90m",
	[LOG_LEVEL_TRACE] = "\033[37m"
};

const rawstring LOG_DEFAULT_TEXT_ESCAPE_COLOR = "\033[0m";

void logger_log_ex(SourceCodeLocation location, Logger logger, LogLevel level, rawstring format, va_list args) {
	if (level < logger.minimum_log_level) {
		return;
	}

	usize message_length = vsnprintf(nullptr, 0, format, args);
	
	Slice(byte) message = allocator_alloc(logger.temp_allocator, message_length + 2);
	vsnprintf((char*)message.data, message_length + 1, format, args);

	logger.vtable->log(logger.logger_data, level, (rawstring)(message.data), location);
}
