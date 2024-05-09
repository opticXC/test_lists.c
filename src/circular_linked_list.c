#include "circular_linked_list.h"
#include "linked_list.h"
#include "node.h"
#include <stdlib.h>

linked_list_t *circular_linked_list_create() {
	linked_list_t *list = malloc(sizeof(linked_list_t));
	if (list != NULL) {
		list->head = list->tail = NULL;
		list->length = 0;
	}
	return list;
};

void circular_linked_list_destroy(linked_list_t *list) {
	if (list == NULL) return;
	node_t *tmp = list->head;
	while (tmp != NULL) {
		circular_linked_list_remove_first(list);
		destroy_node(tmp);
		tmp = list->head;
	}
	free(list);
}

void circular_linked_list_append(linked_list_t *list, int data) {
	if (list == NULL) return;
    node_t *node = create_node(data);
    if(node == NULL) return;

    if(list->head == NULL){
        list->head = list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }

    node->next = list->head;
    list->length++;
}


void circular_linked_list_prepend(linked_list_t *list, int data){
    if(list == NULL) return;

    node_t *node = create_node(data);
    if(node == NULL) return;

    if(list->head == NULL){
        list->head = list->tail = node;
    }else{
        list->tail->next = node;    
    }
    
    node->next = list->head;
    list->head = node;
    list->length++;
}

void circular_linked_list_insert(linked_list_t *list, int data, size_t index){
    if (list == NULL) return;

    if(list->length == 0 || index >= list->length){
        circular_linked_list_append(list, data);
        return;
    }
    if(index == 0){
        circular_linked_list_prepend(list, data);
        return;
    }

    node_t *node = create_node(data);
    if(node == NULL) return;
    node_t *tmp = list->head;
    for(size_t idx = 0; idx < index ; idx++){
        tmp = tmp->next;
    }
    node->next = tmp->next;
    tmp->next = node;
    list->length++;
}

void circular_linked_list_remove_first(linked_list_t *list){
    if(list == NULL || list->head == NULL) return;


    node_t *tmp = list->head;
    list->tail->next = list->tail;
    list->head = tmp->next;
    list->length --;

    if(list->length == 0){
        list->head = list->tail = NULL;
    }

    free(tmp);
}


void circular_linked_list_remove_last(linked_list_t *list){
    if(list == NULL || list->head == NULL) return;

    node_t *tmp = list->head;
    while (tmp->next != list->tail) {
        tmp = tmp->next;
    }
    free(tmp->next);
    
    tmp->next = list->head;
    list->tail = tmp;

    list->length--;
    if(list->length == 0){
        list->head = list->tail = NULL;
    }
}

void circular_linked_list_remove_at(linked_list_t *list, size_t index){
    if(list == NULL) return;
    if(index >= list->length) return;

    node_t *current = list->head;
    for(size_t i=0; i<index-1; i++){
        current = current->next;
    }
    node_t *tmp = current->next;
    current->next = tmp->next;

    if(list->head == list->tail){
        list->head = list->tail = NULL;
    }else if(tmp == list->head){
        list->head = tmp->next;   
    } else if(tmp == list->tail){
        list->tail = current;
    }

    free(tmp);
    list->length--;
}

void circular_linked_list_sort(linked_list_t *list);
void circular_linked_list_reverse(linked_list_t *list);
void circular_linked_list_merge(linked_list_t *list1, linked_list_t *list2);

linked_list_t *circular_linked_list_copy(linked_list_t *list);


node_t *circular_linked_list_search(linked_list_t *list, int data){
    if(list == NULL) return  NULL;
    if(list->head == NULL) return  NULL;

    node_t *current = list->head;
    do{
        if(current->data == data){
            return  current;
        }
        current = current->next;
    }while(current->next != list->head);

    return NULL;
}