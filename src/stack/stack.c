/**
 * @file stack.c
 * @author Jude K. Muriithi (GitHub: jkmuriithi)
 * @brief Default stack implementation using a dynamic array.
 */

#include <stdlib.h>

#include "stack.h"

#define C_GEN_STACK_DEFAULT_SIZE 10

struct Stack {
    /**
     * Number of items currently on the stack. Doubles as a pointer to the
     * top of the stack.
     */
    size_t count;
    /** Holds stack items. */
    void** items;
    /** Length of **items. */
    size_t items_len;
};

Stack* Stack_create(void) {
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) return s;

    s->count = 0;
    s->items = malloc(sizeof(void*) * C_GEN_STACK_DEFAULT_SIZE);
    if (s->items == NULL) {
        free(s);
        return NULL;
    }
    s->items_len = C_GEN_STACK_DEFAULT_SIZE;

    return s;
}

size_t Stack_count(Stack* s) {
    if (s == NULL) return 0;
    else return s->count;
}

bool Stack_empty(Stack* s) {
    return Stack_count(s) == 0;
}


