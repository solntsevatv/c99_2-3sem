#define WORD_LEN 17
#define WORD_COUNT 16

typedef enum
{
    ok,
    input_string_e,
    too_long_word_e,
    too_many_words_e,
} status_codes;

void read_line_and_check(char *str, status_codes *code);
void print_words(char words[WORD_COUNT][WORD_LEN], int count_words);
void print_error(status_codes *code);
void sort_words(int count_words, char words[WORD_COUNT][WORD_LEN]);
int split_by_words(const char *str, char words[WORD_COUNT][WORD_LEN]);