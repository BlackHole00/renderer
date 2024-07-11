#include <std/runtime/loggers/console_logger.h>

#include <stdio.h>

static void consolelogger_log(void* logger_data, LogLevel level, rawstring message, SourceCodeLocation location) {
	// TODO(Vicix): implement colors and time
	printf("[%s] %s:%lu - %s\n", LOG_LEVEL_NAMES[level], location.function, location.line, message);
}

static void consolelogger_flush(void* logger_data) {
	fflush(stdout);
}

static auto singleton_of(vtable_of(ConsoleLogger)) = (vtable_of(Logger)){
	.log = consolelogger_log,
	.flush = consolelogger_flush
};

ConsoleLogger consolelogger_make(LogLevel minimum_log_level, Allocator allocator) {
	return (ConsoleLogger){
		.minimum_log_level = minimum_log_level,
		.allocator = allocator,
		.vtable = &singleton_of(vtable_of(ConsoleLogger))
	};
}
