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
	clock_t start, end;

	start = clock();

	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	printf("¦®");
	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < BACKGROUNDRIGHTDOWNXPOS; xPos++) {
		printf("¦¬");
	}

	printf("¦¯");
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	for (yPos = BACKGROUNDLEFTUPYPOS + 1; yPos < BACKGROUNDRIGHTDOWNYPOS; yPos++) {
		moveCursor(BACKGROUNDLEFTUPXPOS, yPos);
		printf("¦­");
	}
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDRIGHTDOWNYPOS);
	printf("¦±");

	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < BACKGROUNDRIGHTDOWNXPOS; xPos++) {
		printf("¦¬");
	}

	printf("¦°");

	for (yPos = BACKGROUNDRIGHTDOWNYPOS - 1; yPos > BACKGROUNDLEFTUPYPOS; yPos--) {
		moveCursor(BACKGROUNDRIGHTDOWNXPOS * 2 - BACKGROUNDLEFTUPXPOS - 1, yPos);
		printf("¦­");
	}
	end = clock();
	moveCursor(72, 27);
	printf("%.3lf ¹Ð¸®ÃÊ", (double)(end - start));
}


void createItemInMap(Map* map) {

	unsigned int xPos, yPos;
	
	srand(time(NULL));

	xPos = (rand() % (BACKGROUNDRIGHTDOWNXPOS * 2 - 10)) + BACKGROUNDLEFTUPXPOS - 2;
	yPos = (rand() % (BACKGROUNDRIGHTDOWNYPOS)) + BACKGROUNDLEFTUPYPOS - 2;

	map->item = createItem(xPos, yPos);
	
}

Item* createItem(int xPos, int yPos) {

	Item* item = (Item*)malloc(sizeof(Item));
	item->xPos = xPos;
	item->yPos = yPos;
	moveCursor(xPos, yPos);
	printf("¤·");
	moveCursor(0, 0);

	return item;
}

Map* initializeMap() {
	
	Map* map = (Map*)malloc(sizeof(Map));
	map->item = NULL;

	return map;
}