/**
Написать программу, которая запрашивает у пользователя строку,
разбивает строку на слова.В результате разбора строки формируется
массив слов. Из слов, отличных от последнего, составляется новая 
строка, в которой слова разделяютсяодним пробелом. Слова в 
результирующую строку помещаются в обратном порядке. После
последнего слова в результирующей строке пробел не добавляется.
Прежде, чем очередное слово помещается в результирующую строку, 
оно подвергается указанному преобразованию.
1. Оставить в слове только первые вхождения каждой буквы.
*/

#include <stdio.h>
#include <string.h>
#include "str_functions.h"
#define STR_LEN 257
#define SEPARATORS ",;:-.! ?\n\r"

int main(void)
{
    status_codes code = ok;
    char str[STR_LEN];
    char words[WORD_COUNT][WORD_LEN];
    read_line_and_check(str, &code);
    if (code == ok)
    {
        int count_words = split_by_words(str, words);
        if (count_words - 1 <= 0)
            code = no_different_words_e;
        else
        {
            char str_result[STR_LEN];
            form_new_string(words, str_result, count_words);
        }
    }
    if (code != ok)
        print_error(&code);
    return code;
}