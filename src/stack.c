#include "stack.h"
#include "linked_list.h"
#include "node.h"
#include <stdlib.h>


stack_t *stack_create(){
	stack_t *stack = (stack_t *) malloc(sizeof(stack_t));
	stack->list = linked_list_create();
	return stack;
}

void stack_push(stack_t *stack, int value){
	linked_list_prepend(stack->list, value);
}

node_t *stack_pop(stack_t *stack){
	if(stack == NULL) return  NULL;
	if(stack->list == NULL) return NULL;
	node_t *node = stack->list->head;
	linked_list_remove_first(stack->list);
	return node;
}

node_t *stack_peek(stack_t *stack){
	if(stack == NULL) return NULL;
	if(stack->list == NULL) return NULL;
	
	return stack->list->head;
}


size_t stack_length(stack_t *stack){
	return stack->list->length;
}

void stack_destroy(stack_t *stack){
	linked_list_destroy(stack->list);
	free(stack);
}

