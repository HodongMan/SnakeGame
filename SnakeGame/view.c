#include<stdio.h>
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

	printf("旨");
	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < BACKGROUNDRIGHTDOWNXPOS; xPos++) {
		printf("收");
	}

	printf("旬");
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	for (yPos = BACKGROUNDLEFTUPYPOS + 1; yPos < BACKGROUNDRIGHTDOWNYPOS; yPos++) {
		moveCursor(BACKGROUNDLEFTUPXPOS, yPos);
		printf("早");
	}
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDRIGHTDOWNYPOS);
	printf("曲");

	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < BACKGROUNDRIGHTDOWNXPOS; xPos++) {
		printf("收");
	}

	printf("旭");

	for (yPos = BACKGROUNDRIGHTDOWNYPOS - 1; yPos > BACKGROUNDLEFTUPYPOS; yPos--) {
		moveCursor(BACKGROUNDRIGHTDOWNXPOS * 2 - BACKGROUNDLEFTUPXPOS - 1, yPos);
		printf("早");
	}
	end = clock();
	moveCursor(72, 27);
	printf("%.3lf 塵葬蟾", (double)(end - start));
}
