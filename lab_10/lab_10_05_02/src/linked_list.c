#include "../inc/const_errors.h"
#include "../inc/linked_list.h"

int list_is_empty(node_t *list)
{
    boolean check = false;

    if (list == NULL || list->data == NULL)
        check = true;

    return check;
}

status_codes add_el_list(node_t **list, void *elem)
{
    status_codes code = ok;

    node_t *new_list = malloc(sizeof(node_t));
    if (new_list == NULL)
        code = memory_error;

    if (code == ok && list_is_empty(*list))
    {
        new_list->data = elem;
        new_list->next = NULL;
        (*list) = new_list;
    }
    else if (code == ok)
    {
        node_t *curr = *list;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new_list;
        new_list->data = elem;
        new_list->next = NULL;
    }

    return code;
}

void clean_node(node_t **node)
{
    if (*node)
    {
        if ((*node)->data != NULL)
            free((*node)->data);
        free(*node);
    }
}

void clean_list(node_t **list)
{
    while (!list_is_empty(*list))
    {
        node_t *curr = *list;
        *list = (*list)->next;
        clean_node(&curr);
    }
}
