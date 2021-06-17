#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	delete level;
}

void GameManager::Update()
{
	Level* l = level->UpdateLevel();
	if (l != nullptr)
	{
		delete level;
		level = l;
		level->InitMap();
	}
	level->Update();
}
