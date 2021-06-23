#pragma once
#include "Level.h"
#include "Camera.h"
#include "GUI/GUI.h"

class GameManager
{
public:
	GameManager(Window* window);
	~GameManager();

public:
	void Update();
private:
	void MovePlayer();
	bool InRange(unsigned low, unsigned high);
public:
	Level* level;
	Trainer* trainer;
	Camera* camera;
	SDL_Rect midScreenRect;
private:
	Window* window;
};

