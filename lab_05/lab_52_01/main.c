/**
app.exe sb file_in - упорядочивает информацию о студентах по фамилиям
app.exe fb file_in file_out substr - выводит информацию о 
студентах в другой файл
app.exe db file_in_out - вычисляет средний балл и удаляет студентов с меньшим
*/

#include <stdlib.h>
#include "my_functions.h"

int main(int argc, char **argv)
{
    status_codes code = ok;
    code = input_processing(argc, argv);
    print_errors(code);
    return code;
}