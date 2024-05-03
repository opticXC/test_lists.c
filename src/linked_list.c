#include "linked_list.h"
#include "node.h"
#include <stdio.h>

linked_list_t *linked_list_create(){
	linked_list_t *list = (linked_list_t *) malloc(sizeof(linked_list_t));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void linked_list_destroy(linked_list_t *list){
	node_t *current = list->head;
	while(current != NULL){
		node_t *next = current->next;
		destroy_node(current);
		current = next;
	}
	free(list);
}

void linked_list_append(linked_list_t *list, int data){
	node_t *node = create_node(data);
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
	}else{
		list->tail->next = node;
		list->tail = node;
	}
	list->length++;
}

void linked_list_prepend(linked_list_t *list, int data){
	node_t *node = create_node(data);
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
	}else{
		node->next = list->head;
		list->head = node;
	}
	list->length++;
}


void linked_list_insert(linked_list_t *list, int data, size_t index){
	if(index == 0){
		linked_list_prepend(list, data);
	}else if(index >= list->length){
		linked_list_append(list, data);
	}else{
		node_t *current = list->head;
		for(size_t i = 0; i < index - 1; i++){
			current = current->next;
		}
		node_t *node = create_node(data);
		node->next = current->next;
		current->next = node;
		list->length++;
	}
}

void linked_list_remove_first(linked_list_t *list){
	if(list->head != NULL){
		node_t *node = list->head;
		list->head = list->head->next;
		destroy_node(node);
		list->length--;
	}
}

void linked_list_remove_last(linked_list_t *list){
	if(list->head != NULL){
		node_t *current = list->head;
		node_t *previous = NULL;
		while(current->next != NULL){
			previous = current;
			current = current->next;
		}
		if(previous == NULL){
			list->head = NULL;
			list->tail = NULL;
		}else{
			previous->next = NULL;
			list->tail = previous;
		}
		destroy_node(current);
	}
}
void linked_list_remove_at(linked_list_t *list, size_t index){
	if(index == 0){
		linked_list_remove_first(list);
	}else if(index == list->length - 1){
		linked_list_remove_last(list);
	}else if(index < list->length){
		node_t *current = list->head;
		node_t *previous = NULL;
		for(size_t i = 0; i < index; i++){
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		destroy_node(current);
		list->length--;
	}else{
		printf("[WARNING] [OUT OF BOUNDS INDEX] Element not removed\n");
	}
}


void linked_list_sort(linked_list_t *list){
	size_t length = list->length;
	for(size_t i =0; i<length; i++){
	
		for(size_t j = 0; j<length; j++){
			node_t *previous = linked_list_get_node(list, j-1);
			node_t *current = linked_list_get_node(list, j);
			node_t *next = current->next;

			if( next!=NULL && current->data > next->data){
				if(previous != NULL){
					previous->next = next;
				}else{
					list->head = next;
				}
				current->next = next->next;
				next->next = current;
			}
		}
	}
}

/*
void linked_list_quick_sort(linked_list_t *list){
	size_t length = list->length;
	size_t pivot_idx = length/2;

	node_t *pivot = linked_list_get_node(list, pivot_idx);
	for(size_t i =0; i<length; i++){
		node_t *previous = linked_list_get_node(list, i-1);
		node_t *current = linked_list_get_node(list, i);
	}
}
*/

void linked_list_reverse(linked_list_t *list){
	node_t *current = list->head;
	node_t *previous = NULL;
	node_t *next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	list->tail = list->head;
	list->head = previous;
}
void linked_list_merge(linked_list_t *list1, linked_list_t *list2){
	if(list1->head == NULL){
		list1->head = list2->head;
		list1->tail = list2->tail;
	}else if( list2->head != NULL){
		list1->tail->next = list2->head;
		list1->tail = list2->tail;
	}
}

linked_list_t *linked_list_copy(linked_list_t *list){
	linked_list_t *copy = linked_list_create();
	node_t *current = list->head;
	while(current != NULL){
		linked_list_append(copy, current->data);
		current = current->next;
	}
	return copy;
}

node_t *linked_list_get_node(linked_list_t *list, size_t index){
	if(index > list->length){
		printf("[WARNING] [OUT OF BOUNDS INDEX] Element not found\n");
		return NULL;
	}
	node_t *current = list->head;
	for(size_t i = 0; i < index; i++){
		current = current->next;
	}
	return current;
}

