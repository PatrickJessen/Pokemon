#pragma once
#include "Level.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

public:
	void Update();

	Level* level;
private:
};

