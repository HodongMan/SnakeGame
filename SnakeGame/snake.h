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

typedef struct {
	unsigned int xPos;
	unsigned int yPos;
}Snake;

Snake * initializeSnake();
void moveSnake(Snake * snake);


static inline void moveUp(Snake * snake);
static inline void moveDown(Snake * snake);
static inline void moveLeft(Snake * snake);
static inline void moveRight(Snake * snake);


#endif