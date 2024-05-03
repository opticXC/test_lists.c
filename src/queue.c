#include "queue.h"

#include <stdlib.h>
#include "linked_list.h"



queue_t* queue_create(){
	queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
	queue->list = linked_list_create();
	return queue;
}

void queue_destroy(queue_t* queue){
	linked_list_destroy(queue->list);
	free(queue);
}

void queue_enqueue(queue_t* queue, int data){
	linked_list_append(queue->list, data);
}

int queue_dequeue(queue_t* queue){
	node_t *head = queue->list->head;
	int data = head->data;
	linked_list_remove_first(queue->list);
	return data;
}

int queue_peek(queue_t* queue){
	return queue->list->head->data;
}

size_t queue_length(queue_t* queue){
	return queue->list->length;
}

int queue_is_empty(queue_t* queue){
	return queue->list->length == 0;
}
