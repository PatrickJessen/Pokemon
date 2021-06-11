#include "PalletTown.h"

PalletTown::PalletTown(Window* window, const char* filePath, const char* texturePath, int width, int height, int zoneLevel, int tileSize, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->tileSize = tileSize;
	this->zoom = zoom;
	this->width = width;
	this->height = height;
	
	InitMap();
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