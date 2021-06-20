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
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(21, 22)});
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(12, 6)});
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(12, 22)});
	//doorsPosition.emplace(0, std::vector<Vector2> {Vector2(22, 21), Vector2(25, 32)});
	//doorsPosition.emplace(1, std::vector<Vector2> {Vector2(13, 30), Vector2(13, 29)});
	//doorsPosition.emplace(2, std::vector<Vector2> {Vector2(13, 12), Vector2(13, 11)});
	//trainer = new Trainer(window, "Ash", "Assets/Trainers/MainTrainer.png", 200, 250, 62, 62);
	
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
	/*Pokemon Bulbasaur(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5);
	Bulbasaur.InitStats(100, 100, 100, 100, 100, 100);*/

	/*pokeSpawn.emplace(100, std::vector<Pokemon*> {new Pokemon(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5),
												  new Pokemon(window, "Assets/Pokemons/Charmander.png", "Charmander", Type::FIRE, 5),
												  new Pokemon(window, "Assets/Pokemons/Squirtle.png", "Squirtle", Type::WATER, 5)});*/
}

Level* PalletTown::UpdateLevel()
{
	int x = LoadNewLevel();
	switch (x)
	{
	case 0:
	{
		oakLab = new ProfOakLab(window, trainer, "Assets/Map/Pallet Town/OakLab.map", "Assets/Map/Pallet Town/oakroom.bmp", 1, 27, 27, 32, 1);
		trainer->SetXYPos(300, 700);
		return oakLab;
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

void PalletTown::CustomMapUpdate()
{
}
