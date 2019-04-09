//
// Created by Keith_Lee on 09/04/2019.
//

#include "MergeSort.h"

int main(){
    int sz, key[] = {4, 3, 1, 67, 55, 8, 0, 4, -5, 37, 7, 4, 2, 9, 1, -1};

    sz = sizeof(key) / sizeof(int);
    printf("Before mergesort: \n");
    wrt(key, sz);
    mergeSort(key, sz);
    printf("After mergesort: \n");
    wrt(key, sz);

    return 0;
}