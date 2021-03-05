#include "const_errors.h"

void insertion_sort_array(int n, struct thing *object)
{
    int location;
    struct thing new_element;
    for (int i = 1; i < n; i++)
    {
        new_element = object[i];
        location = i - 1;
        while (location >= 0 && object[location].weight / object[location].size \
            > new_element.weight / new_element.size)
        {
            object[location + 1] = object[location];
            location--;
        }
        object[location + 1] = new_element;
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

int form_array_of_found_objects(struct thing *object, int arr_size, char *str_to_find)
{
    int ind = 0;
    while (ind < arr_size)
    {
        if (!find_str_in_name(object[ind], str_to_find))
        {
            for (int j = ind; j < arr_size - 1; j++)
                object[j] = object[j + 1];
            arr_size--;
            ind--;
        }
        ind++;
    }
    return arr_size;
}