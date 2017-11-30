#include"view.h"
#include"snake.h"

int main()
{
	Snake* snake;
	Map* map;

	drawMap();
	snake = initializeSnake();
	map = initializeMap();

	createItemInMap(map);
	setScoreInScreen(map, 0);

	while (1) {
		moveSnake(snake->head);
		if (!isSnakeInTheMap(snake->head)) {
			break;
		}
		getItemBySnake(snake, map);
	}
	return 0;
	
}
