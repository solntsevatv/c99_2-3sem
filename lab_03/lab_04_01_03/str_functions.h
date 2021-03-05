#define WORD_LEN 17
#define WORD_COUNT 16

typedef enum
{
    ok,
    input_string_e,
    too_long_word_e,
    too_many_words_e,
    no_different_words_e,
} status_codes;

int split_by_words(char *str, char words[WORD_COUNT][WORD_LEN]);
void read_line_and_check(char *str, status_codes *code);
void print_error(status_codes *code);

void copy_word(char word[WORD_COUNT][WORD_LEN], const char *str2, int i);
int delete_words_like_last(char words[WORD_COUNT][WORD_LEN], int n);
void form_new_string(char words[WORD_COUNT][WORD_LEN], char *str_result, int n);