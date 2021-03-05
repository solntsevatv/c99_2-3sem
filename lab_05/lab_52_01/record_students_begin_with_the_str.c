#include "my_functions.h"

void record_students_begin_with_str(FILE *f_in, FILE *f_out, \
char string[MAX_SURNAME_LEN], status_codes *code)
{
    int string_len = strlen(string);
    size_t size, read;
    struct student current_student;

    int rc = 0;
    if (file_size(f_in, &size) != 0 || size % sizeof(struct student) != 0)
        *code = size_error;
    else if (size == 0)
        *code = empty_file;

    int count_record_students = 0;
    if (*code == ok)
        for (size_t i = 0; !rc && i < size / sizeof(struct student); i++)
        {
            read = fread(&current_student, sizeof(struct student), 1, f_in);
            if (read == 1)
            {
                int flag = 1;
                for (int j = 0; j < string_len; j++)
                    if (string[j] != current_student.surname[j])
                    {
                        flag = 0;
                        break;
                    }
                if (flag == 1)
                {
                    count_record_students += 1;
                    fwrite(current_student.surname, sizeof(char[MAX_SURNAME_LEN + 1]), 1, f_out);
                    fwrite(current_student.name, sizeof(char[MAX_NAME_LEN + 1 + 3]), 1, f_out);        ///3 байта для выравнивания
                    fwrite(current_student.marks, sizeof(unsigned int [SUBJECTS_COUNT]), 1, f_out);
                }
            }
            else
                rc = 1;
        }
    if (count_record_students == 0 && *code == ok)
        *code = output_file_empty;
}