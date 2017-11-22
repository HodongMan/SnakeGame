#include"view.h"
#include"snake.h"

int main()
{
	int isInTheMap = 0;
	drawMap();
	Snake* snake = InitializeSnake();
	while (1) {
		moveSnake(snake->head);
		if (!isSnakeInTheMap(snake->head)) {
			break;
		}
	}
	return 0;
	
}
