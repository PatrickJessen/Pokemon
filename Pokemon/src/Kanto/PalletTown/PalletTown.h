#pragma once
#include "../../Level.h"


enum class CollisionType
{
	Normal = 385,
	HomeDoor = 391,
	CousinDoor = 390,
	OakLab = 387,
	Water = 386,
	ExitWater = 389,
	NormalExit = 388
};

class PalletTown : public Level
{
public:
	PalletTown(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom);
	~PalletTown();

public:
	virtual void HandlePokeSpawns() override;
	virtual void LoadNewLevel() override;
	void EnterOakLab();

};

