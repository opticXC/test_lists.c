#include "queue.h"
#include <stdio.h>


void print_queue(queue_t *queue){
	node_t *current = queue->list->head;
	while(current != NULL){
		printf("%-3s%d\n",(current == queue->list->head )? "h>": (current->next == NULL)? "t>": " "  , current->data);
		current = current->next;
	}
}

void stdin_clear(){
	char c;
	while((c = getchar() != '\n' ) && c != EOF );
}


int main(){
	queue_t *queue = queue_create();
	while(1){
		int op = 0;
		printf("\033[H\033[J");
		printf("1) Enqueue\n");
		printf("2) Dequeue\n");
		printf("3) Peek\n");
		printf("4) Length\n");
		printf("5) Print\n");
		printf("6) Exit\n");
		printf("Enter option: ");

		scanf("%d", &op);

		if(op == 1){
			int value;
			printf("Enter value: ");
			scanf("\n%d", &value);
			queue_enqueue(queue, value);
		}else if (op == 2){
			if(queue_length(queue) == 0){
				printf("Queue is empty\n");
			}else{
				printf("Dequeued value: %d\n", queue_dequeue(queue));
			}
		}else if (op == 3){
			if(queue_length(queue) == 0){
				printf("Queue is empty\n");
			}else{
				printf("Peeked value: %d\n", queue_peek(queue));
			}
		}else if (op == 4){
			printf("Lenght: %lu\n", queue_length(queue));
		}else if (op == 5){
			print_queue(queue);
		}else if (op == 6){
			break;
		}

		printf("Press enter to continue...");
		stdin_clear();
		getchar();

	}
	queue_destroy(queue);
	return 0;
}
