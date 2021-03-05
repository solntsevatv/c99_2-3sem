#include "../inc/const_errors.h"
#include <stdlib.h>

void insertion_sort_array(struct dyn_arr_objects *data)
{
    int location;
    struct thing new_element;
    for (int i = 1; i < data->len; i++)
    {
        new_element = data->objects[i];
        location = i - 1;
        while (location >= 0 && data->objects[location].weight / data->objects[location].size \
            > new_element.weight / new_element.size)
        {
            data->objects[location + 1] = data->objects[location];
            location--;
        }
        data->objects[location + 1] = new_element;
    }
}

int find_str_in_name(struct thing object, char *str_to_find)
{
    int success = 1;
    for (int i = 0; str_to_find[i] != '\0' && success == 1; i++)
        if (str_to_find[i] != object.name[i])
            success = 0;
    return success;
}


status_codes object_create(int size, struct thing **object_arr)
{
    *object_arr = malloc(size * sizeof(struct thing));

    status_codes code = ok;
    if (object_arr == NULL)
        code = memory_error;

    return code;
}

status_codes create_str(int size, char **str)
{
    *str = malloc(size * sizeof(char));

    status_codes code = ok;
    if (str == NULL)
        code = memory_error;
    
    return code;
}

void clean_array(void *array)
{
    if (array != NULL)
        free(array);
}

void init_dyn_array_objects(struct dyn_arr_objects *data)
{
    data->objects = NULL;
    data->len = 0;
    data->allocated = 0;
    data->step = 2;
}

void prepare_obj_to_print(struct dyn_arr_objects *data, char *str_to_find)
{
    int ind = 0;
    while (str_to_find != NULL && ind < data->len)
    {
        if (!find_str_in_name(data->objects[ind], str_to_find))
        {
            clean_array(data->objects[ind].name);
            for (int j = ind; j < data->len - 1; j++)
                data->objects[j] = data->objects[j + 1];
            data->len -= 1;
            ind--;
        }
        ind++;
    }
}