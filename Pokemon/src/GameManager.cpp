#include "GameManager.h"

GameManager::GameManager(Window* window)
{
    this->window = window;
    trainer = new Trainer(window, "Ash", "Assets/Trainers/MainTrainer.png", window->GetWidth() / 2, window->GetHeight() / 2, 62, 62, 100);
    GUI::Init(window, trainer);
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
    MovePlayer();
	level->UpdateBackground();
    trainer->DrawTrainer(level->camera->cam.x, level->camera->cam.y);
    trainer->UpdateTrainer();
    level->UpdateForeground();
    GUI::MainMenu();
    //GUI::BattleSceneGUI(trainer, trainer);
    //GUI::ChangeFontSize(window->GetWidth() / 2 - 210, window->GetHeight() - 100, 300, 100);
    //GUI::MessageBox("Hello World!");
}

void GameManager::MovePlayer()
{
    //(trainer->xPos - level->camera->cam.x) / level->tileSize / level->zoom;
    //(trainer->yPos - level->camera->cam.y) / level->tileSize / level->zoom;
    int y = trainer->collisionPoint.y / level->tileSize / level->zoom;
    int x = trainer->collisionPoint.x / level->tileSize / level->zoom;
    int tileX = level->camera->cam.x / level->tileSize / 2;
    int tileY = level->camera->cam.y / level->tileSize / 2;
    if (!trainer->movementIsDisabled)
    {
        if (Input::KeyState(Key::W))
        {
            if (level->level[(y)+(tileY)][(x)+(tileX)].type != TileType::Collision)
            {
                trainer->yPos--;
            }
        }
        else if (Input::KeyState(Key::S))
        {
            if (level->level[(y + 1) + (tileY)][(x)+(tileX)].type != TileType::Collision)
            {
                trainer->yPos++;
            }
        }
        else if (Input::KeyState(Key::A))
        {
            if (level->level[(y)+(tileY)][(x - 1) + (tileX)].type != TileType::Collision)
            {
                trainer->xPos--;
            }
        }
        else if (Input::KeyState(Key::D))
        {
            if (level->level[(y)+(tileY)][(x + 1) + (tileX)].type != TileType::Collision)
            {
                trainer->xPos++;
            }
        }
    }
    //std::cout << trainer->GetTileX(level->tileSize) << ", " << trainer->GetTileX(level->tileSize) << "\n";
    //trainer->GetTrainerPos() = { trainer->GetXPos() - level->camera->cam.x, trainer->GetYPos() - level->camera->cam.y, 62, 62 };
}

bool GameManager::InRange(unsigned low, unsigned high)
{
    return ((low) <= (high));
}
