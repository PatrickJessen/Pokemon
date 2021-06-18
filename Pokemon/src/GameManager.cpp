#include "GameManager.h"

GameManager::GameManager(Window* window)
{
    trainer = new Trainer(window, "Ash", "Assets/Trainers/MainTrainer.png", 200, 250, 62, 62);
}

GameManager::~GameManager()
{
	delete level;
    delete trainer;
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
	level->UpdateBackground();
    trainer->UpdateTrainer();
    MovePlayer();
    level->UpdateForeground();
}

void GameManager::MovePlayer()
{
    if (Input::KeyState(Key::W))
    {
        if (level->level[trainer->collisionPoint.y / level->tileSize - 1][trainer->collisionPoint.x / level->tileSize].type != TileType::Collision)
        {
            trainer->yPos--;
        }
    }
    else if (Input::KeyState(Key::S))
    {
        if (level->level[trainer->collisionPoint.y / level->tileSize + 1][trainer->collisionPoint.x / level->tileSize].type != TileType::Collision)
        {
            trainer->yPos++;
        }
    }
    else if (Input::KeyState(Key::A))
    {
        if (level->level[trainer->collisionPoint.y / level->tileSize][trainer->collisionPoint.x / level->tileSize - 1].type != TileType::Collision)
        {
            trainer->xPos--;
        }
    }
    else if (Input::KeyState(Key::D))
    {
        if (level->level[trainer->collisionPoint.y / level->tileSize][(trainer->collisionPoint.x / level->tileSize) + 1].type != TileType::Collision)
        {
            trainer->xPos++;
        }
    }
}
