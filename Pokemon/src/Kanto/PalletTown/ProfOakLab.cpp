#include "ProfOakLab.h"

ProfOakLab::ProfOakLab(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;
	this->zoom = zoom;

	InitMap();
	HandlePokeSpawns();
}

ProfOakLab::~ProfOakLab()
{
}

void ProfOakLab::HandlePokeSpawns()
{
}

void ProfOakLab::LoadNewLevel()
{
}
