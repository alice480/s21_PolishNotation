#ifndef SRC_CALCULATE_H_
#define SRC_CALCULATE_H_
#include <stdlib.h>

struct node {
    char number;
    struct node* next;
};

struct node* init(char number);
struct node* pop(struct node* head);
struct node* push(char number, struct node* head);
void destroy(struct node* root);

#endif  // SRC_CALCULATE_H_
