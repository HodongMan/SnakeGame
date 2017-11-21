#include"view.h"
#include"snake.h"

int main()
{
	
	drawMap();
	Snake* snake = initializeSnake();
	while (1) {
		moveSnake(snake);
	}
	return 0;
	
}
