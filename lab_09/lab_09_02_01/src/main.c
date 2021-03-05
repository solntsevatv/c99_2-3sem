#include "../inc/const_errors.h"
#include "../inc/processing.h"
#include "../inc/output.h"
#include "../inc/input.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    status_codes code = ok;
    struct dyn_arr_objects data;
    init_dyn_array_objects(&data);
    FILE *f = NULL;

    // ввод
    f = check_input(argc, &code, argv);
    if (code == ok)
    {
        code = read_array(f, &data);
        fclose(f);
    }

    // обработка
    if (argc == 2 && code == ok)
        insertion_sort_array(&data);

    // вывод
    char *str_to_find = NULL;
    
    if (argc == 3 && strcmp(argv[2], "ALL") != 0)
        str_to_find = strdup(argv[2]);

    if (code == ok)
    {
        prepare_obj_to_print(&data, str_to_find);
        print_objects(data);
    }


    // очистка памяти
    for (int i = 0; data.objects != NULL && i < data.len; i++)
        clean_array(data.objects[i].name);
    clean_array(data.objects);
    clean_array(str_to_find);
        
    return code;
}