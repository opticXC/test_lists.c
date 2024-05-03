#include "priority_queue.h"
#include <stdlib.h>

priority_queue_t *priority_queue_create(){
	priority_queue_t *queue = (priority_queue_t *) malloc(sizeof(priority_queue_t));
	if (queue){
		queue->head = NULL;
		queue->tail = NULL;
	}
	return queue;
}

void priority_queue_enqueqe(priority_queue_t *queue, int data, int priority){
	if(queue == NULL) return;
	priority_node_t *node =  (priority_node_t *) malloc(sizeof(priority_node_t));
	if(node == NULL) return;

	node->data = data;
	node->priority = priority;
	if(queue->head == NULL){
		queue->head = queue->tail = node;
	}else{
		queue->tail->next = node;
		queue->tail = node;
	}
}

priority_node_t *priority_queue_dequeue(priority_queue_t *queue){
	if (queue == NULL) return  NULL;
	if (queue->head == NULL) return NULL;

	priority_node_t *prev = NULL;
	priority_node_t *max = queue->head;
	priority_node_t *current = queue->head;
	while (current->next != NULL) {
		if( current->next->priority > max->priority ){
			prev = current;
			max = current->next;
		}
		current = current->next;
	}
	if(max == queue->head){
		queue->head = max->next;
		return max;
	}
	if(max == queue->tail){
		queue->tail = prev;
	}
	prev->next = max->next;
	max->next = NULL;
	return  max;
}

priority_node_t *priority_queue_peek(priority_queue_t *queue){
	if(queue == NULL) return NULL;
	return queue->head;
}

priority_node_t *priority_queue_search(priority_queue_t *queue, int data){
	if(queue == NULL) return  NULL;

	priority_node_t *current = queue->head;

	while(current != NULL){
		if(current->data == data) return current;
		current = current->next;
	}

	return  NULL;
}

int priority_queue_length(priority_queue_t *queue){
	if(queue == NULL) return -1;
	int count = 0;
	priority_node_t *current = queue->head;
	while(current != NULL){
		count++;
		current =current->next;
	}
	return count;
}

void priority_queue_destroy(priority_queue_t *queue){
	if (queue == NULL) return;
	
	priority_node_t *current = priority_queue_dequeue(queue);
	while (current != NULL) {
		free(current);
		current = priority_queue_dequeue(queue);
	}
	free(queue);
}