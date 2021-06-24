#pragma once
#include "Window.h"
#include "Trainer/Trainer.h"

class Camera
{
public:
	Camera(Window* window, Trainer* trainer, int zoom, int tileSize);
	~Camera();

public:
	void Update();
	SDL_Rect* SetCamera();
	//void SetLevel(Level* level);
	void SetTarget(Trainer* target);
	SDL_Rect cam;
	SDL_Rect point;
private:
	SDL_Rect* target;
	Window* window;
	Trainer* trainer = nullptr;
	int tileSize;
	//Level* level;
};