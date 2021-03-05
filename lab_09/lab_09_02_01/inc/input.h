#ifndef _INPUT_H_
#define _INPUT_H_

FILE *check_input(int argc, status_codes *code, char **argv);
status_codes read_array(FILE *f, struct dyn_arr_objects *data);

#endif