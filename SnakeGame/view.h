#ifndef _VIEW_H__
#define _VEIW_H__

#include<conio.h>
#include<windows.h>
#include<time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define PAUSE 112

#define BACKGROUNDLEFTUPXPOS 9 
#define BACKGROUNDLEFTUPYPOS 2
#define BACKGROUNDRIGHTDOWNXPOS 60
#define BACKGROUNDRIGHTDOWNYPOS 26




static inline moveCursor(int xPos, int yPos) {

	COORD position;
	position.X = xPos;
	position.Y = yPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void drawMap();



#endif