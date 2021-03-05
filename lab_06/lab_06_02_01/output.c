#include "const_errors.h"
#include <string.h>

void print_objects(struct thing *object, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        printf("%s\n%lf\n%lf\n", object[i].name, object[i].weight, object[i].size);
}
