#ifndef _VIEW_H__
#define _VIEW_H__

#include<conio.h>
#include<windows.h>
#include<time.h>



#define BACKGROUNDLEFTUPXPOS 9 
#define BACKGROUNDLEFTUPYPOS 2
#define BACKGROUNDRIGHTDOWNXPOS 60
#define BACKGROUNDRIGHTDOWNYPOS 26


typedef struct _item {

	unsigned int xPos;
	unsigned int yPos;

}Item;

typedef struct _map {

	Item* item;
	unsigned int total_score;

}Map;

void moveCursor(int xPos, int yPos);
void drawMap();
void createItemInMap(Map* map);

Map * initializeMap();
Item* createItem(int xPos, int yPos);
void setScoreInScreen(Map* map, int score);


static int makeOddNumber(int number);


#endif