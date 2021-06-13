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
	int colType;
	//int trueCollition = 1;
	//int doorCollision = 2;
	//int depthCollision = 3;
	//int waterCollision = 4;
	//int exitMapCollision = 5;
	/*if coltype = collisiontype:normal
		bounce player back*/
};

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
	void Update();
	void CleanMap();

	SDL_Texture* loadTexture();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
protected:
	int tileWidth;
	int tileHeight;
	int zoom;
	int zoneLevel;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	SDL_Rect moveMap;
	Window* window;
	std::vector<Pokemon*> pokeList;
	std::map<int, std::vector<Pokemon*>> pokeSpawn;
	const char* filePath;
	const char* texturePath;
	Trainer* trainer;
};