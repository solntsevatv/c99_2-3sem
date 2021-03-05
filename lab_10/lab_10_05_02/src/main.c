#include "../inc/const_errors.h"
#include "../inc/linked_list.h"
#include "../inc/output.h"
#include "../inc/input.h"
#include "../inc/string_func.h"

int main(void)
{
    setbuf(stdout, NULL);
    args arg;
    node_t *row_1 = NULL, *row_2 = NULL, *res_row = NULL;
    status_codes code = ok;
    int res_ind = -1;

    // input
    arg = read_arg(&code);
    if (code == ok)
    {
        read_list(&row_1, &code);
        if (arg == cat || arg == pos)
            read_list(&row_2, &code);
    }

    // processing
    if (code != ok);
    else if (arg == cat)
        code = concatenation(row_1, row_2, &res_row);
    else if (arg == pos)
        res_ind = find_substring(row_1, row_2);
    else if (arg == sps)
        delete_spases(&row_1);

    if (code == ok && (arg == sps || arg == out))
    {
        res_row = row_1;
        row_1 = NULL;
    }

    // output
    if (code == ok && arg == pos)
        printf("%d", res_ind);
    else if (code == ok)
        print_list(res_row);
    

    // очистка памяти
    clean_list(&row_1);
    clean_list(&row_2);
    clean_list(&res_row);

    return code;
}