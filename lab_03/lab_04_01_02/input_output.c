/**
Здесь содержатся функции, регулирующие ввод строки, ее проверку и
вывод необзодимого результата.
*/

#include <stdio.h>
#include <string.h>
#include "str_func.h"
#define STR_LEN 257
#define SEPARATORS ",;:-.! ?\n\r"

void read_line_and_check(char *str, status_codes *code)
{
    int ch;
    int n = 0;
    int len_word = 0;
    int words_count = 0;

    while ((ch = getchar()) != '\n' && ch != EOF && ch != '\r' \
        && ch != '\0' && n < STR_LEN - 1 && len_word < WORD_LEN)
    {
        str[n] = ch;
        if (strchr(SEPARATORS, ch) == NULL)
            len_word++;
        else
        {
            if (n != 0 && strchr(SEPARATORS, str[n - 1]) == NULL)
                words_count++;
            len_word = 0;
        }
        n++;
    }

    if (n != 0 && strchr(SEPARATORS, str[n - 1]) == NULL)
        words_count++;

    if (len_word >= WORD_LEN)
        *code = too_long_word_e;
    else if (words_count > WORD_COUNT)
        *code = too_many_words_e;
    else
        str[n] = '\0';


    if (*code == ok)
    {
        n = 0;
        *code = input_string_e;
        while (*code == input_string_e && str[n] != '\0')
        {
            if (strchr(SEPARATORS, str[n]) == NULL)
                *code = ok;
            n++;
        }
    }
}

void print_words(char words[WORD_COUNT][WORD_LEN], int count_words)
{
    printf("Result:");
    for (int i = 0; i < count_words; i++)
    {
        printf(" ");
        printf("%s", words[i]);
    }
}

void print_error(status_codes *code)
{
    switch (*code)
    {
        case input_string_e:
            printf("Please, input correct string!");
            break;
        case too_long_word_e:
            printf("Some words were too long!");
            break;
        case too_many_words_e:
            printf("Too many words!");
            break;
        case ok:
            break;
    }
}