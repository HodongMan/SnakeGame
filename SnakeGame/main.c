#include"view.h"
#include"snake.h"

int main()
{
	int isInTheMap = 0;
	Snake* snake;
	Map* map;

	drawMap();
	snake = initializeSnake();
	map = initializeMap();

	createItemInMap(map);

	while (1) {
		moveSnake(snake->head);
		if (!isSnakeInTheMap(snake->head)) {
			break;
		}
	}
	return 0;
	
}
