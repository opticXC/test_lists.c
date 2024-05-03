#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>


void display(priority_queue_t *queue){
	if(priority_queue_length(queue) <=0 ){
		printf("Queue is empty\n");
		return;
	}

	priority_node_t *node = queue->head;
	while(node != NULL){
		printf(" (%d, %d) %s", node->data, node->priority, (node->next == NULL)? "": "->");
		node = node->next;
	}
	putchar('\n');
}

int main(){
	priority_queue_t *queue = priority_queue_create();
	priority_node_t *node = NULL;
	int data = 0, priority = 0;

	while (1) {
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
			printf("Enter data: ");
			scanf("\n%d", &data);
			printf("Enter Priority: ");
			scanf("\n%d", &priority);
			priority_queue_enqueqe(queue, data, priority);
		}else if (op == 2){
			node = priority_queue_dequeue(queue);
			if(node != NULL) printf("Dequed: (%d, %d)\n", node->data, node->priority);
			else printf("Queue is empty\n");
			free(node);

		}else if (op == 3){
			node = priority_queue_peek(queue);
			if(node != NULL) printf("Peeked: (%d, %d)\n", node->data, node->priority);
			else printf("Queue is empty\n");
		}else if (op == 4){
			printf("Lenght of Queue: %d\n", priority_queue_length(queue));
		}else if (op == 5){
			display(queue);
			
		}else if (op == 6){
			break;
		}
		printf("Press enetr to continue...");
		while(  (op = getchar()) != '\n' && op != EOF);
		getchar();
	}
	priority_queue_destroy(queue);
}