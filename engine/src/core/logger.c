#include "asserts.h"
#include "logger.h"

// TODO: Temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line) {
    log_output(LOG_LEVEL_FATAL, "Assertion failed: %s, message: %s, in file: %s, line: %d\n", expression, message, file, line);
}

b8 initialize_logging() {
    // TODO: Create log file
    return TRUE;
}

void shutdown_logging() {
    // TODO: Cleanup logging/write queued entries
}

void log_output(Log_Level level, const char *fmt_str, ...) {
    static const char *log_level_str[] = {
        "FATAL",
        "ERROR",
        "WARN",
        "INFO",
        "DEBUG",
        "TRACE",
    };
    //b8 is_error = level < 2;

    char message[32000];
    va_list arg_ptr;
    va_start(arg_ptr, fmt_str);
    vsnprintf(message, 32000, fmt_str, arg_ptr);
    va_end(arg_ptr);

    printf("[%s] %s", log_level_str[level], message);
}
