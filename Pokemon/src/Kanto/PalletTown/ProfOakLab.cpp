#include "ProfOakLab.h"
#include "PalletTown.h"
#include "../../Pokemon/Charmander.h"
#include "../../Pokemon/Bulbasaur.h"
#include "../../Pokemon/Squirtle.h"

ProfOakLab::ProfOakLab(Window* window, Trainer* trainer, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom)
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
	//doorsPosition.emplace(0, std::vector<Vector2> {Vector2(13, 25), Vector2(14, 25), Vector2(15, 25), Vector2(16, 25)});
	doorsPosition.emplace(0, std::vector<Vector2> {Vector2(25, 13), Vector2(25, 14), Vector2(25, 15), Vector2(25, 16)});
	sprite = new Sprite("Assets/Items/pokeball.png", window);
	pokemon = new Sprite("Nihility", window);

	ballRect1 = { 590, 390, 40, 40 };
	ballRect2 = { 650, 390, 40, 40 };
	ballRect3 = { 710, 390, 40, 40 };

	camera = new Camera(window, trainer, zoom, tileSize);

	profOak = new Trainer(window, "Prof. Oak,", "Assets/Trainers/ProOak.png", 350, 200, 60, 60, 0);
	profOak->SetSrcRect(0, 73, 50, 55);
	//camera = { 0, 0, tileSize * zoom, tileSize * zoom };
	//InitMap();
	//HandlePokeSpawns();
}

ProfOakLab::~ProfOakLab()
{
	std::cout << "destroyed\n";
	delete sprite;
	//CleanMap();
	delete UpdateLevel();
	delete profOak;
}

void ProfOakLab::HandlePokeSpawns()
{
	/*Pokemon Bulbasaur(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5);
	Bulbasaur.InitStats(100, 100, 100, 100, 100, 100);*/

	/*pokeSpawn.emplace(100, std::vector<Pokemon*> {new Pokemon(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5),
												  new Pokemon(window, "Assets/Pokemons/Charmander.png", "Charmander", Type::FIRE, 5),
												  new Pokemon(window, "Assets/Pokemons/Squirtle.png", "Squirtle", Type::WATER, 5)});*/
}

Level* ProfOakLab::UpdateLevel()
{
	int x = LoadNewLevel(camera->cam.x, camera->cam.y);
	switch (x)
	{
	case 0:
	{
		palletTown = new PalletTown(window, trainer, "Assets/Map/Pallet Town/PalletTown.map", "Assets/Map/Pallet Town/Pallet_Town.bmp", 1, 31, 31, 32, 2);
		
		return palletTown;
	}
	break;
	/*case 1:
	{
		std::cout << "garys house\n";
		InitMap();
		tex = loadTexture();
	}
	break;
	case 2:
	{
		std::cout << "ash house\n";
		InitMap();
		tex = loadTexture();
	}
	break;*/
	}
	return nullptr;
}

void ProfOakLab::CustomMapUpdate()
{
	PlacePokeballs();
	InteractWithPokeball();
	camera->SetCamera()->x = 0;
	camera->SetCamera()->y = 0;
	profOak->DrawTrainer(camera->cam.x, camera->cam.y);
	profOak->UpdateTrainer();

	if (trainer->yPos == profOak->yPos)
	{
		trainer->movementIsDisabled = true;
		trainer->yPos += 1;
	}
	else
		trainer->movementIsDisabled = false;

	//std::cout << trainer->GetTileY(tileSize) + camera->cam.x / tileSize << ", " << profOak->GetTileY(tileSize) + camera->cam.x / tileSize << "\n";
}

void ProfOakLab::NewTrainerPosition()
{
	trainer->SetXYPos(300, 500);
}

void ProfOakLab::PlacePokeballs()
{
	if (trainer->starterPokemon == "Charmander")
	{
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect1);
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect2);
	}
	else if (trainer->starterPokemon == "Squirtle")
	{
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect1);
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect3);
	}
	else if (trainer->starterPokemon == "Bulbasaur")
	{
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect3);
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect2);
	}
	else
	{
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect1);
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect3);
		SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &ballRect2);
	}
}

void ProfOakLab::InteractWithPokeball()
{
	if (trainer->starterPokemon == NULL)
	{

		pokemonRect = { window->GetWidth() / 3, window->GetHeight() / 3, 300, 300 };
		if (Collision::AABB(trainer->GetInteractRect(), ballRect3) && Input::KeyPressed(Key::E))
		{
			pokemon->ChangeSprite("Assets/Pokemons/Front/Charmander.png");
			ChoosePokemon("Charmander");
		}
		else if (Collision::AABB(trainer->GetInteractRect(), ballRect2) && Input::KeyPressed(Key::E))
		{
			pokemon->ChangeSprite("Assets/Pokemons/Front/Squirtle.png");
			ChoosePokemon("Squirtle");
		}
		else if (Collision::AABB(trainer->GetInteractRect(), ballRect1) && Input::KeyPressed(Key::E))
		{
			pokemon->ChangeSprite("Assets/Pokemons/Front/Bulbasaur.png");
			ChoosePokemon("Bulbasaur");
		}
	}
	else if (Collision::AABB(trainer->GetInteractRect(), ballRect3) && Input::KeyPressed(Key::E) || Collision::AABB(trainer->GetInteractRect(), ballRect2) && Input::KeyPressed(Key::E) || Collision::AABB(trainer->GetInteractRect(), ballRect1) && Input::KeyPressed(Key::E))
	{
		while (!Input::KeyPressed(Key::SPACE))
		{
			GUI::MessageBox("Better not be greedy!");
			window->Update();
		}
	}
}

void ProfOakLab::ChoosePokemon(const char* name)
{
	SDL_RenderCopy(window->GetRender(), pokemon->tex, NULL, &pokemonRect);
	while (true)
	{
		if (Input::KeyPressed(Key::Y))
		{
			std::cout << "you chose " << name << "\n";
			for (int i = 0; i < 5; i++)
			{
				if (trainer->pokebag[i] == NULL && !hasBeenChosen)
				{
					Pokemon* poke = CreateStarterPokemon(name);
					trainer->pokebag[i] = poke;
					trainer->pokebag[i]->OnPokemonCreate();
					trainer->starterPokemon = name;
					hasBeenChosen = true;
				}
			}
			break;
		}
		else if (Input::KeyPressed(Key::N))
		{
			break;
		}
		window->Update();
	}
}

Pokemon* ProfOakLab::CreateStarterPokemon(std::string name)
{
	if (name == "Charmander")
	{
		return new Charmander(window, pokemon->GetPath(), name, Type::FIRE, 5);
	}
	else if (name == "Squirtle")
	{
		return new Squirtle(window, pokemon->GetPath(), name, Type::WATER, 5);
	}
	else if (name == "Bulbasaur")
	{
		return new Bulbasaur(window, pokemon->GetPath(), name, Type::GRASS, 5);
	}
	return nullptr;
}
