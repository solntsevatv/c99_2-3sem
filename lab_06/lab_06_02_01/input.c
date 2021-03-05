#include "const_errors.h"
#include "input.h"

status_codes read_array(FILE *f, struct thing *object, int *n)
{
    status_codes code = ok;
    char ch = '\0';
    while (*n != MAX_ARR_LEN && code == ok && \
        fgets(object[*n].name, MAX_NAME_LEN + 1, f) != 0)
    {
        /// убираем перенос строки из object name
        size_t name_len = strlen(object[*n].name);
        if (object[*n].name[name_len - 1] == '\n' || object[*n].name[name_len - 1] == '\r')
            object[*n].name[name_len - 1] = '\0';

        /// проверка ввода массы и объема, не является ли имя пустой строкой
        if (fscanf(f, "%lf%lf", &object[*n].weight, &object[*n].size) == 2)
        {
            if (object[*n].weight > 0 && object[*n].size > 0 && \
                object[*n].name[0] != '\0')
            {
                *n = *n + 1;
                fscanf(f, "%c", &ch);
            }
            else
                code = incorrect_data;
        }
        else
            code = reading_error;
    }
    /// проверяем на преувеличение количества структур в массиве
    if (*n == MAX_ARR_LEN && fgets(object[*n].name, MAX_NAME_LEN + 1, f) != 0)
        code = reading_error;
    /// пустой ли файл?
    else if (*n == 0)
        code = size_error;
    return code;
}

FILE *check_input(int argc, status_codes *code, char **argv)
{
    FILE *f;
    if (argc == 2 || argc == 3)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            *code = file_not_transferred;
    }
    else
        *code = incorrect_input;
    return f;
}