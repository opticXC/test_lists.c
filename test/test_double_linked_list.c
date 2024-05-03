#include "double_linked_list.h"
#include <stdio.h>

void display_f(double_linked_list_t *list){
	double_linked_node_t *current = list->head;
	while (current!= NULL) {
		printf("%s%d%s", (current->prev != NULL) ? "<-" : "" , current->data, (current->next != NULL)? "->" : "" );
		current = current->next;
	}
	putchar('\n');
}

void display_r(double_linked_list_t *list){
	double_linked_node_t *current = list->tail;
	while (current!= NULL) {
		printf("%s%d%s", (current->next != NULL) ? "<-" : "" , current->data, (current->prev != NULL)? "->" : "" );
		current = current->prev;
	}
	putchar('\n');
}

void stdin_clear(){
	char c;
	while( (c = getchar()) != '\n' && c != EOF );
}

int main(){
	double_linked_list_t *list = double_linked_list_create();
	int data;
	double_linked_node_t *node = NULL;
	size_t index;
	while(1){
		int op = 0;
		printf("\033[H\033[J");
		printf("1) Insert in begining\n");
		printf("2) Insert at end\n");
		printf("3) Insert at any index\n");
		printf("4) Delete at index\n");
		printf("5) Search\n");
		printf("6) Print Forward\n");
		printf("7) Print Reverse\n");
		printf("8) Exit\n");
		printf("Enter option: ");
		scanf("\n%d", &op);

		if(op == 1){
			printf("Enter data: ");
			scanf("\n%d", &data);
			double_linked_list_prepend(list, data);
		}else if (op == 2){
			printf("Enter data: ");
			scanf("\n%d", &data);
			double_linked_list_append(list, data);
		}else if (op == 3){
			printf("Enter data: ");
			scanf("\n%d", &data);
			printf("Enter index: ");
			scanf("\n%lu", &index);
			double_linked_list_insert(list, data, index);
		}else if (op == 4){
			printf("Enter index to delete: ");
			scanf("\n%lu", &index);
			double_linked_list_remove_at(list,index);
		}else if (op == 5){
			printf("Enter value to search: ");
			scanf("\n%d", &data);
			node = double_linked_list_search(list, data);
			if(node != NULL){
				printf("Node with value %d found in list\n", data);
			}else{
				printf("Node not found\n");
			}
		}else if (op == 6){
			display_f(list);
		}else if (op == 7){
			display_r(list);
		}else if (op == 8){
			break;
		}
		printf("Press enter to continue...\n");
		stdin_clear();
		getchar();
	}

}