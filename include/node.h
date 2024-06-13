#pragma once

typedef struct Node {
	int data;
	struct Node *next;
} node_t;

node_t *create_node(int data);
void destroy_node(node_t *node);