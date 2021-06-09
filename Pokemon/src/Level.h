#pragma once
#include "Window.h"

class Level
{
public:
	~Level();

public:
	virtual void InitMap(Window* window, int tileSize, int zoom);
	virtual void LoadMap(const char* filePath, const char* texturePath, int width, int height);


protected:
	int tileSize;
	int zoom;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	Window* window;
};