#include <stdio.h>
#include <string.h>
#define MAX_SURNAME_LEN 25
#define MAX_NAME_LEN 10
#define SUBJECTS_COUNT 4

struct student
{
    char surname[MAX_SURNAME_LEN + 1];
    char name[MAX_NAME_LEN + 1];
    unsigned int marks[SUBJECTS_COUNT];
};

typedef enum
{
    ok,
    empty_file,
    file_not_transferred,
    reading_error,
    put_error,
    size_error,
    sorting_error,
    output_file_empty,
    incorrect_input = 53,
} status_codes;

double find_marks_average(FILE *f, status_codes *code);
void del_student(FILE *f, size_t ind, size_t num_of_students, status_codes *code);
void del_students_with_low_score(double average, FILE *f, status_codes *code);

int file_size(FILE *f, size_t *size);
size_t count_students(FILE *f, status_codes *code);

void get_student_by_pos(FILE *f, long ind, struct student *current_student, status_codes *code);
void put_student_by_pos(FILE *f, long ind, struct student *current_student, status_codes *code);
void sort_students(FILE *f, status_codes *code);

void record_students_begin_with_str(FILE *f_in, FILE *f_out, \
char string[MAX_SURNAME_LEN], status_codes *code);

void print_bin_file(FILE *f, status_codes *code);
status_codes input_processing(int argc, char **argv);
void print_errors(status_codes code);