//
// Created by Keith_Lee on 11/04/2019.
//

#include "node.h"

typedef struct List{
    struct Node* head;
    int size;
} List;

List* init_list();
void appendTo(List* list, Node* newNode);
void delAt(List* list, int n);
void printList(List* list);

List* init_list(){
    List* newList = (List*)malloc(sizeof(Node));

    newList->head = NULL;
    newList->size = 0;

    return newList;
}

void appendTo(List* list, Node* newNode){
    if(list->size == 0){
        list->head = newNode;
    }
    else{
        Node* cursor = list->head;
        int i;

        for(i=1; i<list->size; i++){
            cursor = cursor->next;
        }

        cursor->next = newNode;
    }

    list->size++;
}

void delAt(List* list, int n){
    if(n < 0 || list->size < n){
        printf("Out of index ( n = %d ) \n", n);
        return;
    }

    Node* cursor = list->head;

    for(int i=0; i<n-2; i++){
        cursor = cursor->next;
    }

    Node* temp = cursor->next;
    cursor->next = temp->next;
    free(temp);

    list->size--;
}

void printList(List* list){
    Node* temp = list->head;

    printf("List Size: %d\n", list->size);
    for(int i=0; i<list->size; i++){
        printf("[%d] ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    List* linked = init_list();

    int i;
    for (i = 1; i < 6; i++) {
        appendTo(linked, newNode(i));
    }
    printList(linked);

    delAt(linked, -1);
    delAt(linked, 5);
    printList(linked);

    delAt(linked, 3);
    printList(linked);

    return 0;
}