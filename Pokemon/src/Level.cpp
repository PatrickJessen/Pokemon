#include "Level.h"
#include "FileHandler/simple_file_handler.h"
#define INDEX y * width + x

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
        delete level;

    level = new Tile[height * width];

    ReadFile inFile(filePath);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            level[INDEX] = inFile.ReadClass<Tile>();
            //level[INDEX].texture = inFile.ReadPrimitive<int>();
        }
    }
    inFile.Close();
}

void Level::LoadMap()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // tile position
            dstRect = { x * tileSize * zoom + moveMap.x, y * tileSize * zoom + moveMap.y, tileSize * zoom, tileSize * zoom };
            // tilenummer fra txt filen
            srcRect = { level[INDEX].textureX * tileSize, level[INDEX].textureY * tileSize, tileSize, tileSize };
            SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
        }
    }
            //std::cout << level[(trainer->GetYPos() / 2) / tileSize / zoom].textureX * tileSize << ", " << level[(trainer->GetXPos() / 2) / tileSize / zoom].textureY * tileSize << "\n";
}

void Level::Update()
{
    LoadMap();
    trainer->UpdateTrainer();
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
