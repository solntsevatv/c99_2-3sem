#include "../inc/const_errors.h"
#include "../inc/input.h"
#include "../inc/linked_list.h"

#define CONTINUE 0
#define END 1

int read_ordinary_line(char *s, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != '\r' \
        && ch != EOF && i < n - 1 && ch != '\0')
        s[i++] = ch;
    s[i] = '\0';
    return i;
}

args read_arg(status_codes *code)
{
    args key = out;
    char arg[ARG_SIZE + 1 + 1];
    if (read_ordinary_line(arg, ARG_SIZE + 1 + 1) != ARG_SIZE)
        *code = reading_arg_error;
    
    if (strcmp(arg, OUT) == 0)
        key = out;
    else if (strcmp(arg, CAT) == 0)
        key = cat;
    else if (strcmp(arg, POS) == 0)
        key = pos;
    else if (strcmp(arg, SPS) == 0)
        key = sps;
    else
        *code = reading_arg_error;
    
    return key;
}

int read_for_list_line(char **substr, int size, int *position, status_codes *code)
{
    *substr = malloc(size * sizeof(char));
    if (*substr == NULL)
        *code = memory_error;

    int ch, i = 0;
    while (i < size && (ch = getchar()) != '\n' && ch != '\r' \
        && ch != EOF && ch != '\0')
        (*substr)[i++] = ch;
    if (i < size)
    {
        (*substr)[i++] = '\0';
        *position = END;
    }
    return i;
}

void read_list(node_t **list, status_codes *code)
{
    char *substr = NULL;
    
    int n = -1, position = CONTINUE;
    while (*code == ok && (n = read_for_list_line(&substr, SUBSTR_SIZE, &position, code)) == SUBSTR_SIZE \
        && position != END)
    {
        *code = add_el_list(list, substr);
        if (*code != ok && substr)
            free(substr);
        n = -1;
    }

    if (*code == ok && n > 0)
        *code = add_el_list(list, substr);
    else if (*code == ok && substr)
        free(substr);
    
    if (*code == ok && (list_is_empty(*list) || (substr = (*list)->data)[0] == '\0'))
        *code = empty_string;
}