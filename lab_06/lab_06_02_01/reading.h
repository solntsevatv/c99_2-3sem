#ifndef _READING_H_
#define _READING_H_

status_codes read_array(FILE *f, struct thing *object, int *n);
FILE *check_input(int argc, status_codes *code, char **argv);

#endif