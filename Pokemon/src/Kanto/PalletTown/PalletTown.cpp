#include "PalletTown.h"
#include "ProfOakLab.h"

PalletTown::PalletTown(Window* window, Trainer* trainer, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;
	this->zoom = zoom;
	this->trainer = trainer;
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(21 * zoom, 22 * zoom)});
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(12 * zoom, 6 * zoom)});
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(12 * zoom, 22 * zoom)});

	isFullMap = false;
	camera = new Camera(window, trainer, zoom, tileSize);
	//HandlePokeSpawns();
}

PalletTown::~PalletTown()
{
	std::cout << "destroyed\n";
	//CleanMap();
	delete UpdateLevel();
}

void PalletTown::HandlePokeSpawns()
{
	
}

Level* PalletTown::UpdateLevel()
{
	int x = LoadNewLevel(camera->cam.x, camera->cam.y);
	switch (x)
	{
	case 0:
	{
		oakLab = new ProfOakLab(window, trainer, "Assets/Map/Pallet Town/OakLab.map", "Assets/Map/Pallet Town/oakroom.bmp", 1, 27, 27, 32, 1);
		//trainer->SetXYPos(1000, 700);
		oakLab->trainer->GetTrainerPos().x = 500;
		oakLab->trainer->GetTrainerPos().y = 100;
		return oakLab;
	}
	break;
	/*case 1:
	{
		std::cout << "garys house\n";
		
	}
	break;
	case 2:
	{
		std::cout << "ash house\n";
		
	}
	break;*/
	}
	return nullptr;
}

void PalletTown::CustomMapUpdate()
{
	camera->Update();
}

void PalletTown::NewTrainerPosition()
{
	
	//trainer->SetXYPos(500 - camera.x, 500 - camera.y);
}
