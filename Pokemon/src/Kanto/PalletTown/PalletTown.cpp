#include "PalletTown.h"

PalletTown::PalletTown(Window* window, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSizeX, int tileSizeY, int zoom)
{
	this->window = window;
	this->filePath = filePath;
	this->texturePath = texturePath;
	this->zoneLevel = zoneLevel;
	this->width = width;
	this->height = height;
	this->tileSizeX = tileSizeX;
	this->tileSizeY = tileSizeY;
	this->zoom = zoom;

	trainer = new Trainer(window, "Ash", "Assets/Trainers/MainTrainer.png", 400, 300, 62, 62);
	
	InitMap();
	HandlePokeSpawns();
}

PalletTown::~PalletTown()
{
	
}

void PalletTown::HandlePokeSpawns()
{
	/*Pokemon Bulbasaur(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5);
	Bulbasaur.InitStats(100, 100, 100, 100, 100, 100);*/

	pokeSpawn.emplace(100, std::vector<Pokemon*> {new Pokemon(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5),
												  new Pokemon(window, "Assets/Pokemons/Charmander.png", "Charmander", Type::FIRE, 5),
												  new Pokemon(window, "Assets/Pokemons/Squirtle.png", "Squirtle", Type::WATER, 5)});
}

//void PalletTown::InitMap()
//{
//	std::ifstream fs(filePath, std::ifstream::in);
//
//	for (int y = 0; y < height; y++)
//		for (int x = 0; x < width; x++)
//		{
//			fs >> level[y][x];
//		}
//	fs.close();
//}

//void PalletTown::LoadMap()
//{
//	for (int y = 0; y < height; y++)
//		for (int x = 0; x < width; x++)
//		{		
//			dstRect = { x * tileSize * zoom + moveMap.x, y * tileSize * zoom + moveMap.y, tileSize * zoom, tileSize * zoom };
//			srcRect = { level[y][x] * tileSize, x * tileSize, tileSize, tileSize };
//			SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
//		}
//
//	SDL_Rect test2 = { trainer->GetXPos() + trainer->GetWidth() / 2, trainer->GetYPos() + trainer->GetHeight() / 2, trainer->GetWidth() / 2, trainer->GetHeight() / 2 };
//	SDL_SetRenderDrawColor(window->GetRender(), 0, 255, 0, 255);
//	SDL_RenderFillRect(window->GetRender(), &test2);
//	std::cout << level[(trainer->GetYPos() + trainer->GetHeight() / 2) / tileHeight / zoom][(trainer->GetXPos() + trainer->GetWidth() / 2) / tileWidth / zoom] << "\n";
//	if (level[(trainer->GetYPos() + trainer->GetHeight() / 2) / tileHeight / zoom][(trainer->GetXPos() + trainer->GetWidth() / 2) / tileWidth / zoom] == (int)CollisionType::HomeDoor)
//	{
//		std::cout << "test\n";
//	}
//}
