#include <stdlib.h>
#include "my_functions.h"

void fill_file_random_numbers(int count, FILE *f)
{
    int num = 0;
    for (int i = 0; i < count; i++)
    {
        num = -1000 + rand() % 2001;
        fwrite(&num, sizeof(int), 1, f);
    }
}

status_codes input_processing(int argc, char **argv)
{
    status_codes code = ok;
    FILE *f;

    if (argc != 3 && argc != 4)
        code = incorrect_input;
    else if (argc == 4)
    {
        f = fopen(argv[3], "wb");
        fill_file_random_numbers(atoi(argv[2]), f);
    }
    else if (argc == 3)
    {
        if (argv[1][0] == 'p' && argv[1][1] == '\0')
        {
            f = fopen(argv[2], "rb");
            if (f != NULL)
                print_bin_file(f, &code);
            else
                code = file_not_transferred;
        }
        else if (argv[1][0] == 's' && argv[1][1] == '\0')
        {
            f = fopen(argv[2], "r+b");
            if (f != NULL)
                sort_numbers(f, &code);
            else
                code = file_not_transferred;
        }
        else
            code = incorrect_input;
    }
    
    if (code != file_not_transferred && code != incorrect_input)
        fclose(f);
    return code;
}

void print_bin_file(FILE *f, status_codes *code)
{
    size_t size, read;
    int num;
    int rc = 0;
    if (file_size(f, &size) != 0 || size % sizeof(int) != 0)
        *code = size_error;
    else if (size == 0)
        *code = empty_file;
    if (*code == ok)
        for (size_t i = 0; !rc && i < size / sizeof(int); i++)
        {
            read = fread(&num, sizeof(int), 1, f);
            if (read == 1)
                printf("%d ", num);
            else
                rc = 1;
        }
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
}
