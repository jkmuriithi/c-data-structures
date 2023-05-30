/**
 * @file test_stack.c
 * @author Jude K. Muriithi (GitHub: jkmuriithi)
 * @brief Unit tests for the default stack implementation.
 */

#include <stdio.h>
#include <stdlib.h>

#include "../src/stack/stack.h"

typedef struct Tester {
    char c;
} Tester;

int main(void) {
    printf("****** Stack Testing ******\n");

    // Stack_create
    printf("Creating stack...\n");
    Stack* s = Stack_create();
    if (s == NULL) {
        fprintf(stderr, "Error: unable to allocate stack\n");
        exit(EXIT_FAILURE);
    }
    printf("Created stack pointer address: %p\n", s);


    // Stack_destroy
    printf("Destroying stack...\n");
    Stack_destroy(s);

    printf("Running Stack_destroy(NULL)\n");
    Stack_destroy(NULL);
}
