/**
 * @file stack.c
 * @author Jude K. Muriithi (GitHub: jkmuriithi)
 * @brief Default stack implementation using a dynamic array.
 */

#include <stdlib.h>

#include "stack.h"

#define C_GEN_STACK_DEFAULT_SIZE 10
#define C_GEN_STACK_GROWTH_FACTOR 1.5
#define C_GEN_STACK_MIN_SIZE 1

struct Stack {
    /** Number of items currently held by the stack. */
    size_t count;
    /** Holds stack items. */
    void** items;
    size_t items_len;
};

Stack* Stack_create(void) {
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) return NULL;

    s->count = 0;
    s->items_len = C_GEN_STACK_DEFAULT_SIZE;
    s->items = malloc(sizeof(void*) * C_GEN_STACK_DEFAULT_SIZE);
    if (s->items == NULL) {
        free(s);
        return NULL;
    }

    return s;
}

size_t Stack_count(Stack* s) {
    if (s == NULL) return 0;
    return s->count;
}

bool Stack_empty(Stack* s) {
    if (s == NULL) return true;
    return s->count == 0;
}

/**
 * @brief Resizes the item array of the stack pointed to by s. Returns false iff
 * the operation could not be completed successfully. Should not be called with
 * NULL s.
 */
static bool resize(Stack* s, size_t new_length) {
    void** new_alloc = realloc(s->items, new_length);
    if (new_alloc == NULL) return false;

    s->items = new_alloc;
    s->items_len = new_length;
    return true;
}

bool Stack_push(Stack* s, void* entry) {
    if (s == NULL) return false;

    // Grow items array if necessary
    if (s->count == s->items_len) {
        size_t new_length = (size_t) (s->items_len * C_GEN_STACK_GROWTH_FACTOR);
        if (new_length < s->items_len) return false; // Overflow check

        if (!resize(s, new_length)) return false;
    }

    s->items[s->count++] = entry;
    return true;
}

void* Stack_pop(Stack* s) {
    if (Stack_empty(s)) return NULL;
    return s->items[--s->count];
}

void* Stack_peek(Stack* s) {
    if (Stack_empty(s)) return NULL;
    return s->items[s->count - 1];
}

bool Stack_trim(Stack* s) {
    if (s == NULL) return false;

    // Trim down items array to max(MIN_SIZE, count)
    size_t new_length;
    if (s->count < C_GEN_STACK_MIN_SIZE) new_length = C_GEN_STACK_MIN_SIZE;
    else new_length = s->count;

    return resize(s, new_length);
}

void Stack_destroy(Stack* s) {
    free(s->items);
    free(s);
}
