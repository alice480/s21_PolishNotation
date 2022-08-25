#include "stack.h"

node *push(node *head, char *token) {
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("Memory error!\n");
    } else {
        if (head == NULL) {
            strcpy(ptr->token, token);
            ptr->NEXT = NULL;
            head = ptr;
        } else {
            strcpy(ptr->token, token);
            ptr->NEXT = head;
            head = ptr;
        }
    }
    return head;
}

node *pop(node *head, char **element) {
    if (head) {
        strcpy(*element, head->token);
        node * ptr = head;
        head = head->NEXT;
        free(ptr);
    }
    return head;
}

char *peek(node *head) {
    char *ans = NULL;
    if (head != NULL) ans = head->token;
    return ans;
}

