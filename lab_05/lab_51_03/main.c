/**
тип int, шейкерная сортировка, по возрастанию

 app.exe c number file  - создание файла с number числами;
 app.exe p file - вывести числа из файла на экран;
 app.exe s file - упорядочить числа в файле;

*/

#include "my_functions.h"

int main(int argc, char **argv)
{
    status_codes code = ok;
    code = input_processing(argc, argv);
    if (code != ok)
        print_errors(code);
    return code;
}