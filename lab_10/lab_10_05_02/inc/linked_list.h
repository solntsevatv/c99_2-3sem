#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

status_codes add_el_list(node_t **list, void *elem);
int list_is_empty(node_t *list);
void clean_node(node_t **node);
void clean_list(node_t **list);
void *pop_back(node_t **stack_l);

#endif