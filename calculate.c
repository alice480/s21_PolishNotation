#include "calculating.h"
#define BINARY "+", "-", "*", "/"
#define UNARY "sin", "cos", "tan", "ctg", "sqrt", "ln", "-"

struct d_node* d_init(float number) {
    struct d_node* head = malloc(sizeof(struct d_node));
    head->number = number;
    head->next = NULL;
    return head;
}

struct d_node* d_push(float number, struct d_node* head) {
    struct d_node *new_node = malloc(sizeof(struct d_node));
    new_node->number = number;
    new_node->next = head;
    head = new_node;
    return head;
}

void d_destroy(struct d_node* head) {
    while (head) {
        struct d_node *ptr;
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

int operator_check(char *operator) {  // returns 1 if a function or operator is passed
    int flag = 0;
    char *bin[4] = {BINARY};
    char *un[7] = {UNARY};
    for (int i = 0; i < 4; i++)
        if (!strcmp(operator, bin[i]))
            flag = 2;
    for (int i = 0; i < 7; i++)
        if (!strcmp(operator, un[i]))
            flag = 1;
    return flag;
}

float bin_operation(char *simbols, float number1, float number2) {
    const char *str = simbols;
    float result = 0;
    if (!strcmp(str, "+"))
        result = number1 + number2;
    else if (!strcmp(str, "-"))
        result = number1 - number2;
    else if (!strcmp(str, "*"))
        result = number1 * number2;
    else if (!strcmp(str, "/"))
        result = number1 / number2;
    return result;
}

float un_operation(char *simbols, float number) {
    const char *str = simbols;
    float result = 0;
    if (!strcmp(str, "cos"))
        result = (cos(number));
    else if (!strcmp(str, "sin"))
        result = (sin(number));
    else if (!strcmp(str, "tan"))
        result = (tan(number));
    else if (!strcmp(str, "ctg"))
        result = (cos(number) / sin(number));
    else if (!strcmp(str, "sqrt"))
        result = (sqrt(number));
    else if (!strcmp(str, "ln"))
        result = (log(number));
    return result;
}

float value_calculating(float x, char **rpn, int rpn_size) {
    struct d_node *head = NULL;
    float result = 0;
    for (int i = 0; i < rpn_size; i++) {
        if (!operator_check(rpn[i])) {
            const char *str = rpn[i];
            float digit;
            if (!strcmp(str, "x"))
                digit = x;
            else
                digit = atof(str);
            if (!head)
                head = d_init(digit);
            else
                head = d_push(digit, head);
        } else if (operator_check(rpn[i]) == 1) {
            float num1 = 0;
            if (head) {
                num1 = head->number;
                struct d_node *ptr = head;
                head = head->next;
                free(ptr);
            }
            if (head)
                d_push(un_operation(rpn[i], num1), head);
            else
                head = d_init(un_operation(rpn[i], num1));
        } else if (operator_check(rpn[i]) == 2) {
            float num2, num1;
            if (head) {
                num2 = head->number;
                num1 = head->next->number;
                struct d_node *ptr = head;
                head = head->next;
                free(ptr);
            }
            if (head) {
                struct d_node *ptr = head;
                head = head->next;
                free(ptr);
            }
            if (head) {
                d_push(bin_operation(rpn[i], num2, num1), head);
            } else {
                head = d_init(bin_operation(rpn[i], num2, num1));
                head->number = bin_operation(rpn[i], num2, num1);
            }
        }
    }
    if (head)
        result = head->number;
    d_destroy(head);
    return result;
}

