#include "GameManager.h"

GameManager::GameManager(Window* window)
{
    this->window = window;
    trainer = new Trainer(window, "Ash", "Assets/Trainers/MainTrainer.png", window->GetWidth() / 2, window->GetHeight() / 2, 62, 62, 100);
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
    CameraControl();
    level->UpdateForeground();
}

void GameManager::MovePlayer()
{
    //level->camera = { trainer->xPos - window->GetWidth() / 2, trainer->yPos - window->GetHeight() / 2, level->tileSize * level->zoom, level->tileSize * level->zoom };
    if (Input::KeyState(Key::W))
    {
        if (level->level[(trainer->collisionPoint.y / level->tileSize / level->zoom - 1)][trainer->collisionPoint.x / level->tileSize / level->zoom].type != TileType::Collision)
        {
            trainer->yPos--;
        }
    }
    else if (Input::KeyState(Key::S))
    {
        if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom + 1][trainer->collisionPoint.x / level->tileSize / level->zoom].type != TileType::Collision)
        {
            trainer->yPos++;
        }
    }
    else if (Input::KeyState(Key::A))
    {
        if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom - 1].type != TileType::Collision)
        {
            
            trainer->xPos--;
        }
    }
    else if (Input::KeyState(Key::D))
    {
        if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom + 1].type != TileType::Collision)
        {
            
            trainer->xPos++;
        }
    }
    //trainer->SetXYPos(window->GetWidth() / 2, window->GetHeight() / 2);
}

void GameManager::CameraControl()
{
    int w = level->tileSize * level->zoom;
    //std::cout << level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom].textureY << ", " << level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom].textureX << "\n";
    std::cout << level->camera.x << ", " << level->camera.y << "\n";
    //std::cout << trainer->GetXPos() << ", " << trainer->GetYPos() << "\n";
    //if (IsPlayerMidScreen())
    //{ level->camera.x = (trainer->GetXPos() + trainer->GetWidth() / 2) - window->GetWidth() / 2;
    level->camera.x = (trainer->GetXPos() + trainer->GetWidth() / 2) - window->GetWidth() / 2;
    level->camera.y = (trainer->GetYPos() + trainer->GetHeight() / 2) - window->GetHeight() / 2;
}

bool GameManager::IsPlayerMidScreen()
{
    if (trainer->GetXPos() == window->GetWidth() / 2 && trainer->GetYPos() == window->GetHeight() / 2)
    {
        return true;
    }
    return false;
}
