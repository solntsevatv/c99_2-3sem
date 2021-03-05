/**
Ввести одну строку. Составить массив из слов исходной строки 
(каждое слово должно входить в массив только один раз). Упорядочить 
этот массив в лексикографическом порядке. Слова из упорядоченного
массива вывести на экран, разделив одним пробелом.
*/

#include <stdio.h>
#include <string.h>
#include "str_func.h"
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
        sort_words(count_words, words);
        print_words(words, count_words);
    }
    else
        print_error(&code);
    return code;
}