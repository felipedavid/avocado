#pragma once

#include "defines.h"

#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED

#if _MSC_VER
#include <intrin.h>
#define debug_break() __debugbreak()
#else
#define debug_break() __builtin_trap()
#endif

KAPI void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line);

#define KASSERT(expr) \
    { \
        if (!(expr)) { \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debug_break(); \
        } \
    }

#define KASSERT_MSG(expr, msg) \
    { \
        if (!(expr)) { \
            report_assertion_failure(#expr, msg, __FILE__, __LINE__); \
            debug_break(); \
        } \
    }

#ifdef _DEBUG
#define KASSERT_DEBUG(expr) \
    { \
        if (!(expr)) { \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debug_break(); \
        } \
    }
#else
#define KASSERT_DEBUG(expr) // Do nothing
#endif

#else

// If asserts are disabled, do nothing
#define KASSERT(expr)
#define KASSERT_MSG(expr, msg)
#define KASSERT_DEBUG(expr)

#endif
