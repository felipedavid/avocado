#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED  1
#define LOG_INFO_ENABLED  1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if AV_RELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN  = 2,
    LOG_LEVEL_INFO  = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5,
} Log_Level;

b8 initialize_logging();
void shutdown_logging();

AV_API void log_output(Log_Level level, const char *message, ...);

#define AV_FATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, __VA_ARGS__);
#define AV_ERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, __VA_ARGS__);

#if LOG_WARN_ENABLED == 1
#define AV_WARN(message, ...) log_output(LOG_LEVEL_WARN, message, __VA_ARGS__);
#else
// If the log level is not enabled, do nothing
#define AV_WARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
#define AV_INFO(message, ...) log_output(LOG_LEVEL_INFO, message, __VA_ARGS__);
#else
// If the log level is not enabled, do nothing
#define AV_INFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
#define AV_DEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, __VA_ARGS__);
#else
// If the log level is not enabled, do nothing
#define AV_DEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
#define AV_TRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, __VA_ARGS__);
#else
// If the log level is not enabled, do nothing
#define AV_TRACE(message, ...)
#endif
