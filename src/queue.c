#include "queue.h"

#include <stdlib.h>
#include "linked_list.h"

queue_t* queue_create(){
	queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
	queue->list = linked_list_create();
	return queue;
}

void queue_destroy(queue_t* queue){
	if(queue == NULL) return;
	linked_list_destroy(queue->list);
	free(queue);
}

void queue_enqueue(queue_t* queue, int data){
	if(queue == NULL) return;
	linked_list_append(queue->list, data);
}

node_t *queue_dequeue(queue_t* queue){
	if(queue == NULL || queue->list == NULL) return NULL;
	node_t *head = queue->list->head;
	linked_list_remove_first(queue->list);
	return head;
}

node_t *queue_peek(queue_t* queue){
	if (queue == NULL || queue->list == NULL) return NULL;
	return queue->list->head;
}

size_t queue_length(queue_t* queue){
	return queue->list->length;
}

int queue_is_empty(queue_t* queue){
	return queue->list->length == 0;
}
