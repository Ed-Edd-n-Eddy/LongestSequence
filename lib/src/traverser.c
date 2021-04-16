#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../include/traverser.h"

int visitPoints(int rows, int cols, char matrix[][cols]) {
    int maxElements = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 'v')
                continue;
            int currMax = procedureDFS(i, j, rows, cols, matrix);
            maxElements = currMax > maxElements ? currMax : maxElements;
        }
    }
    return maxElements;
}

static int procedureDFS(int x, int y, int rows, int cols, char matrix[][cols]) {
            /* DFS init stack and push initial points */
            char color = matrix[x][y];
            matrix[x][y] = 'v';
            int currMax = 1;
            pointsStack_t *stack = createStack(INITIAL_STACK_SIZE);
            pushValidAdjacentPoints(x, y, rows, cols, matrix, color, stack);
            /* DFS iterate until no points are left */
            while(stack->currentPosition > 0) {
                point_t *currPoint = pop(stack);
                currMax++;
                pushValidAdjacentPoints(currPoint->x, currPoint->y, rows, cols, matrix, color, stack);
            }
            freeStack(stack);
            return currMax;
}

static void pushValidAdjacentPoints(int x, int y, int rows, int cols, char matrix[][cols], char color, pointsStack_t *stack) {
    /* check left, up, right, down and push point to stack if necessary */
    if(checkLeft(x, y, cols, matrix, color)) { /* for left */
        pushPoint(x, y-STEP, stack, cols, matrix);
    }

    if(checkUp(x, y, rows, cols, matrix, color)) { /* for up */
        pushPoint(x-STEP, y, stack, cols, matrix);
    }

    if(checkRight(x, y, cols, matrix, color)) { /* for right */
        pushPoint(x, y+STEP, stack, cols, matrix);
    }

    if(checkDown(x, y, rows, cols, matrix, color)) { /* for down */
        pushPoint(x+STEP, y, stack, cols, matrix);
    }
}

static void pushPoint(int x, int y, pointsStack_t *stack, int cols, char matrix[][cols]) {
    point_t point;
    point.x = x;
    point.y = y;
    push(stack, point);
    matrix[x][y] = 'v';
}


static bool checkLeft(int x, int y, int cols, char matrix[][cols], char color){
    return (((y-STEP) >= WITHIN) && ((y-STEP) < cols) && matrix[x][y-STEP] == color) == true;
}

static bool checkUp(int x, int y, int rows, int cols, char matrix[][cols], char color){
    return (((x-STEP) >= WITHIN) && ((x-STEP) < rows) && matrix[x-STEP][y] == color) == true;
}

static bool checkRight(int x, int y, int cols, char matrix[][cols], char color){
    return (((y+STEP) >= WITHIN) && ((y+STEP) < cols) && matrix[x][y+STEP] == color) == true;
}

static bool checkDown(int x, int y, int rows, int cols, char matrix[][cols], char color){
    return (((x+STEP) >= WITHIN) && ((x+STEP) < rows) && matrix[x+STEP][y] == color) == true;
}