#include "Window.h"

int main()
{
	Window* window = new Window("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1720, 920, false);

	while (true)
	{
		window->Update();
		window->Clear();
	}
	window->Clean();
	return 0;
}