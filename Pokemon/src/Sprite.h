#pragma once
#include "SDL_image.h"
#include "Window.h"

class Sprite
{
private:
	Window* window;

public:
	Sprite(const char* path, Window* window);
	~Sprite();

	void ChangeSprite(const char* path);

	const char* GetPath();

private:
	const char* path;

public:
	SDL_Surface* surface;
	SDL_Texture* tex;
};
