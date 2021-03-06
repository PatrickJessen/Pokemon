#pragma once
#include "Window.h"
#include "Pokemon/Pokemon.h"
#include "Trainer/Trainer.h"
#include <fstream>
#include "Vector2.h"
#include "Sprite.h"
#include "Collision.h"
#include "Input.h"
#include "Camera.h"
#include "GUI/GUI.h"

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
	int LoadNewLevel(int camX, int camY);
	virtual Level* UpdateLevel() = 0;
	virtual void CustomMapUpdate() = 0;
	virtual void NewTrainerPosition() = 0;
	void InitMap();
	void LoadLayers();
	void DrawBackground();
	void DrawDepth();
	void UpdateBackground();
	void UpdateForeground();
	void CleanMap();

	void Battle();
	void ShowFirstAvailablePokemon();
	void Attack();
	void BattleUIController();

	void SpawnPokemon();

	SDL_Texture* tex = nullptr;
	Trainer* trainer;
	Trainer* gary = nullptr;
	int tileSize;
	Tile** level;
	int windowWidth;
	int windowHeight;
	int zoom;
	SDL_Rect dstRect;
	SDL_Rect srcRect;
	Sprite* sprite;
	Camera* camera = nullptr;

	bool pokeIsInBattle = false;
protected:
	Window* window;
	/*std::vector<Pokemon*> pokeList;
	std::map<int, std::vector<Pokemon*>> pokeSpawn;*/
	std::map<int, std::vector<Vector2>> doorsPosition;
	int width;
	int height;
	int zoneLevel;
	const char* filePath;
	const char* texturePath;
	bool isBattleOver = false;
	
private:
	bool showMoves = false;
};