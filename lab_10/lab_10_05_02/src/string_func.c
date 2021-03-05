#include "../inc/const_errors.h"
#include "../inc/string_func.h"
#include "../inc/linked_list.h"

void left_shift(node_t **source_str)
{
    char *curr_substr = (*source_str)->data;
    int ind = 0, size = strnlen(curr_substr, SUBSTR_SIZE);
    for (int i = 0; i < size - 1; i++)
        if (curr_substr[i] == ' ' && curr_substr[i + 1] == ' ')
            ind = i;
    
    for (int i = ind; i < size - 1; i++)
        curr_substr[i] = curr_substr[i + 1];
    curr_substr[size - 1] = '\0';
    
    (*source_str)->data = curr_substr;
}

void check_for_empty_nodes(node_t **source_str)
{
    node_t *curr = *source_str;
    char *curr_substr;

    node_t *node_to_delete = NULL;

    while (curr->next != NULL)
    {
        curr_substr = curr->next->data;
        if (curr_substr[0] == '\0')
        {
            node_to_delete = curr->next;
            curr->next = curr->next->next;
            clean_node(&node_to_delete);
        }

        if (curr->next != NULL)
            curr = curr->next;
    }
}

int find_spases(char *source_str, int max_size)
{
    boolean found = false;
    for (int i = 0; !found && i < max_size - 1 && source_str[i + 1] != '\0'; i++)
        if (source_str[i] == ' ' && source_str[i + 1] == ' ')
            found = true;
    return found;
}

int find_chr(char *source_str, int max_size, char chr)
{
    boolean found = false;
    for (int i = 0; !found && i < max_size && source_str[i] != '\0'; i++)
        if (source_str[i] == chr)
            found = true;
    return found;
}

void delete_spases(node_t **source_str)
{
    node_t *curr = (*source_str);
    char *substr;
    int last_sym_spase = 0;
    while (curr != NULL)
    {
        substr = curr->data;
        if (find_spases(substr, SUBSTR_SIZE))
        {
            while (find_spases(substr, SUBSTR_SIZE))
            {
                left_shift(&curr);
                substr = curr->data;
            }
        }

        if (last_sym_spase && substr[0] == ' ')
            left_shift(&curr);

        if (last_sym_spase && substr[0] != '\0')
            last_sym_spase = 0;
        
        if (find_chr(substr, SUBSTR_SIZE, ' ') && substr[strnlen(substr, SUBSTR_SIZE) - 1] == ' ')
            last_sym_spase = 1;

        curr = curr->next;
    }

    check_for_empty_nodes(source_str);
}

void copy_str(node_t *curr_node, status_codes *code, node_t **res_row)
{
    void *new_substr = NULL;
    while (curr_node != NULL && *code == ok)
    {
        new_substr = malloc(SUBSTR_SIZE * sizeof(char));
        if (!new_substr)
            *code = memory_error;
        else
        {
            memcpy(new_substr, curr_node->data, SUBSTR_SIZE);
            *code = add_el_list(res_row, new_substr);
            curr_node = curr_node->next;
        }
    }
}

status_codes concatenation(node_t *str_1, node_t *str_2, node_t **res_row)
{
    status_codes code = ok;
    
    copy_str(str_1, &code, res_row);
    copy_str(str_2, &code, res_row);

    return code;
}

node_t *to_next_substr(node_t *curr_node, char **curr_row)
{
    curr_node = curr_node->next;
    if (curr_node)
        *curr_row = curr_node->data;
    return curr_node;
}

int find_substring(node_t *str_node, node_t *str_to_find)
{
    node_t *stopped_node = str_node->next, *curr_find_node = str_to_find;
    char *source_row = str_node->data, *row_to_find = curr_find_node->data;
    int source_ind = 0, str_to_find_ind = 0, res_ind;

    search_codes flag = not_find;
    while (str_node != NULL && flag != found)
    {
        if (flag == not_find)
        {
            // check if the first symbol of str to find is in the source str
            // yes: change the flag, initialize source_ind, increase ind str_to_find
            for (int i = source_ind % SUBSTR_SIZE; i < SUBSTR_SIZE && str_to_find_ind == 0 && source_row[i] != '\0'; i++)
            {
                source_ind++;
                if (source_row[i] == row_to_find[str_to_find_ind])
                {
                    res_ind = source_ind - 1;
                    flag = comparing;
                    str_to_find_ind++;
                    stopped_node = str_node;
                }
            }
            //no: go to next substring
            if (str_to_find_ind == 0)
                str_node = to_next_substr(str_node, &source_row);
        }
        if (flag == comparing)
        {
            // go to next substr if it needed
            if (source_ind % SUBSTR_SIZE == 0 && str_node->next)
                str_node = to_next_substr(str_node, &source_row);
            if (str_to_find_ind % SUBSTR_SIZE == 0)
                curr_find_node = to_next_substr(curr_find_node, &row_to_find);

            if (row_to_find[str_to_find_ind % SUBSTR_SIZE] == '\0')
                flag = found;
            // if doesn't match
            else if (source_row[source_ind % SUBSTR_SIZE] != row_to_find[str_to_find_ind % SUBSTR_SIZE])
            {
                flag = not_find;
                source_ind = res_ind + 1;
                str_to_find_ind = 0;

                str_node = stopped_node;
                if (source_ind % SUBSTR_SIZE == 0)
                    str_node = stopped_node->next;

                if (str_node)
                    source_row = str_node->data;

                curr_find_node = str_to_find;
                row_to_find = curr_find_node->data;
            }
            // else increase indexes
            else
            {
                source_ind++;
                str_to_find_ind++;
            }
        }
    }

    if (flag != found)
        res_ind = -1;

    return res_ind;
}
