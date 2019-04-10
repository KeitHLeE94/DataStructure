//
// Created by Keith_Lee on 10/04/2019.
//

#include "sort.h"

void swap(char **p, char **q){
    char *temp;

    temp = *q;
    *q = *p;
    *p = temp;
}