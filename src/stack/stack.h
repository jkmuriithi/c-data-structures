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
 * @brief Generic stack data structure, designed to hold data in void pointer
 * form. A pointer to a properly allocated stack will never be NULL.
 */
typedef struct Stack Stack;

/**
 * @brief Creates a new stack pointer. If memory cannot be allocated, the returned
 * pointer will be NULL. Must be destroyed before program termination using
 * Stack_destroy.
 */
Stack* Stack_create(void);

/**
 * @brief Returns the number of items currently held in stack *s. Returns 0 if s is
 * NULL.
 */
size_t Stack_count(Stack* s);

/** @brief Returns true if s points to an empty stack or is NULL. */
bool Stack_empty(Stack* s);

/**
 * @brief Pushes an item onto stack *s. Returns true if the operation was
 * successful, and false if either the operation was unsuccessful or s is NULL.
 */
bool Stack_push(Stack* s, void* entry);

/**
 * @brief Retrieves the item at the top of stack *s and removes it. Returns NULL
 * if the stack is empty, the operation was unsuccessful, or if s is NULL.
 */
void* Stack_pop(Stack* s);

/**
 * @brief Retrieves the item at the top of stack *s, but does not remove it.
 * Returns NULL if the stack is empty, or if s is NULL.
 */
void* Stack_peek(Stack* s);

/**
 * @brief Trims the size of a stack in memory down to its current length.
 * Returns true if the operation was successful. Returns false if the
 * operation was unsuccessful or if s is NULL. If an implementation enforces
 * some minimum memory allocation size, this function will return a stack of
 * at least that size in memory.
 */
bool Stack_trim(Stack* s);

/**
 * @brief Destroys the stack pointed to by s, freeing all memory allocated to
 * the structure. If s is NULL, no operation is performed.
 */
void Stack_destroy(Stack* s);

#endif
