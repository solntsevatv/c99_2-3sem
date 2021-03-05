#ifndef _STRING_FUNC_H_
#define _STRING_FUNC_H_

void delete_spases(node_t **source_str);
status_codes concatenation(node_t *str_1, node_t *str_2, node_t **res_row);
int find_substring(node_t *source_str, node_t *str_to_find);

typedef enum
{
    not_find,
    comparing,
    found,
} search_codes;

#endif