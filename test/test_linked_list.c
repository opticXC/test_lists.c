#include "linked_list.h"
#include <stdio.h>



void print_linked_list(linked_list_t *list){
	if(list == NULL || list->length == 0){
		printf("List is empty\n");
		return;
	}
	node_t *current = list->head;
	while(current != NULL){
		printf("%d%s", current->data, (current->next == NULL)? "\n": "->" );
		current = current->next;
	}
}

int main(){
	linked_list_t *list = linked_list_create();
	linked_list_append(list, 7);
	linked_list_append(list, 3);
	linked_list_append(list, 8);
	linked_list_append(list, 2);
	linked_list_append(list, 5);
	linked_list_append(list, 4);
	linked_list_insert(list, 1, 3);
	
	print_linked_list(list);

	linked_list_sort(list);
	print_linked_list(list);

	linked_list_reverse(list);
	print_linked_list(list);

	linked_list_destroy(list);
	
}
