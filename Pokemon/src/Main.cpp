#include "Window.h"
#include "GameManager.h"
#include "Kanto/PalletTown/PalletTown.h"
#include "Camera.h"

int main()
{
	Window* window = new Window("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1700, 900, false);

	GameManager* manager = new GameManager(window);

	Level* test = new PalletTown(window, manager->trainer, "Assets/Map/Pallet Town/PalletTown.map", "Assets/Map/Pallet Town/Pallet_Town.bmp", 1, 31, 31, 32, 2); // 37, 22

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