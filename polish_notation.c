#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calculate.h"
#define Operations "+", "-", "*", "/", "sin", "cos", "tg", "ctg", "sqrt", "ln" // max length 4

int is_operator(char *simbols);
char math_operation(char *simbols, char number1, char number2);

int main() {
    char *expres = "- * / 5 - 7 + 1 1 2 + 2 + 1 1";
    struct node *head;
    head = init(expres[0]);  // checking of null str
    head = push(expres[1], head);
    char new_value;
    for (int i = 2; *(expres + i); i++) {
        if (expres[i] != ' ')
            head = push(expres[i], head);
        if (is_operator(head->next->next->number) &&
            !is_operator(head->next->number) && !is_operator(head->number)) {
                new_value = math_operation(head->next->next->number, head->next->number, head->number);
                head = pop(head);
                head = pop(head);
                head = pop(head);
                head = push(new_value, head);
        }
    }
    printf("%d", head->number);
    destroy(head);
}

int is_operator(char *simbols) {
    int flag = 0;
    char *operators[10] = {Operations};
    for (int i = 0; i < 10; i++)
        flag += (!strcmp(simbols, operators[i]));
    return flag;
}

char math_operation(char *simbols, char number1, char number2) {
    char result;
    if (!strcmp(simbols, "+"))
        result = number1 + number2;
    else if (!strcmp(simbols, "-"))
        result = number1 - number2;
    else if (!strcmp(simbols, "*"))
        result = number1 * number2;
    else if (!strcmp(simbols, "/"))
        result = number1 / number2;
    else if (!strcmp(simbols, "sin"))
        result = (sin(number1));
    else if (!strcmp(simbols, "cos"))
        result = (cos(number1));
    else if (!strcmp(simbols, "tg"))
        result = (tan(number1));
    else if (!strcmp(simbols, "tg"))
        result = (t);
    return result;
}
