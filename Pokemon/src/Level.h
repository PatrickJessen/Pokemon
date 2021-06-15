#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include "Trainer/Trainer.h"
#include <fstream>

struct Tile
{
	int textureX;
	int textureY;
	bool depth = false;
	bool water = false;
	bool collision = false;
	bool labDoor = false;
	bool houseDoor = false;
	bool houseDoor2 = false;
	bool exit = false;
	bool exit2 = false;
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
	void LoadLayers();
	void Update();
	void CleanMap();
	void MovePlayer();
	SDL_Texture* loadTexture();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
protected:
	Tile* level = nullptr;
	int tileSizeX;
	int tileSizeY;
	int tileSize = 16;
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