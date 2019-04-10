//
// Created by Keith_Lee on 10/04/2019.
//

#include "sort.h"

void error_exit_calloc_failed(){
    printf("%s", "ERROR: The call to calloc() failed to allocate the requested memory - bye!\n");
    exit(1);
}

void error_exit_too_many_words(){
    printf("ERROR: At most %d words can be stored - bye!\n", N);
    exit(1);
}

void error_exit_word_too_long(){
    printf("%s%d%s", "ERROR: A word with more than ", MAXWORD, " characters was found - bye!\n");
    exit(1);
}