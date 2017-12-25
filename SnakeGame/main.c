#include"view.h"
#include"snake.h"

int main()
{
	Snake* snake;
	Map* map;
	snakeElem* temp;

	drawMap();
	snake = initializeSnake();
	map = initializeMap();

	createItemInMap(map);
	setScoreInScreen(map, 0);

	while (TRUE) {
		moveSnake(snake->head);
		if (!isSnakeInTheMap(snake->head)) {
			break;
		}
		getItemBySnake(snake, map);
	}
	temp = snake->head;
	while (TRUE) {
		
		
		printf("%d %d\n", temp->xPos, temp->yPos);
		if (temp->next == NULL) {
			break;
		}
		else {
			temp = temp->next;
		}
	}
	return 0;
	
}
