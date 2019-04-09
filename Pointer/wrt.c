//
// Created by Keith_Lee on 09/04/2019.
//

#include "MergeSort.h"

void wrt(int key[], int sz){
    int i;

    for(i=0; i<sz; i++){
        printf("%4d%s", key[i], ((i < sz - 1) ? " " : "\n"));
    }
}