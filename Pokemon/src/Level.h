#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include "Trainer/Trainer.h"
#include <fstream>

enum class TileType
{
	Depth, Water, Collision, Door, Exit, Grass, TallGrass, Grave, Sand, Rock, DeepWater, Ice, Waterfall
};

struct Tile
{
	int textureX;
	int textureY;
	TileType type;
};

class Level
{
public:
	//Level(Window* window, const char* filePath, const char* texturePath, int col, int row, int zoneLevel, int tileSize, int zoom);
	Level() = default;
	~Level();

public:
	virtual void HandlePokeSpawns() = 0;
	virtual void LoadNewLevel() = 0;
	void InitMap();
	void LoadLayers();
	void Update();
	void CleanMap();
	void MovePlayer();
	SDL_Texture* loadTexture();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
protected:
	Tile** level;
	int tileSize;
	int width;
	int height;
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