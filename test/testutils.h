/**
 * @file testutils.h
 * @author Jude K. Muriithi (GitHub: jkmuriithi)
 * @brief Time-saving macros for testing
 */

#ifndef C_GEN_TEST_TESTUTILS_H
#define C_GEN_TEST_TESTUTILS_H

#include <stdio.h>

#define errif(expr, message)                                        \
if (expr) {                                                         \
    fprintf(stderr, "Error: %s (line %u)\n", (message), __LINE__ ); \
    exit(EXIT_FAILURE);                                             \
}

#endif
