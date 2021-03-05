#include "my_functions.h"

void print_bin_file(FILE *f, status_codes *code)
{
    size_t size, read;
    struct student current_student;

    int rc = 0;
    if (file_size(f, &size) != 0 || size % sizeof(struct student) != 0)
        *code = size_error;
    else if (size == 0)
        *code = empty_file;

    if (*code == ok)
        for (size_t i = 0; !rc && i < size / sizeof(struct student); i++)
        {
            read = fread(&current_student, sizeof(struct student), 1, f);
            if (read == 1)
            {
                if (i != 0)
                    printf("\n");
                printf("%s ", current_student.surname);
                printf("%s ", current_student.name);
                for (int i = 0; i < SUBJECTS_COUNT; i++)
                    printf("%d ", current_student.marks[i]);
            }
            else
                rc = 1;
        }
}

status_codes input_processing(int argc, char **argv)
{
    FILE *f;
    status_codes code = ok;
    if (argc == 3)
    {
        if (argv[1][0] == 's' && argv[1][1] == 'b' && argv[1][2] == '\0')
        {
            f = fopen(argv[2], "r+b");
            if (f != NULL)
            {
                sort_students(f, &code);
                print_bin_file(f, &code);
            }
            else
                code = file_not_transferred;
        }
        else if (argv[1][0] == 'd' && argv[1][1] == 'b' && argv[1][2] == '\0')
        {
            f = fopen(argv[2], "r+b");
            if (f != NULL)
            {
                double average = find_marks_average(f, &code);
                del_students_with_low_score(average, f, &code);
            }
            else
                code = file_not_transferred;
        }
        else
            code = incorrect_input;
    }
    else if (argc == 5)
    {
        if (argv[1][0] == 'f' && argv[1][1] == 'b' && argv[1][2] == '\0')
        {
            f = fopen(argv[2], "rb");
            if (f != NULL)
            {
                FILE *f_out = fopen(argv[3], "wb");
                record_students_begin_with_str(f, f_out, argv[4], &code);
                fclose(f_out);
            }
            else
                code = file_not_transferred;
        }
        else
            code = incorrect_input;
    }
    else
        code = incorrect_input;
    
    if (code != file_not_transferred && code != incorrect_input)
        fclose(f);

    return code;
}


void print_errors(status_codes code)
{
    if (code == file_not_transferred)
        fprintf(stdout, "File wasn't transferred");
    else if (code == empty_file)
        fprintf(stdout, "File is empty");
    else if (code == incorrect_input)
        fprintf(stdout, "Incorrect input!");
    else if (code == size_error)
        fprintf(stdout, "There is a size error in the file");
    else if (code == sorting_error)
        fprintf(stdout, "There is a sorting error in the file");
    else if (code == reading_error)
        fprintf(stdout, "There is a reading error in the file");
    else if (code == put_error)
        fprintf(stdout, "There is a put error in the file");
    else if (code == output_file_empty)
        fprintf(stdout, "Output file is empty");
}
