//
// Created by Keith_Lee on 11/04/2019.
//

#include "node.h"

typedef struct Stack{
    struct Node* top;
    int size;
} Stack;

Stack* init_stack();
void push(Stack* s, Node* newnode);
void pop(Stack* s);
int top(Stack* s);
void print_stack(Stack* s);

Stack* init_stack(){
    Stack* newStack = (Stack*)malloc(sizeof(Stack));

    newStack->top = NULL;
    newStack->size = 0;

    return newStack;
}

void push(Stack* s, Node* newnode){
    if(s->size == 0){
        s->top = newnode;
    }
    else{
        newnode->next = s->top;
        s->top = newnode;
    }

    s->size++;
}

void pop(Stack* s){
    if(s->size == 0){
        printf("pop() : stack is empty. \n");
        return;
    }

    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);

    s->size--;
}

int top(Stack* s){
    int result = 0;

    if(s->size == 0){
        printf("top() : stack is empty. \n");
    }
    else{
        result = s->top->data;
    }

    return result;
}

void print_stack(Stack* s){
    Node* temp = s->top;

    for(int i=0; i<s->size; i++){
        printf("[%d] ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int i;

    Stack* s = init_stack();

    push(s, newNode(1));
    printf("top : %d\n", top(s));

    pop(s);
    pop(s);

    for (i = 2; i < 6; i++) {
        push(s, newNode(i));
    }

    pop(s);
    print_stack(s);

    for (i = 0; i < 3; i++) pop(s);
    top(s);

    return 0;
}