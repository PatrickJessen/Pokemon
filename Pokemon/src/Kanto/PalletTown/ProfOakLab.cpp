#include "ProfOakLab.h"
#include "PalletTown.h"

ProfOakLab::ProfOakLab(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;
	this->zoom = zoom;
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(39, 26), Vector2(39, 27), Vector2(39, 28), Vector2(39, 29), Vector2(39, 30), Vector2(39, 31)});

	//InitMap();
	//HandlePokeSpawns();
}

ProfOakLab::~ProfOakLab()
{
	std::cout << "destroyed\n";
	CleanMap();
	delete UpdateLevel();
}

void ProfOakLab::HandlePokeSpawns()
{

}

Level* ProfOakLab::UpdateLevel()
{
	int x = LoadNewLevel();
	switch (x)
	{
	case 0:
	{
		palletTown = new PalletTown(window, "Assets/Map/Pallet Town/PalletMap.map", "Assets/Map/Pallet Town/pt.bmp", 1, 46, 46, 16, 1);

		//palletTown->tex = palletTown->loadTexture();
		return palletTown;
	}
	break;
	/*case 1:
	{
		std::cout << "garys house\n";
		InitMap();
		tex = loadTexture();
	}
	break;
	case 2:
	{
		std::cout << "ash house\n";
		InitMap();
		tex = loadTexture();
	}
	break;*/
	}
	return nullptr;
}
