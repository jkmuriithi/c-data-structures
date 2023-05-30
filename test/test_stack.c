/**
 * @file test_stack.c
 * @author Jude K. Muriithi (GitHub: jkmuriithi)
 * @brief Unit tests for the default stack implementation.
 */

#include <stdio.h>
#include <stdlib.h>

#include "testutils.h"
#include "../src/stack/stack.h"

typedef struct Tester {
    char c;
} Tester;

// Dummy data
Tester t[] = {
    { 'a' },
    { 'b' },
    { 'c' },
    { 'd' },
    { 'e' },
    { 'f' }
};

int main(void) {
    // Stack_create
    Stack* s = Stack_create();
    errif(s == NULL, "unable to create stack");

    // Stack_count
    errif(Stack_count(NULL) != 0, "Stack_count of NULL is not 0");
    errif(Stack_count(s) != 0, "Stack_count of an empty stack is not 0");

    // Stack_empty
    errif(!Stack_empty(NULL), "Stack_empty of NULL is not true");
    errif(!Stack_empty(s), "Stack_empty of an empty stack is not true");

    // General stack operations
    errif(Stack_peek(NULL) != NULL, "Stack_peek on NULL is not NULL");
    errif(Stack_peek(s) != NULL, "Stack_peek on an empty stack is not NULL");

    for (int i = 0; i < 6; i++) {
        errif(!Stack_push(s, &t[i]), "Stack_push failure");
        errif(Stack_count(s) != i + 1, "Stack_count incorrect");
        errif(Stack_peek(s) != &t[i], "Stack_peek incorrect");
    }

    for (int i = 0; i < 6; i++) {
        Tester* peek = Stack_peek(s);
        Tester* pop = Stack_pop(s);
        errif(peek != pop, "Stack_peek and Stack_pop don't match");
        errif(pop != &t[6 - i - 1], "Stack_pop order incorrect");
        errif(Stack_count(s) != 6 - i - 1, "Stack_count incorrect");
    }

    errif(!Stack_empty(s), "Stack_empty of an empty stack is not true");
    errif(Stack_count(s) != 0, "Stack_count of an empty stack is not 0");

    // Stack_destroy
    Stack_destroy(NULL);
    Stack_destroy(s);

    printf("All tests passed.\n");
    exit(EXIT_SUCCESS);
}
