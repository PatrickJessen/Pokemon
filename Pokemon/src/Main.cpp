#include "Window.h"
#include "GameManager.h"
#include "Kanto/PalletTown/PalletTown.h"

int main()
{
	Window* window = new Window("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 700, false);

	//PalletTown* palletTown = new Level(window, "Assets/Map/PalletTown.map", "Assets/Map/PalletTown.png", 100, 100, 1, 16, 3);
	GameManager* manager = new GameManager(window);

	Level* test = new PalletTown(window, manager->trainer, "Assets/Map/Pallet Town/PalletMap.map", "Assets/Map/Pallet Town/pt.bmp", 1, 46, 46, 16, 1); // 37, 22
	//test->tex = test->loadTexture();
	manager->level = test;
	manager->level->InitMap();
	while (true)
	{
		manager->Update();
		window->Update();
		window->Clear();
		SDL_Delay(1);
	}
	//test->CleanMapArr();
	window->Clean();
	return 0;
}