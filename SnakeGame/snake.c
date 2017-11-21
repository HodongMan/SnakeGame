#include"snake.h"


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
					moveLeft(snake);
					break;
				case RIGHT:
					moveRight(snake);
					break;
				case UP:
					moveUp(snake);
					break;
				case DOWN:
					moveDown(snake);
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

static inline void moveUp(Snake * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	snake->yPos -= 1;
	moveCursor(snake->xPos, snake->yPos);
	printf("бс");
}

static inline void moveDown(Snake * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	snake->yPos += 1;
	moveCursor(snake->xPos, snake->yPos);
	printf("бс");
}

static inline void moveRight(Snake * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	printf("бс");
	snake->xPos += 2;
	moveCursor(snake->xPos, snake->yPos);
}

static inline void moveLeft(Snake * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	snake->xPos -= 2;
	moveCursor(snake->xPos, snake->yPos);
	printf("бс");
}
