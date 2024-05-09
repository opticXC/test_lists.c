#pragma once

#include "linked_list.h"
#include "stdlib.h"

typedef struct Queue {
	linked_list_t *list;
} queue_t;

queue_t *queue_create();
void queue_destroy(queue_t *queue);

void queue_enqueue(queue_t *queue, int data);
node_t *queue_dequeue(queue_t *queue);
node_t *queue_peek(queue_t *queue);
size_t queue_length(queue_t *queue);

int queue_is_empty(queue_t *queue);
