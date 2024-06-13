#pragma once

#include <stdlib.h>

typedef struct DoubleLinkedNode {
	struct DoubleLinkedNode *prev;
	int data;
	struct DoubleLinkedNode *next;
} double_linked_node_t;

typedef struct DoubleLinkedList {
	double_linked_node_t *head;
	double_linked_node_t *tail;

} double_linked_list_t;

double_linked_list_t *double_linked_list_create();
void double_linked_list_destroy(double_linked_list_t *list);

void double_linked_list_append(double_linked_list_t *list, int data);
void double_linked_list_prepend(double_linked_list_t *list, int data);
void double_linked_list_insert(double_linked_list_t *list, int data, size_t index);

void double_linked_list_remove_first(double_linked_list_t *list);
void double_linked_list_remove_last(double_linked_list_t *list);
void double_linked_list_remove_at(double_linked_list_t *list, size_t index);

void double_linked_list_sort(double_linked_list_t *list);
void double_linked_list_reverse(double_linked_list_t *list);
void double_linked_list_merge(double_linked_list_t *list1, double_linked_list_t *list2);

double_linked_list_t *double_linked_list_copy(double_linked_list_t *list);

double_linked_node_t *double_linked_list_get_node(double_linked_list_t *list, size_t index);
double_linked_node_t *double_linked_list_search(double_linked_list_t *list, int data);