#include<stdio.h>
#include"view.h"

void drawMap() {

	int xPos, yPos;
	clock_t start, end;

	start = clock();

	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	printf("��");
	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < BACKGROUNDRIGHTDOWNXPOS; xPos++) {
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

	for (xPos = BACKGROUNDLEFTUPXPOS + 1; xPos < BACKGROUNDRIGHTDOWNXPOS; xPos++) {
		printf("��");
	}

	printf("��");

	for (yPos = BACKGROUNDRIGHTDOWNYPOS - 1; yPos > BACKGROUNDLEFTUPYPOS; yPos--) {
		moveCursor(BACKGROUNDRIGHTDOWNXPOS * 2 - BACKGROUNDLEFTUPXPOS - 1, yPos);
		printf("��");
	}
	end = clock();
	moveCursor(72, 27);
	printf("%.3lf �и���", (double)(end - start));
}
