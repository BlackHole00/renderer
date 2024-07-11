#pragma once

#include <std/lang/types.h>
#include <std/lang/descriptor.h>
#include <std/lang/mem.h>
#include <std/runtime/logger.h>

typedef Logger ConsoleLogger;
extern singleton ConsoleLogger singleton_of(ConsoleLogger);

ConsoleLogger consolelogger_make(LogLevel minimum_log_level, Allocator allocator);
