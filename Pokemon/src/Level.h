#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include "Trainer/Trainer.h"
#include <fstream>

struct Tile
{
	int textureX;
	int textureY;
	int depth;
};

class Level
{
public:
	//Level(Window* window, const char* filePath, const char* texturePath, int col, int row, int zoneLevel, int tileSize, int zoom);
	Level() = default;
	~Level();

public:
	virtual void HandlePokeSpawns() = 0;
	void InitMap();
	virtual void InitColMap() = 0;
	void LoadMap();
	void Update();
	void CleanMap();

	SDL_Texture* loadTexture();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
protected:
	Tile* level = nullptr;
	int height;
	int width;
	int tileSize;
	int zoom;
	int zoneLevel;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	SDL_Rect moveMap;
	Window* window;
	std::vector<SDL_Rect> collisionRect;
	std::vector<Pokemon*> pokeList;
	std::map<int, std::vector<Pokemon*>> pokeSpawn;
	const char* filePath;
	const char* colMap;
	const char* texturePath;
	Trainer* trainer;
};