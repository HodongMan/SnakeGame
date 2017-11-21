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
	int xPos;
	int yPos;
}Snake;

Snake * initializeSnake() {

	Snake* snake = (Snake*)malloc(sizeof(Snake));
	snake->xPos = BACKGROUNDRIGHTDOWNXPOS + 1;
	snake->yPos = BACKGROUNDRIGHTDOWNYPOS / 2;
	moveCursor(snake->xPos, snake->yPos);
	printf("бс");
	return snake;
}


void moveSnake(Snake * snake) {

	int pressed_key;

	while (1) {
		if (_kbhit()) {
			pressed_key = _getch();
			if (pressed_key == 224 || pressed_key == 0) {
				pressed_key = _getch();
				switch (pressed_key) {
					
					case LEFT:

						moveCursor(snake->xPos, snake->yPos);
						printf("  ");
						snake->xPos -= 2;
						moveCursor(snake->xPos, snake->yPos);
						printf("бс");
						
						break;
					case RIGHT:

						moveCursor(snake->xPos, snake->yPos);
						printf("  ");
						printf("бс");
						snake->xPos += 2;
						moveCursor(snake->xPos, snake->yPos);

						break;
					case UP:

						moveCursor(snake->xPos, snake->yPos);
						printf("  ");
						snake->yPos -= 1;
						moveCursor(snake->xPos, snake->yPos);
						printf("бс");

						break;
					case DOWN:

						moveCursor(snake->xPos, snake->yPos);
						printf("  ");
						snake->yPos += 1;
						moveCursor(snake->xPos, snake->yPos);
						printf("бс");

						break;
					default:
						break;
				}
			}
			else {

			}
		}
	}
}

void moveSnakeOld(Snake * snake) {

	int pressed_key;

	while (1) {
		if (_kbhit()) {
			pressed_key = _getch();
			if (pressed_key == 224 || pressed_key == 0) {
				pressed_key = _getch();
				switch (pressed_key) {

				case LEFT:

					moveCursor(snake->xPos, snake->yPos);
					printf("  ");
					snake->xPos -= 2;
					moveCursor(snake->xPos, snake->yPos);
					printf("бс");

					break;
				case RIGHT:

					snake->xPos -= 2;
					moveCursor(snake->xPos, snake->yPos);
					printf("  ");
					snake->xPos += 2;
					moveCursor(snake->xPos, snake->yPos);
					printf("бс");
					snake->xPos += 2;
					moveCursor(snake->xPos, snake->yPos);

					break;
				case UP:

					moveCursor(snake->xPos, snake->yPos);
					printf("  ");
					snake->yPos -= 1;
					moveCursor(snake->xPos, snake->yPos);
					printf("бс");

					break;
				case DOWN:

					snake->yPos -= 1;
					moveCursor(snake->xPos, snake->yPos);
					printf("  ");
					snake->yPos += 1;
					moveCursor(snake->xPos, snake->yPos);
					printf("бс");
					snake->yPos += 1;
					moveCursor(snake->xPos, snake->yPos);

					break;
				default:
					break;
				}
			}
			else {

			}
		}
	}
}



#endif