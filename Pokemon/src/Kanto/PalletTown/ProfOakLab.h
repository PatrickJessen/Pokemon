#pragma once
#include "../../Level.h"

class ProfOakLab : public Level
{
public:
	ProfOakLab(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom);
	~ProfOakLab();

public:
	virtual void HandlePokeSpawns() override;
	virtual Level* UpdateLevel() override;

	Level* palletTown = nullptr;
};

