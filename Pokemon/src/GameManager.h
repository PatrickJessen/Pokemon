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
	void MovePlayer();
	void CameraControl();
	bool IsPlayerMidScreen();
public:
	Level* level;
	Trainer* trainer;
	Camera* camera;
private:
	Window* window;
};

