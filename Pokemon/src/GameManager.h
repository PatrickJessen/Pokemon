#pragma once
#include "Level.h"

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
private:
	Window* window;
};

