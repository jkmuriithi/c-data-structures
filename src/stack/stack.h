/**
 * @file stack.h
 * @author Jude K. Muriithi (GitHub: jkmuriithi)
 * @brief Declarations for the stack data structure.
 */

#ifndef C_GEN_STACK_H
#define C_GEN_STACK_H

#include <stdbool.h>
#include <stddef.h>

struct Stack;

/**
 * Generic stack data structure, designed to hold data in void pointer form.
 * A pointer to a properly allocated stack will never be NULL.
 */
typedef struct Stack Stack;

/**
 * Creates a new stack pointer. If memory cannot be allocated, the returned
 * pointer will be NULL. Must be destroyed before program termination using
 * Stack_destroy.
 */
Stack* Stack_create(void);

/**
 * Returns the number of items currently held in stack *s. Returns 0 if s is
 * NULL.
 */
size_t Stack_count(Stack* s);

/** Returns true if s points to an empty stack or is NULL. */
bool Stack_empty(Stack* s);

/**
 * Pushes an item onto stack *s. Returns true if the operation was successful,
 * and false if the operation was unsuccessful. Returns false if s is NULL.
 */
bool Stack_push(Stack* s, void* entry);

/**
 * Retrieves the item at the top of stack *s. Returns NULL if the stack is
 * empty, or if s is NULL.
 */
void* Stack_pop(Stack* s);

/**
 * Destroys the stack pointed to by s. If s is NULL, no operation is
 * performed.
 */
void Stack_destroy(Stack* s);

#endif
