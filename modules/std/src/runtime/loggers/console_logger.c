#include <std/runtime/loggers/console_logger.h>

#include <stdio.h>

static void consolelogger_log(void*, LogLevel level, rawstring message, SourceCodeLocation location) {
	printf("[%s%s%s] %s:%lu\t: %s\n", 
		LOG_LEVEL_ESCAPE_COLORS[level], 
		LOG_LEVEL_NAMES[level], 
		LOG_DEFAULT_TEXT_ESCAPE_COLOR, 
		location.function, 
		location.line, 
		message
	);
}

static void consolelogger_flush(void*) {
	fflush(stdout);
}

static auto singleton_of(vtable_of(ConsoleLogger)) = (vtable_of(Logger)){
	.log = consolelogger_log,
	.flush = consolelogger_flush
};

ConsoleLogger consolelogger_make(LogLevel minimum_log_level, Allocator temp_allocator) {
	return (ConsoleLogger){
		.minimum_log_level = minimum_log_level,
		.temp_allocator = temp_allocator,
		.vtable = &singleton_of(vtable_of(ConsoleLogger))
	};
}
