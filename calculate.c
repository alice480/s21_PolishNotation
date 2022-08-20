#include "calculate.h"

struct node* init(char number) {
    struct node* head = malloc(sizeof(struct node));
    head->number = number;
    head->next = NULL;
    return head;
}

struct node* pop(struct node* head) {
    if (head) {
        struct node *ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}

struct node* push(char number, struct node* head) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->number = number;
    new_node->next = head;
    head = new_node;
    return head;
}

void destroy(struct node* head) {
    while (head) {
        struct node *ptr;
        ptr = head;
        head = head->next;
        free(ptr);
    }
}
