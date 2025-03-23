#pragma once

void assert_failed(const char *condition, const char *function, const char *file, int line);

#define ASSERT(condition)                                                \
    do                                                                   \
    {                                                                    \
        if (!(condition))                                                \
        {                                                                \
            assert_failed(#condition, __FUNCTION__, __FILE__, __LINE__); \
        }                                                                \
    } while (false)
