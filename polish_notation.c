#include "rpn.h"

char** convert_to_rpn(char** buf, int buf_size, int str_size, int* rpn_size) {
    node* head = NULL;
    char* func_arr[] = {FUNCTIONS};
    int found_func;
    char* trash = malloc(sizeof(char));
    char peek_buf;

    char** rpn = malloc(sizeof(char*) * buf_size);
    for (int i = 0; i < buf_size; i++) {
        rpn[i] = malloc(sizeof(char) * str_size);
    }
    int rpn_i = 0;

    for (int i = 0; i < buf_size; i++) {
       int flag_func = 0;
       int flag_num = 0;
        for (int j = 0; j < FCOUNT; j++) {
            if (!strcmp(buf[i], func_arr[j])) {
                head = push(head, buf[i]);
                flag_func = 1;
            }
        }
        if (flag_func == 0) {
            if ((buf[i][0] >= 48 && buf[i][0] <= 57) || buf[i][0] == 120 || buf[i][0] == 88) {
                strcpy(rpn[rpn_i], buf[i]);
                rpn_i++;
                flag_num = 1;
            }
        }
        if (flag_func == 0 && flag_num == 0) {
            switch (buf[i][0]) {
                case '(':
                    head = push(head, "(");
                    break;

                case ')':
                    while (strcmp(peek(head), "(")) {
                        head = pop(head, &rpn[rpn_i]);
                        rpn_i++;
                    }
                    head = pop(head, &trash);
                    for (int j = 0; j < FCOUNT; j++)
                        if (peek(head) == func_arr[j]) found_func = 1;
                    if (found_func) {
                        head = pop(head, &rpn[rpn_i]);
                        rpn_i++;
                    }
                    break;

                case '*':
                case '/':
                case '+':
                case '-':
                case '#':
                    if (peek(head) != NULL) {
                        peek_buf = peek(head)[0];
                        while ((peek_buf == '+' || peek_buf == '-' || peek_buf == '*' || peek_buf == '/' ||
                                peek_buf == '#') &&
                               (precedence(peek_buf) > precedence(buf[i][0]))) {
                            head = pop(head, &rpn[rpn_i]);
                            if (peek(head) != NULL) {
                                peek_buf = peek(head)[0];
                            } else {
                                peek_buf = '\0';
                            }
                            rpn_i++;
                        }
                    }
                    head = push(head, buf[i]);
                    break;
            }
        }
    }
    while (head != NULL) {
        head = pop(head, &rpn[rpn_i]);
        rpn_i++;
    }
    *rpn_size = rpn_i;
    free(trash);
    return rpn;
}

int precedence(char op) {
    int ans;
    if (op == '+' || op == '-') ans = 1;
    if (op == '*' || op == '/') ans = 2;
    if (op == '#') ans = 3;
    return ans;
}
