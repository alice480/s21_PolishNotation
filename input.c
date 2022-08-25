#include "input.h"

// Reads the input string and returns a pointer to its beginning
char *input_string() {
    char *str = malloc(sizeof(char));
    char ch;
    int len = 0;
    while ((ch = getchar()) && ch != '\n') {
        str[len] = ch;
        len += 1;
        char* temp = realloc(str, sizeof(char) * (len + 1));
        if (temp != NULL) {
            str = temp;
        }
    }
    return str;
}

// Returns an array of strings with functions, operators, and operands
from the read string
char **parse_string(char *str, int *buf_size) {
    int len = strlen(str);
    char *func_arr[] = {FUNCTIONS};
    char **buf = malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++) {
        buf[i] = malloc(sizeof(char) * len);
    }

    int buf_i = 0;
    while (*str != '\0') {
        int flag_func = 0;
        // Проверяем функции
        for (int i = 0; i < FCOUNT; i++) {
            if (strstr(str, func_arr[i]) == str) {
                strcpy(buf[buf_i], func_arr[i]);
                buf_i++;
                str = str + strlen(func_arr[i]);
                flag_func = 1;
            }
        }
        if (flag_func == 0) {
            int flag_num = 0;
            // Проверяем числа
            int num_i = 0;
            while ((str[0] >= 48 && str[0] <= 57) || str[0] == '.') {
                buf[buf_i][num_i] = str[0];
                str++;
                num_i++;
            }
            if (num_i > 0) {
                flag_num = 1;
                buf_i++;
            }
            // If there are no functions or numbers
            if (flag_num == 0) {
                // Checking unary or binary minus
                if (str[0] == '-') {
                    if (buf_i == 0 || buf[buf_i - 1][0] == '(') {
                        buf[buf_i][0] = '#';  // unary
                        buf[buf_i][1] = '\0';
                        buf_i++;
                        str++;
                    } else {
                        buf[buf_i][0] = '-';  // binary
                        buf[buf_i][1] = '\0';
                        buf_i++;
                        str++;
                    }
                } else {
                    buf[buf_i][0] = str[0];
                    buf[buf_i][1] = '\0';
                    buf_i++;
                    str++;
                }
            }
        }
    }
    *buf_size = buf_i;
    return buf;
}
