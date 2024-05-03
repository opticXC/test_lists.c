#pragma once

typedef struct PNode {
	int priority;
	int data;
	struct PNode *next;
} priority_node_t;

typedef struct PQueue {
	priority_node_t *head;
	priority_node_t *tail;
} priority_queue_t;

priority_queue_t *priority_queue_create();
void priority_queue_destroy(priority_queue_t *queue);

void priority_queue_enqueqe(priority_queue_t *queue, int data, int priority);
priority_node_t *priority_queue_dequeue(priority_queue_t *queue);

priority_node_t *priority_queue_peek(priority_queue_t *queue);
priority_node_t *priority_queue_search(priority_queue_t *queue, int data);
int priority_queue_length(priority_queue_t *queue);