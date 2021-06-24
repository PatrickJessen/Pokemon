#pragma once
#include "../../Level.h"

class PalletTown : public Level
{
public:
	PalletTown(Window* window, Trainer* trainer, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom);
	~PalletTown();

public:
	virtual void HandlePokeSpawns() override;
	virtual Level* UpdateLevel() override;
	virtual void CustomMapUpdate() override;
	virtual void NewTrainerPosition() override;

	void AddGaryPoke();

	Level* oakLab = nullptr;
};

