#ifndef _PROCESSING_H_
#define _PROCESSING_H_

void insertion_sort_array(int n, struct thing *object);
int find_str_in_name(struct thing object, char *str_to_find);
int form_array_of_found_objects(struct thing *object, int arr_size, char *str_to_find);

#endif