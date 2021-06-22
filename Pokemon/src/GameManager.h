#pragma once
#include "Level.h"
#include "Camera.h"

class GameManager
{
public:
	GameManager(Window* window);
	~GameManager();

public:
	void Update();
private:
	void MoveCamera();
	void MovePlayer();
	bool IsCameraOutOfBounce();
	bool IsPlayerMidScreen();
	bool IsPlayerMidScreenX();
	bool InRange(unsigned low, unsigned high);
public:
	Level* level;
	Trainer* trainer;
	Camera* camera;
	SDL_Rect midScreenRect;
private:
	Window* window;
};

