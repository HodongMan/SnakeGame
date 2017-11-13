#ifndef _VIEW_H__
#define _VEIW_H__

#include<conio.h>
#include<windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define PAUSE 112

#define BACKGROUNDLEFTUPXPOS 9 
#define BACKGROUNDLEFTUPYPOS 2
#define BACKGROUNDRIGHTDOWNXPOS 60
#define BACKGROUNDRIGHTDOWNYPOS 25

void moveCursor(int xPos, int yPos) {

	COORD position;
	position.X = xPos;
	position.Y = yPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void drawMap() {

	int i, j;
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	printf("��");
	for (i = BACKGROUNDLEFTUPXPOS + 1; i < BACKGROUNDRIGHTDOWNXPOS; i++) {
		printf("��");
	}

	printf("��");
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDLEFTUPYPOS);

	for (j = BACKGROUNDLEFTUPYPOS + 1; j < BACKGROUNDRIGHTDOWNYPOS; j++) {
		moveCursor(BACKGROUNDLEFTUPXPOS, j);
		printf("��");
	}
	moveCursor(BACKGROUNDLEFTUPXPOS, BACKGROUNDRIGHTDOWNYPOS);
	printf("��");

	for (i = BACKGROUNDLEFTUPXPOS + 1; i < BACKGROUNDRIGHTDOWNXPOS; i++) {
		printf("��");
	}

	printf("��");

	for (j = BACKGROUNDRIGHTDOWNYPOS - 1; j > BACKGROUNDLEFTUPYPOS; j--) {
		moveCursor(BACKGROUNDRIGHTDOWNXPOS * 2 - BACKGROUNDLEFTUPXPOS - 1, j);
		printf("��");
	}

	moveCursor(72, 27);
}




#endif