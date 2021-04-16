#include <stdlib.h>

#include "../include/pointsStack.h"

pointsStack_t *createStack(int initialCapacity) {
    pointsStack_t *stack = malloc(sizeof(pointsStack_t));

    stack->stack = malloc(initialCapacity * sizeof(point_t));
    stack->capacity = initialCapacity;
    stack->currentPosition = 0;

    return stack;
}

void push(pointsStack_t *stack, point_t p) {

    if(stack->capacity == stack->currentPosition){
        int newCapacity = stack->capacity * FACTOR;
        stack->stack = realloc(stack->stack, newCapacity * (sizeof(point_t)));
        stack->capacity = newCapacity;
    }

    stack->stack[stack->currentPosition++] = p;
}

point_t *pop(pointsStack_t *stack) {
    return &stack->stack[--stack->currentPosition];
}

void freeStack(pointsStack_t *stack) {
    free(stack->stack);
    free(stack);
}
