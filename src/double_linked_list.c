
#include "double_linked_list.h"
#include <complex.h>

double_linked_list_t *double_linked_list_create(){
	double_linked_list_t *list = (double_linked_list_t *) malloc(sizeof(double_linked_list_t));
	list->head = list->tail = NULL;
	return list;
}

void double_linked_list_destroy(double_linked_list_t *list){
	double_linked_node_t *head = list->head;
	while(head != NULL){
		double_linked_node_t *tmp = head;
		head = head->next;
		free(tmp);
	}
}

void double_linked_list_append(double_linked_list_t *list, int data){
	double_linked_node_t *node = (double_linked_node_t *) malloc(sizeof(double_linked_node_t));
	if(list->head == NULL){
		list->head = list->tail = node;
		node->prev = node->next = NULL;
	}else{
		node->prev = list->tail;
		list->tail->next = node;
		node->next = NULL;
		list->tail = node;
	}
	node->data = data;
}


void double_linked_list_prepend(double_linked_list_t *list, int data){
	double_linked_node_t *node = (double_linked_node_t *) malloc(sizeof(double_linked_node_t));
	if(list->head == NULL){
		list->head = list->tail = node;
		node->prev = node->next = NULL;
	}else{
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
		node->prev = NULL;
	}
	node->data = data;
}

void double_linked_list_insert(double_linked_list_t *list, int data, size_t index){
	if (list->head == NULL){
		double_linked_list_append(list, data);
		return;
	}

	double_linked_node_t *node = (double_linked_node_t *) malloc(sizeof(double_linked_node_t));
	double_linked_node_t *current = list->head;
	size_t idx = 0;
	while(idx < index-1 && current != NULL){
		current = current->next;
	}
	if(current == NULL){
		free(node);
		return;
	}

	node->prev = current;
	node->next = current->next;
	current->next->prev = node;
	current->next = node;
	node->data = data;
}

void double_linked_list_remove_first(double_linked_list_t *list){
	double_linked_node_t *head = list->head;
	if(head == NULL) return;
	if(head == list->tail){
		list->tail = NULL;
	}
	list->head = head->next;
	list->head->prev = NULL;
	free(head);
}

void double_linked_list_remove_last(double_linked_list_t *list){
	double_linked_node_t *tail = list->tail;
	if(tail == NULL) return;
	if(list->head == tail){
		list->head = NULL;
	}
	list->tail = tail->prev;
	list->tail->next = NULL;
	free(tail);
}

void double_linked_list_remove_at(double_linked_list_t *list, size_t index){
	if(index == 0) double_linked_list_remove_first(list);

	double_linked_node_t *current = list->head;
	for(size_t i = 0; i<=index && current != NULL; i++){
		current = current->next;
	}

	if(current == NULL) return;
	
	if(current->prev == NULL){
		double_linked_list_remove_first(list);
	}else if(current->next == NULL){
		double_linked_list_remove_last(list);
	}else{
		double_linked_node_t *tmp = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(tmp);
	}
}


void double_linked_list_sort(double_linked_list_t *list){
	list->head = list->head;
	
}

void double_linked_list_reverse(double_linked_list_t *list){
	double_linked_node_t *current = list->head;
	while(current != NULL){
		double_linked_node_t *tmp = current->next;
		current->next = current->prev;
		current->prev = tmp;

		if(current->prev == NULL){
			list->head = current;
		}
		if(current->next == NULL){
			list->tail = NULL;
		}
		current = tmp;
		
	}
}

void double_linked_list_merge(double_linked_list_t *list1, double_linked_list_t *list2){
	if(list1->head == NULL){
		list1->head = list2->head;
		list1->tail = list2->tail;
	}else{
		list1->tail->next = list2->head;
		list2->head->prev = list1->tail;
		list1->tail = list2 ->tail;
	}
}



double_linked_list_t *double_linked_list_copy(double_linked_list_t *list){
	double_linked_list_t *copy = double_linked_list_create();
	double_linked_node_t *current = list->head;
	while(current != NULL){
		double_linked_list_append(list, current->data);
	}
	return copy;
}

double_linked_node_t *double_linked_list_get_node(double_linked_list_t *list, size_t index){
	double_linked_node_t *current = list->head;
	for(size_t i = 0; i<= index && current != NULL; i++){
		current = current->next;
	}
	return current;
}

double_linked_node_t *double_linked_list_search(double_linked_list_t *list, int data){
	double_linked_node_t *node = NULL;
	double_linked_node_t *current = list->head;
	while (current != NULL ) {
		if(current->data == data){
			node = current;
			break;
		}
	}
	return  node;
}