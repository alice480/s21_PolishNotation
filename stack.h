#ifndef SRC_STACK_H_
#define SRC_STACK_H_
// Максимальная длина для token
#define MAXLEN 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char token[MAXLEN];
    struct node *NEXT;
} node;

node* push(node* head, char *token);
node* pop(node *head, char** element);
char *peek(node *head);

#endif  // SRC_STACK_H_
