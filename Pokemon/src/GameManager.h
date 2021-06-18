#pragma once
#include "Level.h"

class GameManager
{
public:
	GameManager(Window* window);
	~GameManager();

public:
	void Update();
	void MovePlayer();

	Level* level;
	Trainer* trainer;
private:
	Window* window;
};

