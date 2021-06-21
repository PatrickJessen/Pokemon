#pragma once
#include "Window.h"
#include "Level.h"

class Camera
{
public:
	Camera(Window* window, Level* level, int zoomX, int zoomY);
	~Camera();

public:
	void Update();
	void SetLevel(Level* level);
	void SetTarget(SDL_Rect* target);
	SDL_Rect cam;
private:
	SDL_Rect* target;
	Window* window;
	Level* level;
};