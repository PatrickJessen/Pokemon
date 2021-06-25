#include "PalletTown.h"
#include "ProfOakLab.h"
#include "../../GUI/GUI.h"
#include "../../Pokemon/Charmander.h"
#include "../../Pokemon/Bulbasaur.h"
#include "../../Pokemon/Squirtle.h"

PalletTown::PalletTown(Window* window, Trainer* trainer, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;
	this->zoom = zoom;
	this->trainer = trainer;
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(21 * zoom, 22 * zoom)});
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(12 * zoom, 6 * zoom)});
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(12 * zoom, 22 * zoom)});

	camera = new Camera(window, trainer, zoom, tileSize);

	//HandlePokeSpawns();
}

PalletTown::~PalletTown()
{
	std::cout << "destroyed\n";
	//CleanMap();
	delete UpdateLevel();
}

void PalletTown::HandlePokeSpawns()
{
	
}

Level* PalletTown::UpdateLevel()
{
	int x = LoadNewLevel(camera->cam.x, camera->cam.y);
	switch (x)
	{
	case 0:
	{
		oakLab = new ProfOakLab(window, trainer, "Assets/Map/Pallet Town/OakLab.map", "Assets/Map/Pallet Town/oakroom.bmp", 1, 27, 27, 32, 1);
		//trainer->SetXYPos(1000, 700);
		oakLab->trainer->GetTrainerPos().x = 500;
		oakLab->trainer->GetTrainerPos().y = 100;
		return oakLab;
	}
	break;
	/*case 1:
	{
		std::cout << "garys house\n";
		
	}
	break;
	case 2:
	{
		std::cout << "ash house\n";
		
	}
	break;*/
	}
	return nullptr;
}

void PalletTown::CustomMapUpdate()
{
	camera->Update();
	if (trainer->starterPokemon != NULL && trainer->GetTileY(tileSize) + camera->cam.y / tileSize <= 5)
	{
		if (gary == nullptr)
		{
			gary = new Trainer(window, "gary", "Assets/Trainers/Gary.png", -100, -100, 62, 62, 0);
			gary->SetSrcRect(0, 73, 50, 55);
			gary->SetXYPos(trainer->xPos, 900);
			AddGaryPoke();
			gary->UpdateTrainer();
		}
		/*while (camera->cam.y != gary->yPos)
		{
			camera->cam.y--;
			window->Update();
			SDL_Delay(2);
		}*/
		camera->SetTarget(gary);
		gary->DrawTrainer(camera->cam.x, camera->cam.y);
		if (gary->yPos > trainer->yPos + trainer->GetHeight())
		{
			trainer->movementIsDisabled = true;
			gary->yPos--;
			SDL_Delay(5);
		}
		else
		{
			GUI::MessageBox("Get ready for battle!");
			if (Input::KeyPressed(Key::SPACE))
			{
				while (true) //<-- victory || !victory
				{
					Battle();
				}
			}
			trainer->movementIsDisabled = false;
		}
	}
	else
		trainer->movementIsDisabled = false;


	//std::cout << trainer->GetTileX(tileSize) + camera->cam.x / tileSize << ", " << trainer->GetTileY(tileSize) + camera->cam.y / tileSize << "\n";
}

void PalletTown::NewTrainerPosition()
{
	
	//trainer->SetXYPos(500 - camera.x, 500 - camera.y);
}

void PalletTown::AddGaryPoke()
{
	if (trainer->starterPokemon == "Charmander")
	{
		gary->pokebag[0] = new Bulbasaur(window, "Assets/Pokemons/Front/Squirtle.png", "Squirtle", Type::GRASS, 5);
	}
	else if (trainer->starterPokemon == "Squirtle")
	{
		gary->pokebag[0] = new Charmander(window, "Assets/Pokemons/Front/Bulbasaur.png", "Bulbasaur", Type::FIRE, 5);
	}
	else if (trainer->starterPokemon == "Bulbasaur")
	{
		gary->pokebag[0] = new Squirtle(window, "Assets/Pokemons/Front/Charmander.png", "Charmander", Type::WATER, 5);
	}
}