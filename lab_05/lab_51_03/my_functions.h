#include <stdio.h>

typedef enum
{
    ok,
    empty_file,
    incorrect_input,
    file_not_transferred,
    size_error,
} status_codes;

void fill_file_random_numbers(int count, FILE *f);
status_codes input_processing(int argc, char **argv);
void print_bin_file(FILE *f, status_codes *code);
void print_errors(status_codes code);

int file_size(FILE *f, size_t *size);
size_t count_numbers(FILE *f, status_codes *code);

void print_bin_file(FILE *f, status_codes *code);
void print_errors(status_codes code);

int get_number_by_pos(FILE *f, long ind, int *sort_code);
void put_number_by_pos(FILE *f, long ind, int num, int *sort_code);
void sort_numbers(FILE *f, status_codes *code);
