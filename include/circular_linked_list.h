#include "linked_list.h"


linked_list_t *circular_linked_list_create();
void circular_linked_list_destroy(linked_list_t *list);

void circular_linked_list_append(linked_list_t *list, int data);
void circular_linked_list_prepend(linked_list_t *list, int data);
void circular_linked_list_insert(linked_list_t *list, int data, size_t index);

void circular_linked_list_remove_first(linked_list_t *list);
void circular_linked_list_remove_last(linked_list_t *list);
void circular_linked_list_remove_at(linked_list_t *list, size_t index);


void circular_linked_list_sort(linked_list_t *list);
void circular_linked_list_reverse(linked_list_t *list);
void circular_linked_list_merge(linked_list_t *list1, linked_list_t *list2);

linked_list_t *circular_linked_list_copy(linked_list_t *list);

node_t *circular_linked_list_search(linked_list_t *list, int data);