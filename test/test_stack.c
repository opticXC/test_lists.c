#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void display(stack_t *stk){
	if(stk->list->length == 0) {
		printf("Stack is empty\n");
		return;
	}
	node_t *current = stk->list->head;
	while(current != NULL){
		printf("%-3s%d\n",(current == stk->list->head)? ">": " " , current->data);
		current = current->next;
	}
}

int main(){
	stack_t *stk = stack_create();
	node_t *node = NULL;
	int data = 0, op = 0;
	while(1){
		printf("\033[H\033[J");
		printf("1) Push\n");
		printf("2) Pop\n");
		printf("3) Peek\n");
		printf("4) Length\n");
		printf("5) Print\n");
		printf("6) Exit\n");
		printf("Enter option: ");

		scanf("%d", &op);

		if(op == 1){
			printf("Enter value: ");
			scanf("\n%d", &data);
			stack_push(stk, data);
		}else if (op == 2){
			if(stack_length(stk) == 0){
				printf("Stack is empty\n");
			}else{
				node = stack_pop(stk);
				printf("Popped value: %d\n", node->data);
				free(node);
			}
		}else if (op == 3){
			if(stack_length(stk) == 0){
				printf("Stack is empty\n");
			}else{
				printf("Peeked value: %d\n", stack_peek(stk)->data);
			}
		}else if (op == 4){
			printf("Lenght: %lu\n", stack_length(stk));
		}else if (op == 5){
			display(stk);
		}else if (op == 6){
			break;
		}

		printf("Press enter to continue...");
		while( (op = getchar()) != '\n' && op != EOF );
		getchar();

	}
	stack_destroy(stk);
}