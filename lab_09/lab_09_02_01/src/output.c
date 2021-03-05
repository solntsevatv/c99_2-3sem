#include "../inc/const_errors.h"

void print_objects(struct dyn_arr_objects data)
{
    for (int i = 0; i < data.len; i++)
        printf("%s\n%lf\n%lf\n", data.objects[i].name, data.objects[i].weight, data.objects[i].size);
}