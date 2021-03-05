#include "../inc/const_errors.h"
#include "../inc/linked_list.h"
#include "../inc/output.h"

void print_list(node_t *list)
{
    node_t *curr = list;
    char *substr;
    int i = 0;

    while (curr != NULL)
    {
        substr = curr->data;
        while (i < SUBSTR_SIZE && substr[i] != '\0')
        {
            printf("%c", substr[i]);
            i++;
        }
        curr = curr->next;
        i = 0;
    }
}