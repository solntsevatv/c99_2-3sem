#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

status_codes add_el_list(node_t **list, void *elem);
int list_is_empty(node_t *list);
void clean_list(node_t **list);
void *pop_front(node_t **list);
void *pop_back(node_t **stack_l);
node_t *reverse(node_t *head);
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
int cmp_int_elems(const int *elem_1, const int *elem_2);

#endif