#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"

class Level
{
public:
	Level(Window* window, const char* filePath, const char* texturePath, int col, int row, int zoneLevel, int tileSize, int zoom);
	~Level();

public:
	virtual void HandlePokeSpawns() = 0;
	void LoadMap();
	void CleanMapArr();

	SDL_Texture* loadTexture();

	void SpawnPokemon();



protected:
	int col;
	int row;
	int** mapArr;
	int tileSize;
	int zoom;
	int zoneLevel;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	Window* window;
	std::map<int, std::vector<Pokemon*>> pokeSpawn;
	const char* filePath;
	const char* texturePath;
};