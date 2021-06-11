#include "Level.h"
#include "FileHandler/simple_file_handler.h"

using namespace SimpleFileHandler;

//Level::Level(Window* window, const char* filePath, const char* texturePath, int col, int row, int zoneLevel, int tileSize, int zoom)
//	:window(window), filePath(filePath), texturePath(texturePath), col(row), zoneLevel(zoneLevel), tileSize(tileSize), zoom(zoom)
//{
//	std::ifstream fs(filePath, std::ifstream::in);
//	mapArr = new int* [row];
//	for (int i = 0; i < col; i++)
//	{
//		mapArr[i] = new int[col];
//	}
//		
//}

Level::~Level()
{
}

void Level::InitMap()
{
	if (level != nullptr)
	{
		delete level;
	}
	level = new Tile[height * width];

	ReadFile inFile(filePath);

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			level[y * width + x] = inFile.ReadClass<Tile>();
		}

	inFile.Close();
}

void Level::InitCollisionMap()
{
	/*if (colLevel != nullptr)
	{
		delete colLevel;
	}
	colLevel = new Tile[height * width];

	ReadFile inFile("Assets/Map/pt.map");

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			colLevel[y * width + x] = inFile.ReadClass<Tile>();
		}

	inFile.Close();*/
}

void Level::LoadMap()
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			dstRect = { x * tileSize * zoom + moveMap.x, y * tileSize * zoom, tileSize * zoom + moveMap.y, tileSize * zoom };
			srcRect = { level[y * width + x].textureX * tileSize, level[y * width + x].textureY * tileSize, tileSize, tileSize };
			if (level[y * width + x].textureX == 157 || level[y * width + x].textureY == 157)
			{
				std::cout << "test\n";
			}
			SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
		}
}

void Level::CleanMap()
{
	delete level;
}


SDL_Texture* Level::loadTexture()
{
    SDL_Surface* surface(SDL_LoadBMP(texturePath));
    if (surface) {
        SDL_Texture* texture(SDL_CreateTextureFromSurface(window->GetRender(), surface));
        if (texture) {
            printf("Texture loaded successfully: %s\n", texturePath);
            return texture;
        }
        printf("Failed to create texture: %s\n", texturePath);
        return nullptr;
    }
    printf("Cannot find texture file: %s\n", texturePath);
    return nullptr;
}

void Level::SpawnPokemon()
{
	int x = rand() % 100;
	for (auto item : pokeSpawn)
	{
		if (x < item.first)
		{
			std::cout << "A wild " << item.second[item.first]->GetName() << " Appeard\n";
		}
	}
}
