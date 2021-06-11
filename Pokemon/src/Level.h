#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include <fstream>

enum class CollisionType
{
	Normal = 385,
	Door = 391,
	Water = 386,
	ExitWater = 389,
	NormalExit = 388
};

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
	if coltype = collisiontype:normal
		bounce player back
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
	void InitCollisionMap();
	void LoadMap();
	void CleanMap();

	SDL_Texture* loadTexture();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
protected:
	Tile* level = nullptr;
	//Tile* colLevel = nullptr;
	int width;
	int height;
	int tileSize;
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

	int tileCounterX = 43;
	int tileCounterY = 8;
};