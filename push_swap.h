#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>

typedef struct stack{
    int capacity;
    int size;
    int *collection;
}stack;

#endif