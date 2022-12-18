#include "logger.h"
#include "asserts.h"

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 init_logging() {
    // TODO: create log file.
    return TRUE;
}

void shutdown_logging() {
    // TODO: cleanup logging/write queued entries.
}

static const char *lvl_strs[6] = {
    "FATAL",
    "ERROR",
    "WARN",
    "INFO",
    "DEBUG",
    "TRACE",
};

void log_output(Log_Level lvl, const char *message, ...) {
    b8 is_error = lvl < 2;

    char msg[32000];
    memset(msg, 0, sizeof(msg));

    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(msg, 32000, message, arg_ptr);
    va_end(arg_ptr);

    printf("[%s] %s\n", lvl_strs[lvl], msg);
}

void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line) {
    KFATAL("Assertion Failure %s, Message: '%s', in file: %s, line %d\n", expression, message, file, line);
}
