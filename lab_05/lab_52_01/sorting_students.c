#include <string.h>
#include "my_functions.h"

void get_student_by_pos(FILE *f, long ind, struct student *current_student, status_codes *code)
{
    int reading_code = 0;
    if (fseek(f, ind * sizeof(struct student), SEEK_SET) == 0)
        reading_code = fread(&current_student->surname, sizeof(char[MAX_SURNAME_LEN + 1]), 1, f);
    if (reading_code)
        reading_code = fread(&current_student->name, sizeof(char[MAX_NAME_LEN + 1]), 1, f);
    if (reading_code)
        reading_code = fread(&current_student->marks, sizeof(unsigned int [SUBJECTS_COUNT]), 1, f);
    if (!reading_code)
        *code = reading_error;
}

void put_student_by_pos(FILE *f, long ind, struct student *current_student, status_codes *code)
{
    int put_code = 0;
    if (fseek(f, ind * sizeof(struct student), SEEK_SET) == 0)
        put_code = fwrite(current_student->surname, sizeof(char[MAX_SURNAME_LEN + 1]), 1, f);
    if (put_code)
        put_code = fwrite(current_student->name, sizeof(char[MAX_NAME_LEN + 1]), 1, f);
    if (put_code)
        put_code = fwrite(current_student->marks, sizeof(unsigned int [SUBJECTS_COUNT]), 1, f);
    if (!put_code)
        *code = put_error;
}

void sort_students(FILE *f, status_codes *code)
{
    size_t left = 0, right = count_students(f, code) - 1;
    int swapped = 1;
    if (right == 0 && *code != ok)
        swapped = 0;
    else if (right + 1 == 0)
        *code = empty_file;
    struct student current_student, next_student;
    while (swapped == 1)
    {
        swapped = 0;

        for (size_t i = left; i < right; i++)
        {
            get_student_by_pos(f, i, &current_student, code);
            if (*code == ok)
                get_student_by_pos(f, i + 1, &next_student, code);
            if (*code == ok && strcmp(current_student.surname, next_student.surname) > 0)
            {
                put_student_by_pos(f, i, &next_student, code);
                if (*code == ok)
                    put_student_by_pos(f, i + 1, &current_student, code);
                swapped = 1;
            }
            else if (*code == ok && strcmp(current_student.surname, next_student.surname) == 0 \
                && strcmp(current_student.name, next_student.name) > 0)
            {
                put_student_by_pos(f, i, &next_student, code);
                if (*code == ok)
                    put_student_by_pos(f, i + 1, &current_student, code);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        right -= 1;

        for (size_t i = right; i > left; i--)
        {
            get_student_by_pos(f, i - 1, &current_student, code);
            if (*code == ok)
                get_student_by_pos(f, i, &next_student, code);
            if (*code == ok && strcmp(current_student.surname, next_student.surname) > 0)
            {
                put_student_by_pos(f, i - 1, &next_student, code);
                if (*code == ok)
                    put_student_by_pos(f, i, &current_student, code);
                swapped = 1;
            }
            else if (*code == ok && strcmp(current_student.surname, next_student.surname) == 0 \
                && strcmp(current_student.name, next_student.name) > 0)
            {
                put_student_by_pos(f, i - 1, &next_student, code);
                if (*code == ok)
                    put_student_by_pos(f, i, &current_student, code);
                swapped = 1;
            }
        }
        left += 1;
    }
}