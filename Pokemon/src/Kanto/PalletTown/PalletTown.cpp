#include "PalletTown.h"



PalletTown::PalletTown(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int tileSize, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->tileSize = tileSize;
	this->zoom = zoom;
	
	InitMap();
}

void PalletTown::HandlePokeSpawns()
{
	/*Pokemon Bulbasaur(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5);
	Bulbasaur.InitStats(100, 100, 100, 100, 100, 100);*/

	pokeSpawn.emplace(100, std::vector<Pokemon*> {new Pokemon(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5),
												  new Pokemon(window, "Assets/Pokemons/Charmander.png", "Charmander", Type::FIRE, 5),
												  new Pokemon(window, "Assets/Pokemons/Squirtle.png", "Squirtle", Type::WATER, 5)});
}

void PalletTown::InitMap()
{
	std::ifstream fs(filePath, std::ifstream::in);
	for (int c = 0; c < col; c++)
		for (int r = 0; r < row; r++)
		{
			fs >> mapArr[c][r];
		}
}

void PalletTown::LoadMap()
{
	for (int c = 0; c < col; c++)
		for (int r = 0; r < row; r++)
		{
			dstRect = { r * tileSize * zoom, c * tileSize * zoom, tileSize * zoom, tileSize * zoom };
			srcRect = { mapArr[c][r] * tileSize, tileSize, tileSize, tileSize };
			SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
		}
}

