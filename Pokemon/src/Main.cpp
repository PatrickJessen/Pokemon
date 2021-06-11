#include "Window.h"
#include "Kanto/PalletTown/PalletTown.h"

int main()
{
	Window* window = new Window("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1720, 920, false);

	//PalletTown* palletTown = new Level(window, "Assets/Map/PalletTown.map", "Assets/Map/PalletTown.png", 100, 100, 1, 16, 3);

	Level* test = new PalletTown(window, "Assets/Map/PalletTown1.map", "Assets/Map/pt.bmp", 50, 50, 1, 16, 2);
	test->tex = test->loadTexture();

	while (true)
	{
		test->LoadMap();
		window->Update();
		window->Clear();
	}
	//test->CleanMapArr();
	window->Clean();
	return 0;
}