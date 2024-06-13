#include "node.h"
#include <stdlib.h>

node_t *create_node(int data){
	node_t *node = (node_t *) malloc(sizeof(node_t));
	node->data = data;
	node->next = NULL;
	return node;
}

void destroy_node(node_t *node){
	free(node);
}
