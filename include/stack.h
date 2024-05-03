#pragma once

#include "linked_list.h"
#include "node.h"
#include <stdlib.h>

typedef struct Stack {
	linked_list_t *list;
} stack_t;

stack_t *stack_create();

void stack_push(stack_t *stack, int value);
node_t *stack_pop(stack_t *stack);
node_t *stack_peek(stack_t *stack);
size_t stack_length(stack_t *stack);

void stack_destroy(stack_t *stack);
