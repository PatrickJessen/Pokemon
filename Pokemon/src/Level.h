#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include "Trainer/Trainer.h"
#include <fstream>
#include "Vector2.h"
#include "Sprite.h"

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
	//Level() = default;
	virtual ~Level() = 0;
	//~Level();

public:
	virtual void HandlePokeSpawns() = 0;
	int LoadNewLevel();
	virtual Level* UpdateLevel() = 0;
	void InitMap();
	void LoadLayers();
	void Update();
	void CleanMap();
	void MovePlayer();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
protected:
	Sprite* sprite;
	Tile** level;
	Trainer* trainer;
	SDL_Rect moveMap;
	Window* window;
	/*std::vector<Pokemon*> pokeList;
	std::map<int, std::vector<Pokemon*>> pokeSpawn;*/
	std::map<int, std::vector<Vector2>> doorsPosition;
	int tileSize;
	int width;
	int height;
	int zoom;
	int zoneLevel;
	const char* filePath;
	const char* texturePath;
};