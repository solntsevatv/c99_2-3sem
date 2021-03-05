#include "../inc/const_errors.h"
#include "../inc/linked_list.h"
#include "../inc/output.h"
#include <string.h>

void print_list(node_t *list)
{
    if (list_is_empty(list))
    {
        printf("Stack is empty.");
        return;
    }

    node_t *curr = list;
    int *num;

    while (curr != NULL)
    {
        num = curr->data;
        printf("%d ", *num);
        curr = curr->next;
    }
}