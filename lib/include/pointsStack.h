#ifndef POINTSSTACK_H_
#define POINTSSTACK_H_

#define FACTOR 2

typedef struct point {
    int x;
    int y;
} point_t;

typedef struct pointsStack {
    point_t *stack;
    int capacity;
    int currentPosition;
} pointsStack_t;

pointsStack_t *createStack(int initialCapacity);
struct point *pop(pointsStack_t *stack);
void push(pointsStack_t *stack, struct point p);
void freeStack(pointsStack_t *stack);

#endif