#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include "Trainer/Trainer.h"
#include <fstream>
#include "Vector2.h"
#include "Sprite.h"
#include "Collision.h"
#include "Input.h"

enum class TileType
{
	Depth, Water, Collision, Door, Exit, Grass, TallGrass, Grave, Sand, Rock, DeepWater, Ice, Waterfall, test
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
	virtual void CustomMapUpdate() = 0;
	void InitMap();
	void LoadLayers();
	void DrawBackground();
	void DrawDepth();
	void UpdateBackground();
	void UpdateForeground();
	void CleanMap();
	void MovePlayer();

	void SpawnPokemon();

	SDL_Rect camera;
	SDL_Texture* tex = nullptr;
	Trainer* trainer;
	int tileSize;
	Tile** level;
	int windowWidth;
	int windowHeight;
	int zoom;
	SDL_Rect dstRect;
	SDL_Rect srcRect;
protected:
	Sprite* sprite;
	Window* window;
	/*std::vector<Pokemon*> pokeList;
	std::map<int, std::vector<Pokemon*>> pokeSpawn;*/
	std::map<int, std::vector<Vector2>> doorsPosition;
	int width;
	int height;
	int zoneLevel;
	const char* filePath;
	const char* texturePath;
};