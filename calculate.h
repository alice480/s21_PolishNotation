#ifndef SRC_CALCULATING_H_
#define SRC_CALCULATING_H_
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct d_node {
    float number;
    struct d_node* next;
};

struct d_node* d_init(float number);
struct d_node* d_push(float number, struct d_node* head);
void destroy(struct d_node* root);

float value_calculating(float x, char **rpn, int rpn_size);

#endif  // SRC_CALCULATING_H_
