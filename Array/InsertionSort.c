//
// Created by Keith_Lee on 08/04/2019.
//

#include <stdio.h>

int arr[10];
int i;

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void insertionSort(){
    for(i=1; i<sizeof(arr) / sizeof(int); i++){
        int j = i;

        while(j != 0 && arr[j] < arr[j-1]){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

int main(){
    for(i=0; i<10; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort();

    for(i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}