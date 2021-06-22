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
    trainer->UpdateTrainer();
    MoveCamera();
    MovePlayer();
    level->UpdateForeground();
}

void GameManager::MoveCamera()
{
    if (IsPlayerMidScreen())
    {

        ////level->camera = { trainer->xPos - window->GetWidth() / 2, trainer->yPos - window->GetHeight() / 2, level->tileSize * level->zoom, level->tileSize * level->zoom };
        if (Input::KeyState(Key::W))
        {
            if (level->level[(trainer->collisionPoint.y / level->tileSize / level->zoom)][trainer->collisionPoint.x / level->tileSize / level->zoom].type != TileType::Collision)
            {
                //trainer->yPos--;
                level->camera.y++;
                //midScreenRect.y--;
            }
        }
        else if (Input::KeyState(Key::S))
        {
            if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom + 1][trainer->collisionPoint.x / level->tileSize / level->zoom].type != TileType::Collision)
            {
                //trainer->yPos++;
                level->camera.y--;
                //midScreenRect.y++;
            }
        }
    }
    if (IsPlayerMidScreenX())
    {

        if (Input::KeyState(Key::A))
        {
            if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom - 1].type != TileType::Collision)
            {

                //trainer->xPos--;
                level->camera.x++;
                //midScreenRect.x--;
            }
        }
        else if (Input::KeyState(Key::D))
        {
            if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom + 1].type != TileType::Collision)
            {

                //trainer->xPos++;
                level->camera.x--;
                //midScreenRect.x++;
            }
        }
    }
        ////trainer->SetXYPos(window->GetWidth() / 2, window->GetHeight() / 2);
        trainer->GetTrainerPos() = { trainer->xPos - level->camera.x, trainer->yPos - level->camera.y, 62, 62 };
        //std::cout << trainer->GetTileX(level->tileSize) << ", " << trainer->GetTileY(level->tileSize) << "\n";
}

void GameManager::MovePlayer()
{
    if (!IsPlayerMidScreen())
    {
        if (Input::KeyState(Key::W))
        {
            if (level->level[(trainer->collisionPoint.y / level->tileSize / level->zoom)][trainer->collisionPoint.x / level->tileSize / level->zoom].type != TileType::Collision)
            {
                trainer->yPos--;
                midScreenRect.y--;

                if (midScreenRect.y > 0 && midScreenRect.y < window->GetHeight() / 2)
                    level->camera.y++;
            }
        }
        else if (Input::KeyState(Key::S))
        {
            if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom + 1][trainer->collisionPoint.x / level->tileSize / level->zoom].type != TileType::Collision)
            {
                trainer->yPos++;
                midScreenRect.y++;
                if (midScreenRect.y > window->GetHeight() && midScreenRect.y < window->GetHeight())
                    level->camera.y--;
            }
        }
    }
    if (!IsPlayerMidScreenX())
    {

        if (Input::KeyState(Key::A))
        {
            if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom - 1].type != TileType::Collision)
            {
                trainer->xPos--;
                midScreenRect.x--;
                if (midScreenRect.x > 0 && midScreenRect.x < window->GetWidth() / 2)
                    level->camera.x++;
            }
        }
        else if (Input::KeyState(Key::D))
        {
            if (level->level[trainer->collisionPoint.y / level->tileSize / level->zoom][trainer->collisionPoint.x / level->tileSize / level->zoom + 1].type != TileType::Collision)
            {

                trainer->xPos++;
                midScreenRect.x++;
                if (midScreenRect.x > window->GetWidth() && midScreenRect.x < window->GetWidth())
                    level->camera.x--;
            }
        }
    }
}

bool GameManager::IsCameraOutOfBounce()
{
    if (level->camera.x > 0)
    {
        level->camera.x = 0;
        return true;
    }
    else if (level->camera.y > 0)
    {
        level->camera.y = 0;
        return true;
    }
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
    SDL_RenderDrawRect(window->GetRender(), &midScreenRect);
    if (midScreenRect.y == window->GetHeight() / 2  && !IsCameraOutOfBounce())
    {
        //midScreenRect = { window->GetWidth() / 2, window->GetHeight() / 2, trainer->GetWidth(), trainer->GetHeight() };
        //std::cout << level->camera.w / 2 << ", " << level->camera.h / 2 << " : " << trainer->collisionPoint.x << ", " << trainer->collisionPoint.y << "\n";
        return true;
    }
    //if (trainer->GetXPos() == trainer->xPos - window->GetWidth() / 2 && trainer->GetYPos() == trainer->yPos - window->GetHeight() / 2)
    //{
    //    //trainer->GetTrainerPos() = { trainer->xPos - level->camera.x, trainer->yPos - level->camera.y, 62, 62 };
    //    return true;
    //}
    return false;
}

bool GameManager::IsPlayerMidScreenX()
{
    SDL_RenderDrawRect(window->GetRender(), &midScreenRect);
    if (midScreenRect.x == window->GetWidth() / 2 && !IsCameraOutOfBounce())
    {
        //midScreenRect = { window->GetWidth() / 2, window->GetHeight() / 2, trainer->GetWidth(), trainer->GetHeight() };
        //std::cout << level->camera.w / 2 << ", " << level->camera.h / 2 << " : " << trainer->collisionPoint.x << ", " << trainer->collisionPoint.y << "\n";
        return true;
    }
    //if (trainer->GetXPos() == trainer->xPos - window->GetWidth() / 2 && trainer->GetYPos() == trainer->yPos - window->GetHeight() / 2)
    //{
    //    //trainer->GetTrainerPos() = { trainer->xPos - level->camera.x, trainer->yPos - level->camera.y, 62, 62 };
    //    return true;
    //}
    return false;
}

bool GameManager::InRange(unsigned low, unsigned high)
{
    return ((low) <= (high));
}
