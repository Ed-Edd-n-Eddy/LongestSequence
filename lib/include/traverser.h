#ifndef TRAVERSER_H_
#define TRAVERSER_H_

#include "../include/pointsStack.h"

#define INITIAL_STACK_SIZE 10
#define STEP 1
#define WITHIN 0

int visitPoints(int rows, int cols, char matrix[][cols]);

static void pushValidAdjacentPoints(int x, int y, int rows, int cols, char matrix[][cols], char color, pointsStack_t *stack);
static void pushPoint(int x, int y, pointsStack_t *stack, int cols, char matrix[][cols]);
static int procedureDFS(int x, int y, int rows, int cols, char matrix[][cols]);
static bool checkLeft(int x, int y, int cols, char matrix[][cols], char color);
static bool checkUp(int x, int y, int rows, int cols, char matrix[][cols], char color);
static bool checkRight(int x, int y, int cols, char matrix[][cols], char color);
static bool checkDown(int x, int y, int rows, int cols, char matrix[][cols], char color);

#endif