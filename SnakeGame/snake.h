#ifndef _SNAKE_H__

#define _SNAKE_H__

#include"view.h"
#include<stdio.h>
#include<stdlib.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define PAUSE 112


typedef struct _snakeElem{

	unsigned int xPos;
	unsigned int yPos;
	struct _snakeElem* prev;
	struct _snakeElem* next;

}snakeElem;

typedef struct {

	snakeElem* head;
	snakeElem* tail;

}Snake;

Snake* initializeSnake();
snakeElem* makeSnakeElem(int xPos, int yPos);
void moveSnake(snakeElem* snake);
int isSnakeInTheMap(snakeElem* snake);

void getItemBySnake(Snake* snake, Map* map);


static inline void moveUp(snakeElem * snake);
static inline void moveDown(snakeElem * snake);
static inline void moveLeft(snakeElem * snake);
static inline void moveRight(snakeElem * snake);


#endif