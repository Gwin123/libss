#ifndef INC_LIST_H

#define INC_LIST_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


void push(Node **head, int data);

int pop(Node **head);

void test();

#endif