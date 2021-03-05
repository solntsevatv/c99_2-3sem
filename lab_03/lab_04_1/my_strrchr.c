#include "my_strrchr.h"
#include <stddef.h>

char *my_strrchr(char *str, int ch)
{
    char *symb;
    symb = NULL;
    int string_len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            symb = &str[i];
        string_len++;
    }
    if (ch == '\0')
        symb = &str[string_len];
    return symb;
}