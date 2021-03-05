/**
Здесь содержатся функции, обрабатывающие слова и строку.
*/

#include <string.h>
#include <stdio.h>
#include "str_functions.h"
#define SEPARATORS ",;:-.! ?"

void copy_word(char word[WORD_COUNT][WORD_LEN], const char *str2, int i)
{
    int n = 0;
    for (int j = 0; str2[j] != '\0'; j++)
    {
        word[i][j] = str2[j];
        n++;
    }
    word[i][n] = str2[n];
}

int delete_words_like_last(char words[WORD_COUNT][WORD_LEN], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        if (strcmp(words[i], words[n - 1]) == 0)
        {
            for (int j = i; j < n - 1; j++)
                copy_word(words, words[j + 1], j);
            n--;
        }
    }
    return n--;
}

int split_by_words(char *str, char words[WORD_COUNT][WORD_LEN])
{
    char *pword = strtok(str, SEPARATORS);
    int n = 0;
    while (pword)
    {
        copy_word(words, pword, n);
        pword = strtok(NULL, SEPARATORS);
        n++;
    }
    n = delete_words_like_last(words, n);
    return n;
}

void form_new_string(char words[WORD_COUNT][WORD_LEN], \
char *str_result, int n)
{
    int str_ind = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int len_word = strlen(words[i]);
        for (int j = 0; j < len_word; j++)
        {
            if (strcmp(strchr(words[i], words[i][j]), &words[i][j]) == 0)
            {
                str_result[str_ind] = words[i][j];
                str_ind++;
            }
        }
        str_result[str_ind] = ' ';
        str_ind++;
    }
    str_result[str_ind - 1] = '\0';
    printf("Result: %s\n", str_result);
}