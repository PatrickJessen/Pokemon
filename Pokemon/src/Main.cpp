#include "Window.h"
#include "Kanto/PalletTown/PalletTown.h"

int main()
{
	Window* window = new Window("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1702, 915, false);

	//PalletTown* palletTown = new Level(window, "Assets/Map/PalletTown.map", "Assets/Map/PalletTown.png", 100, 100, 1, 16, 3);

	Level* test = new PalletTown(window, "Assets/Map/originMapCol.map", "Assets/Map/pt.bmp", 1, 46, 46, 16, 16, 1); // 37, 22
	test->tex = test->loadTexture();

	while (true)
	{
		test->Update();
		window->Update();
		window->Clear();
		SDL_Delay(1);
	}
	//test->CleanMapArr();
	window->Clean();
	return 0;
}