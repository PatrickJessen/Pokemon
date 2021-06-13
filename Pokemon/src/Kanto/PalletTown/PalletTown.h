#pragma once
#include "../../Level.h"

static const int width = 46;
static const int height = 44;

enum class CollisionType
{
	Normal = 385,
	Door = 391,
	Water = 386,
	ExitWater = 389,
	NormalExit = 388
};

class PalletTown : public Level
{
public:
	PalletTown(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int tileWidth, int tileHeight, int zoom);
	~PalletTown();

public:
	virtual void HandlePokeSpawns() override;
	virtual void InitMap() override;
	virtual void LoadMap() override;

private:
	int level[width][height];
};

