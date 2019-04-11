//
// Created by Keith_Lee on 11/04/2019.
//

#ifndef DATASTRUCTURE_NODE_H
#define DATASTRUCTURE_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* newNode(int n){
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = n;
    temp->next = NULL;

    return temp;
}

#endif //DATASTRUCTURE_NODE_H
