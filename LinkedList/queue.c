//
// Created by Keith_Lee on 11/04/2019.
//

#include "node.h"

typedef struct Queue{
    struct Node* front;
    struct Node* rear;
    int size;
} Queue;

Queue* init_queue();
void enqueue(Queue* q, Node* newNode);
void dequeue(Queue* q);
int front(Queue* q);
void printQueue(Queue* q);

Queue* init_queue(){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));

    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;

    return newQueue;
}

void enqueue(Queue* q, Node* newNode){
    if(q->size == 0){
        q->front = newNode;
        newNode->next = q->rear;
    }
    else{
        Node* temp = q->front;
        int i;

        for(i=1; i<q->size; i++){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = q->rear;
    }

    q->size++;
}

void dequeue(Queue* q){
    if(q->size == 0){
        printf("dequeue() : queue is empty \n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    q->size--;
}

int front(Queue* q){
    int result = 0;

    if(q->size == 0){
        printf("front() : queue is empty \n");
    }
    else{
        result = q->front->data;
    }

    return result;
}

void printQueue(Queue* q){
    if(q->size == 0){
        printf("printQueue() : queue is empty \n");
        return;
    }

    Node* temp = q->front;

    for(int i=0; i<q->size; i++){
        printf("[%d] ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(){
    int i;

    Queue* q = init_queue();

    enqueue(q, newNode(1));
    printf("front : %d\n", front(q));

    dequeue(q);
    dequeue(q);

    printQueue(q);

    for(i=2; i<6; i++){
        enqueue(q, newNode(i));
    }
    printQueue(q);

    dequeue(q);
    printQueue(q);

    for(i=0; i<3; i++){
        dequeue(q);
    }

    front(q);

    return 0;
}