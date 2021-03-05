/**
Здесь содержатся функции, обрабатывающие слова и строку.
*/

#include <string.h>
#include <stdio.h>
#include "str_func.h"
#define SEPARATORS ",;:-.! ?"

void regulate_words_ind(int *word_num_ind, int *word_symbol_ind, \
char words[WORD_COUNT][WORD_LEN])
{
    int k = 0;
    int n = *word_num_ind;
    words[n][*word_symbol_ind] = '\0';
    while (k < n && strcmp(words[k], words[n]) != 0)
        k++;
    if (k != n && strcmp(words[k], words[n]) == 0)
    {
        *word_symbol_ind = 0;
        words[n][*word_symbol_ind] = '\0';
    }
    else
    {
        words[n][*word_symbol_ind] = '\0';
        *word_symbol_ind = 0;
        *word_num_ind = n + 1;
    }
}

int split_by_words(const char *str, char words[WORD_COUNT][WORD_LEN])
{
    int i = 0;
    int word_num_ind = 0;
    int word_symbol_ind = 0;
    while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
    {
        if (strchr(SEPARATORS, str[i]) != NULL)
        {
            if (i != 0 && strchr(SEPARATORS, str[i - 1]) == NULL)
                regulate_words_ind(&word_num_ind, &word_symbol_ind, words);
        }
        else
        {
            words[word_num_ind][word_symbol_ind] = str[i];
            word_symbol_ind++;
        }
        i++;
    }
    words[word_num_ind][word_symbol_ind] = '\0';
    if (strchr(SEPARATORS, str[i - 1]) == NULL)
        word_num_ind++;
    return word_num_ind;
}

void copy_word(char word[WORD_COUNT][WORD_LEN], int i, int change)
{
    int n = 0;
    for (int j = 0; word[i + change][j] != '\0'; j++)
    {
        word[i][j] = word[i + change][j];
        n++;
    }
    word[i][n] = word[i + change][n];
}

void sort_words(int count_words, char words[WORD_COUNT][WORD_LEN])
{
    int left = 0;
    int right = count_words - 1;
    int swapped = 1;
    char word[WORD_LEN];
    while (swapped == 1)
    {
        swapped = 0;

        for (int i = left; i < right; i++)
        {
            if (strcmp(words[i], words[i + 1]) > 0)
            {
                strcpy(word, words[i]);
                copy_word(words, i, 1);
                strcpy(words[i + 1], word);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        right -= 1;

        for (int i = right; i > left; i--)
        {
            if (strcmp(words[i - 1], words[i]) > 0)
            {
                strcpy(word, words[i]);
                copy_word(words, i, -1);
                strcpy(words[i - 1], word);
                swapped = 1;
            }
        }
        left += 1;
    }
}
