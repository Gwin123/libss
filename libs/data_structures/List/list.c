//
// Created by DNS on 27.12.2021.
//

#include "list.h"
#include <malloc.h>

void test() {
    printf("Hello, World");
}

void push(Node **head, int data) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}


int pop(Node **head) {
    Node* prev = NULL;
    if (head == NULL) {
        exit(-1);
    }

    prev = (*head);
    int val = prev->value;
    (*head) = (*head)->next;

    free(prev);

    return val;
}

