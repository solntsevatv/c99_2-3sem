#ifndef _PROCESSING_H_
#define _PROCESSING_H_

void insertion_sort_array(struct dyn_arr_objects *data);
struct thing *reallocate_mem(int *size, struct thing **object_arr, status_codes *code);
void clean_array(void *array);
status_codes create_str(int size, char **str);
status_codes object_create(int size, struct thing **object_arr);
void init_dyn_array_objects(struct dyn_arr_objects *data);
void prepare_obj_to_print(struct dyn_arr_objects *data, char *str_to_find);

#endif