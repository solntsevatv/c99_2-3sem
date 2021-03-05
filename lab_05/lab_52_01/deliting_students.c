#include <unistd.h>
#include "my_functions.h"

double find_marks_average(FILE *f, status_codes *code)
{
    size_t num_of_students = count_students(f, code);
    if (num_of_students == 0 && *code == ok)
        *code = empty_file;
    struct student current_student;
    double all_sum = 0, student_score = 0;
    if (*code == ok)
    {
        for (size_t i = 0; i < num_of_students; i++)
        {
            if (fread(&current_student, sizeof(struct student), 1, f))
            {
                student_score = 0;
                for (int j = 0; j < SUBJECTS_COUNT; j++)
                    student_score += current_student.marks[j];
                student_score /= 4;
                all_sum += student_score;
            }
        }
    }
    return (double) all_sum / num_of_students;
}

void del_student(FILE *f, size_t ind, size_t num_of_students, status_codes *code)
{
    struct student next_student;
    for (size_t i = ind; i < num_of_students - 1; i++)
    {
        get_student_by_pos(f, i + 1, &next_student, code);
        put_student_by_pos(f, i, &next_student, code);
    }
    size_t size = 0;
    file_size(f, &size);
    ftruncate(fileno(f), size - sizeof(struct student));
}

void del_students_with_low_score(double average, FILE *f, status_codes *code)
{
    size_t num_of_students = count_students(f, code);
    double student_score = 0;
    struct student current_student;
    for (size_t i = 0; i < num_of_students; i++)
    {
        fseek(f, i * sizeof(struct student), SEEK_SET);
        if (fread(&current_student, sizeof(struct student), 1, f))
        {
            student_score = 0;
            for (int j = 0; j < SUBJECTS_COUNT; j++)
                student_score += current_student.marks[j];
            student_score /= 4;
            if (student_score < average)
            {
                del_student(f, i, num_of_students, code);
                num_of_students--;
                i--;
            }
        }
    }
}