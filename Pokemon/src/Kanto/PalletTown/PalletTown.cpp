#include "PalletTown.h"
#include "ProfOakLab.h"

PalletTown::PalletTown(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;
	this->zoom = zoom;

	trainer = new Trainer(window, "Ash", "Assets/Trainers/MainTrainer.png", 200, 250, 62, 62);
	
	InitMap();
	HandlePokeSpawns();
}

PalletTown::~PalletTown()
{
	
}

void PalletTown::HandlePokeSpawns()
{
	/*Pokemon Bulbasaur(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5);
	Bulbasaur.InitStats(100, 100, 100, 100, 100, 100);*/

	pokeSpawn.emplace(100, std::vector<Pokemon*> {new Pokemon(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5),
												  new Pokemon(window, "Assets/Pokemons/Charmander.png", "Charmander", Type::FIRE, 5),
												  new Pokemon(window, "Assets/Pokemons/Squirtle.png", "Squirtle", Type::WATER, 5)});
}

void PalletTown::LoadNewLevel()
{
	if (level[trainer->collisionPoint.y / tileSize][trainer->collisionPoint.x / tileSize].type == TileType::Door)
	{
		std::cout << "test\n";
		EnterOakLab();
	}
}

void PalletTown::EnterOakLab()
{
	Level* oakLab = new ProfOakLab(window, this->filePath = "Assets/Map/Pallet Town/OakLab.map", this->texturePath = "Assets/Map/Pallet Town/OakLab.bmp", this->zoneLevel = 1, this->width = 60, this->height = 60, this->tileSize = 16, this->zoom = 1);
	//oakLab->Update();
	//filePath = "Assets/Map/Pallet Town/OakLab.map";
	//texturePath = "Assets/Map/Pallet Town/OakLab.bmp";
	//zoneLevel = 1;
	//width = 60;
	//height = 60;
	//tileSize = 16;
	//zoom = 1;
	InitMap();
	tex = loadTexture();
}