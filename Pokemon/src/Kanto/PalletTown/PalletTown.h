#pragma once
#include "../../Level.h"

class PalletTown : public Level
{
public:
	PalletTown(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom);
	~PalletTown();

public:
	virtual void HandlePokeSpawns() override;
};

