#include "../inc/const_errors.h"
#include "../inc/input.h"
#include "../inc/processing.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

status_codes append_elem(struct dyn_arr_objects *data, struct thing object)
{
    status_codes code = ok;
    if (!data->objects)
    {
        code = object_create(INIT_SIZE, &data->objects);
        if (!data->objects)
            code = memory_error;
        data->allocated = INIT_SIZE;
    }
    else if (data->len >= data->allocated)
    {
        struct thing *tmp = realloc(data->objects, \
        data->allocated * data->step * sizeof(struct thing));
        if (!tmp)
            code = memory_error;
        else
        {
            data->objects = tmp;
            data->allocated *= data->step;
        }
    }

    if (code == ok)
    {
        data->objects[data->len] = object;
        data->len++;
    }
    return code;
}

status_codes read_array(FILE *f, struct dyn_arr_objects *data)
{
    status_codes code = ok;
    ssize_t read;
    size_t name_len = 5;
    char *start_read = NULL;
    struct thing object;
    object.name = NULL;

    /// создание строки
    code = create_str(name_len, &start_read);
    
    while (code == ok && (read = getline(&start_read, &name_len, f)) != -1)
    {
        /// ввод строки и удаление символа переноса строки
        object.name = strdup(start_read);
        if (object.name[read - 1] == '\r' || object.name[read - 1] == '\n')
            object.name[read - 1] = '\0';
        
        /// проверка ввода массы и объёма
        if (fscanf(f, "%lf%lf\n", &object.weight, &object.size) == 2)
        {
            if (object.weight > 0 && object.size > 0 && object.name[0] != '\0')
                code = append_elem(data, object);
            else
                code = incorrect_data;
        }
        else
            code = reading_error;
    }
    
    /// очистка памяти
    clean_array(start_read);
    if (code == incorrect_data || code == reading_error)
        clean_array(object.name);

    /// пустой ли файл?
    if (data->len == 0)
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