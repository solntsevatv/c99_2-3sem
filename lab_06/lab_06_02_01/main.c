#include "const_errors.h"
#include "processing.h"
#include "output.h"
#include "input.h"

int main(int argc, char **argv)
{
    status_codes code = ok;
    struct thing object[MAX_ARR_LEN];
    FILE *f = NULL;
    int arr_size = 0;

    // ввод
    f = check_input(argc, &code, argv);
    if (code == ok)
    {
        code = read_array(f, object, &arr_size);
        fclose(f);
    }

    // обработка
    if (argc == 2 && code == ok)
        insertion_sort_array(arr_size, object);

    if (argc == 3 && strcmp(argv[2], "ALL") != 0)
    {
        char str_to_find[MAX_NAME_LEN + 1];
        strcpy(str_to_find, argv[2]);
        arr_size = form_array_of_found_objects(object, arr_size, str_to_find);
        if (arr_size <= 0)
            code = empty_output;
    }

    // вывод
    if (code == ok)
        print_objects(object, arr_size);

    return code;
}