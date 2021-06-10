#pragma once
#include "../../Level.h"

const static int col = 45;
const static int row = 40;

class PalletTown : public Level
{
public:
	PalletTown(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int tileSize, int zoom);
	~PalletTown() = default;

public:
	virtual void HandlePokeSpawns() override;
	virtual void InitMap() override;
	virtual void LoadMap() override;

private:
	int mapArr[col][row];
};

