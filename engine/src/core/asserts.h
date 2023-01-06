#pragma once

#include "defines.h"

#define AV_ASSERTIONS_ENABLED

#ifdef AV_ASSERTIONS_ENABLED
#if _MSV_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

AV_API void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line);

#define VA_ASSERT(expr) \
    {\
        if (!(expr)) {\
            report_assertion_failure(#expr, "", __FILE__, __LINE__);\
            debugBreak();\
        }\
    }

#define VA_ASSERT_MSG(expr, message) \
    {\
        if (!(expr)) {\
            report_assertion_failure(#expr, message, __FILE__, __LINE__);\
            debugBreak();\
        }\
    }

// There are some asserts that we only want to have on the debug build
#ifdef _DEBUG
#define VA_ASSERT_DEBUG(expr) \
    {\
        if (!(expr)) {\
            report_assertion_failure(#expr, "", __FILE__, __LINE__);\
            debugBreak();\
        }\
    }
#else
#define VA_ASSERT_DEBUG(expr)
#endif

// If assertions are disabled, map macros to nothing
#else
#define VA_ASSERT(expr)
#define VA_ASSERT_MSG(expr)
#define VA_ASSERT_DEBUG(expr)
#endif
