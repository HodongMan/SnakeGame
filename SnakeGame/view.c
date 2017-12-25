#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"view.h"

inline void moveCursor(int xPos, int yPos) {

	COORD position;
	position.X = xPos;
	position.Y = yPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


void drawMap() {

	int xPos, yPos;

	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	printf("��");
	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < (BACKGROUNDRIGHTDOWNXPOS * 2) - 10; xPos++) {
		printf("��");
	}

	printf("��");
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	for (yPos = BACKGROUNDLEFTUPYPOS + 1; yPos < BACKGROUNDRIGHTDOWNYPOS; yPos++) {
		moveCursor(BACKGROUNDLEFTUPXPOS, yPos);
		printf("��");
	}
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDRIGHTDOWNYPOS);
	printf("��");

	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < (BACKGROUNDRIGHTDOWNXPOS * 2) - 10; xPos++) {
		printf("��");
	}

	printf("��");

	for (yPos = BACKGROUNDRIGHTDOWNYPOS - 1; yPos > BACKGROUNDLEFTUPYPOS; yPos--) {
		moveCursor(BACKGROUNDRIGHTDOWNXPOS * 2 - BACKGROUNDLEFTUPXPOS - 1, yPos);
		printf("��");
	}
	
}


void createItemInMap(Map* map) {

	unsigned int xPos, yPos;
	
	srand(time(NULL));

	xPos = makeOddNumber((rand() % (BACKGROUNDRIGHTDOWNXPOS * 2 - 20)) + BACKGROUNDLEFTUPXPOS);
	yPos = makeOddNumber((rand() % (BACKGROUNDRIGHTDOWNYPOS)) + BACKGROUNDLEFTUPYPOS);

	map->item = createItem(xPos, yPos);
	
}

static inline int makeOddNumber(int number) {
	
	if (number % 2 == 0) {
		return number - 1;
	}

	return number;
}

Item* createItem(int xPos, int yPos) {

	Item* item;

	if ((item = (Item*)malloc(sizeof(Item))) == NULL) {
		fprintf(stderr, "SYSTEM ERROR");
		return NULL;
	}
	item->xPos = xPos;
	item->yPos = yPos;
	moveCursor(xPos, yPos);
	printf("��");
	moveCursor(0, 0);

	return item;
}

Map* initializeMap() {
	
	Map* map;

	if ((map = (Map*)malloc(sizeof(Map))) == NULL) {
		fprintf(stderr, "SYSTEM ERROR");
		return NULL;
	}
	map->item = NULL;
	map->total_score = 0;

	return map;
}

void setScoreInScreen(Map* map, int score) {
	
	moveCursor(72, 27);
	map->total_score += score;
	printf("���� ������ %d �Դϴ�.", map->total_score);

}