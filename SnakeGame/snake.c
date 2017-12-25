#include<windows.h>

#include"snake.h"


snakeElem * makeSnakeElem(int xPos, int yPos) {

	snakeElem* snake;
	
	if ((snake = (snakeElem*)malloc(sizeof(snakeElem))) == NULL) {
		fprintf(stderr, "SYSTEM ERROR");
		return NULL;
	}
	snake->xPos = xPos;
	snake->yPos = yPos;
	snake->prev = NULL;
	snake->next = NULL;
	moveCursor(snake->xPos, snake->yPos);

	printf("бс");
	snake->moveTo = moveLeft;
	return snake;
}

Snake* initializeSnake() {
	
	Snake * snake;

	if ((snake = (Snake*)malloc(sizeof(Snake))) == NULL) {
		fprintf(stderr, "SYSTEM ERROR");
		return NULL;
	}
	snakeElem* firstSnakeElem = makeSnakeElem(BACKGROUNDRIGHTDOWNXPOS + 1, BACKGROUNDRIGHTDOWNYPOS / 2);
	snake->head = firstSnakeElem;
	snake->tail = firstSnakeElem;

	return snake;
}


void moveSnake(snakeElem * snake) {

	int pressed_key;

	
	if (_kbhit()) {
		pressed_key = _getch();
		if (pressed_key == 224 || pressed_key == 0) {
			pressed_key = _getch();
			switch (pressed_key) {

			case LEFT:
				snake->moveTo = moveLeft;
				break;
			case RIGHT:
				snake->moveTo = moveRight;
				break;
			case UP:
				snake->moveTo = moveUp;
				break;
			case DOWN:
				snake->moveTo = moveDown;
				break;
			default:
				break;
			}
		}
		else {

		}
	}
	else {
		snake->moveTo(snake);
		Sleep(100);
	}
	
}

int isSnakeInTheMap(snakeElem* snake) {

	if ((snake->xPos >= (BACKGROUNDRIGHTDOWNXPOS * 2 - 10)) || (snake->xPos <= BACKGROUNDLEFTUPXPOS)) {
		return FALSE;
	}
	else if ((snake->yPos >= BACKGROUNDRIGHTDOWNYPOS) || (snake->yPos <= BACKGROUNDLEFTUPYPOS)) {
		return FALSE;
	}
	return TRUE;
}

void getItemBySnake(Snake* snake, Map* map) {

	if ((snake->head->xPos == map->item->xPos) && (snake->head->yPos == map->item->yPos)) {
		setScoreInScreen(map, 30);
		free(map->item);
		createItemInMap(map);
	}
}

static inline void moveUp(snakeElem * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	snake->yPos -= 1;
	moveCursor(snake->xPos, snake->yPos);
	printf("бс");
}

static inline void moveDown(snakeElem * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	snake->yPos += 1;
	moveCursor(snake->xPos, snake->yPos);
	printf("бс");
}

static inline void moveRight(snakeElem * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	printf("бс");
	snake->xPos += 2;
	moveCursor(snake->xPos, snake->yPos);
}

static inline void moveLeft(snakeElem * snake) {
	moveCursor(snake->xPos, snake->yPos);
	printf("  ");
	snake->xPos -= 2;
	moveCursor(snake->xPos, snake->yPos);
	printf("бс");
}

/*
void moveSnakeOld(snakeElem * snake) {

	int pressed_key;


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

*/
