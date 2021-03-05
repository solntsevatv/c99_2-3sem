#include "../inc/const_errors.h"
#include "../inc/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int list_is_empty(node_t *list)
{
    int code = 0;

    if (list == NULL || list->data == NULL)
        code = 1;

    return code;
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

node_t *reverse(node_t *head)
{
    node_t *new_head = NULL;

    while (!list_is_empty(head))
        add_el_list(&new_head, pop_back(&head));
    
    return new_head;
}

void insert_between(node_t **prev, node_t **between, node_t *after)
{
    (*prev)->next = *between;
    (*between)->next = after;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (list_is_empty(element));
    else if (list_is_empty(*head))
    {
        *head = element;
        element->next = NULL;
    }
    else
    {
        node_t *prev = (*head);
        node_t *curr = prev->next;
        if (comparator(prev->data, element->data) > 0)
        {
            element->next = prev;
            *head = element;
        }
        else
        {
            while (curr != NULL && curr->next != NULL && comparator(curr->data, element->data) < 0)
            {
                curr = curr->next;
                prev = prev->next;
            }
            if (curr != NULL && comparator(curr->data, element->data) < 0)
                insert_between(&curr, &element, NULL);
            else
                insert_between(&prev, &element, curr);
        }
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *new_list = NULL;
    node_t *elem = NULL;
    while (!list_is_empty(head))
    {
        elem = head;
        head = head->next;
        sorted_insert(&new_list, elem, (int(*)(const void *, const void *)) comparator);
    }
    return new_list;
}

void *pop_back(node_t **list)
{
    void *el = NULL;

    if (list && !list_is_empty(*list))
    {
        node_t *curr = (*list)->next;
        node_t *prev = *list;

        while (curr && curr->next)
        {
            curr = curr->next;
            prev = prev->next;
        }
        
        if (!curr)
        {
            curr = prev;
            *list = NULL;
        }
        
        el = curr->data;
        prev->next = NULL;

        free(curr);
    }

    return el;
}

void *pop_front(node_t **list)
{
    void *el = NULL;

    if (list != NULL && !list_is_empty(*list))
    {
        el = (*list)->data;
        node_t *to_pop = *list;
        
        *list = (*list)->next;

        free(to_pop);
    }

    return el;
}

int cmp_int_elems(const int *elem_1, const int *elem_2)
{
    return *elem_1 - *elem_2;
}

void clean_list(node_t **list)
{
    while (!list_is_empty(*list))
    {
        node_t *curr = *list;
        *list = (*list)->next;
        if (curr->data != NULL)
            free(curr->data);
        free(curr);
    }
}