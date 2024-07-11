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

// TODO(Vicix): Implement Color Codes
const rawstring* LOG_LEVEL_ESCAPE_COLORS = (const rawstring[]){
	[LOG_LEVEL_FATAL] = "",
	[LOG_LEVEL_ERROR] = "",
	[LOG_LEVEL_WARN]  = "",
	[LOG_LEVEL_INFO]  = "",
	[LOG_LEVEL_DEBUG] = "",
	[LOG_LEVEL_TRACE] = ""
};

// TODO(Vicix): Implement Color Codes
const rawstring LOG_DEFAULT_TEXT_ESCAPE_COLOR = "";

void logger_log_ex(SourceCodeLocation location, Logger logger, LogLevel level, rawstring format, va_list args) {
	if (level < logger.minimum_log_level) {
		return;
	}

	usize message_length = vsnprintf(nullptr, 0, format, args);
	
	Slice(byte) message = allocator_alloc(logger.allocator, message_length + 2);
	vsnprintf((char*)message.data, message_length + 1, format, args);

	logger.vtable->log(logger.logger_data, level, (rawstring)(message.data), location);

	allocator_dealloc(logger.allocator, message);
}
