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
        level->NewTrainerPosition();
	}
	level->UpdateBackground();
    trainer->DrawTrainer(level->camera->cam.x, level->camera->cam.y);
    trainer->UpdateTrainer();
    MoveCamera();
    MovePlayer();
    level->UpdateForeground();
}

void GameManager::MoveCamera()
{
    
}

void GameManager::MovePlayer()
{
    int y = trainer->collisionPoint.y / level->tileSize / level->zoom;
    int x = trainer->collisionPoint.x / level->tileSize / level->zoom;
    int tileX = level->camera->cam.x / level->tileSize / 2;
    int tileY = level->camera->cam.y / level->tileSize / 2;
    if (Input::KeyState(Key::W))
    {
        if (level->level[(y) - (tileY)][(x) - (tileX) +1].type != TileType::Collision)
        {
            trainer->yPos++;
        }
    }
    else if (Input::KeyState(Key::S))
    {
        if (level->level[(y + 1) - (tileY)][(x) - (tileX)].type != TileType::Collision)
        {
            trainer->yPos--;
        }
    }
    else if (Input::KeyState(Key::A))
    {
        if (level->level[(y) - (tileY)][(x - 1) - (tileX)].type != TileType::Collision)
        {
            trainer->xPos++;
        }
    }
    else if (Input::KeyState(Key::D))
    {
        if (level->level[(y) -(tileY)][(x + 1) - (tileX)].type != TileType::Collision)
        {

            trainer->xPos--;
        }
    }

    //trainer->GetTrainerPos() = { trainer->GetXPos() - level->camera->cam.x, trainer->GetYPos() - level->camera->cam.y, 62, 62 };
}

bool GameManager::IsCameraOutOfBounce()
{
    /*if (level->camera.x > 0)
    {
        level->camera.x = 0;
        return true;
    }
    else if (level->camera.y > 0)
    {
        level->camera.y = 0;
        return true;
    }*/
    /*else if (level->camera.y > level->camera.h / 2)
    {
        level->camera.y = level->camera.h / 2;
        return true;
    }
    else if (level->camera.x > level->camera.w / 2)
    {
        level->camera.x = level->camera.w / 2;
        return true;
    }*/
    return false;
}

bool GameManager::IsPlayerMidScreen()
{
    
    if (trainer->GetXPos() == trainer->xPos - window->GetWidth() / 2 && trainer->GetYPos() == trainer->yPos - window->GetHeight() / 2)
    {
        //trainer->GetTrainerPos() = { trainer->xPos - level->camera.x, trainer->yPos - level->camera.y, 62, 62 };
        return true;
    }
    return false;
}

bool GameManager::InRange(unsigned low, unsigned high)
{
    return ((low) <= (high));
}
