#include "../inc/my_func.h"
#include "../inc/const_errors.h"

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define ERROR -1
#define STR_MAX_INT_SIZE 12
#define STR_MAX_LINT_SIZE 23

void str_reverse(char *str)
{
    int size = strlen(str);
    char ch;
    for (int i = 0; i < size / 2; i++)
    {
        ch = str[size - 1 - i];
        str[size - 1 - i] = str[i];
        str[i] = ch;
    }
}

void str_init(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
}

void int_to_str(long num, char *str, int size)
{
    str_init(str, size);
    int ind = 0, check_minus = false;

    if (num < 0)
        check_minus = true;

    unsigned long abs_num = labs(num);

    if (abs_num == 0)
        str[ind] = '0';

    while (abs_num > 0)
    {
        str[ind++] = '0' + abs_num % 10;
        abs_num /= 10;
    }

    if (check_minus)
        str[ind] = '-';

    str_reverse(str);
}

int count_result_len(const char *format, int ind, va_list vl)
{
    int len = 0;
    long arg;
    char int_convert[STR_MAX_LINT_SIZE];

    for (int i = ind; format[i] != '\0'; i++)
    {
        len++;
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            if (format[i + 1] == 'c')
            {
                arg = va_arg(vl, int);
                i++;
            }
            else if (format[i + 1] == 's')
            {
                char *str = va_arg(vl, char *);
                len += strlen(str) - 1;
                i++;
            }
            else if (format[i + 1] == 'd')
            {
                arg = va_arg(vl, int);
                int_to_str(arg, int_convert, STR_MAX_INT_SIZE);
                len += strlen(int_convert) - 1;
                i++;
            }
            else if (format[i + 1] == 'l' && format[i + 2] == 'd')
            {
                arg = va_arg(vl, long);
                int_to_str(arg, int_convert, STR_MAX_LINT_SIZE);
                len += strlen(int_convert) - 1;
                i += 2;
            }
        }
    }
    return len;
}

// return num of not recorded digits
int read_int(long num, int *str_ind, char *s, int n)
{
    int not_rec = 0, ind = 0;

    char int_convert[STR_MAX_LINT_SIZE];
    int_to_str(num, int_convert, STR_MAX_LINT_SIZE);
    
    while (*str_ind < n - 1 && int_convert[ind] != '\0')
    {
        s[*str_ind] = int_convert[ind];
        *str_ind += 1;
        ind++;
    }

    while (int_convert[ind] != '\0')
    {
        not_rec++;
        ind++;
    }

    return not_rec;
}

// return num of not recorded symbols
int read_str(char *arg_str, int *res_str_ind, char *source_str, int n)
{
    int src_str_ind = 0, not_rec = 0;

    while (*res_str_ind < n - 1 && arg_str[src_str_ind] != '\0')
        source_str[(*res_str_ind)++] = arg_str[src_str_ind++];

    while (arg_str[src_str_ind] != '\0')
    {
        src_str_ind++;
        not_rec++;
    }

    return not_rec;
}

boolean read_arg(const char *format, int *i, char *s, int *result, va_list *vl, int *str_ind, int n)
{
    boolean read = true;

    if (format[*i] == 'c')
    {
        int ch = va_arg(*vl, int);
        s[(*str_ind)++] = (char) ch;
    }
    else if (format[*i] == 's')
    {
        char *str = va_arg(*vl, char *);
        result += read_str(str, str_ind, s, n);
    }
    else if (format[*i] == 'd')
    {
        int num = va_arg(*vl, int);
        result += read_int(num, str_ind, s, n);
    }
    else if (format[*i] == 'l' && format[*i + 1] == 'd')
    {
        *i += 1;
        long num = va_arg(*vl, long);
        result += read_int(num, str_ind, s, n);
    }
    else
        read = false;

    return read;
}

int my_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list vl;
    int str_ind = 0, i = 0;
    int result = 0;

    if (format == NULL || (s == NULL && n > 0))
        result = ERROR;
    
    va_start(vl, format);
    while (n != 0 && result >= 0 && str_ind < n - 1 && format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] == '%')
            s[str_ind++] = format[i++];
        else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 's' \
            || format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == 'l'))
        {
            i++;
            if (!read_arg(format, &i, s, &result, &vl, &str_ind, n))
                s[str_ind++] = format[i - 1];
        }
        else
            s[str_ind++] = format[i];
        i++;
    }
    if (n > str_ind && s != NULL)
        s[str_ind] = '\0';

    if (result != ERROR)
        result += str_ind + count_result_len(format, i, vl);
    
    va_end(vl);
    return result;
}