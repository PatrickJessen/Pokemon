#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include <fstream>

class Level
{
public:
	//Level(Window* window, const char* filePath, const char* texturePath, int col, int row, int zoneLevel, int tileSize, int zoom);
	Level() = default;
	~Level();

public:
	virtual void HandlePokeSpawns() = 0;
	virtual void InitMap() = 0;
	virtual void LoadMap() = 0;
	void CleanMapArr();

	SDL_Texture* loadTexture();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
protected:
	int tileSize;
	int zoom;
	int zoneLevel;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	Window* window;
	std::vector<Pokemon*> pokeList;
	std::map<int, std::vector<Pokemon*>> pokeSpawn;
	const char* filePath;
	const char* texturePath;

	int tileCounterX = 43;
	int tileCounterY = 8;
};