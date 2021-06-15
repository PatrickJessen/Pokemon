#include "Level.h"
#include "FileHandler/simple_file_handler.h"
#include "Input.h"
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

void Level::LoadLayers()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // tile position
            dstRect = { x * tileSizeX * zoom + moveMap.x, y * tileSizeY * zoom + moveMap.y, tileSizeX * zoom, tileSizeY * zoom };
            // tilenummer fra txt filen
            srcRect = { level[INDEX].textureX * tileSizeX, level[INDEX].textureY * tileSizeY, tileSizeX, tileSizeY };
            if (!level[INDEX].depth)
            {
                SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
            }
            if (level[INDEX].collision)
            {
                SDL_Rect testing = { level[INDEX].textureX * tileSize, level[INDEX].textureY * tileSize, tileSize, tileSize };
                SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
                SDL_RenderDrawRect(window->GetRender(), &testing);
            }
            //SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
        }
    }
    trainer->DrawTrainer();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (level[INDEX].depth)
            {
                // tile position
                dstRect = { x * tileSizeX * zoom + moveMap.x, y * tileSizeY * zoom + moveMap.y, tileSizeX * zoom, tileSizeY * zoom };
                // tilenummer fra txt filen
                srcRect = { level[INDEX].textureX * tileSizeX, level[INDEX].textureY * tileSizeY, tileSizeX, tileSizeY };
                SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
            }
        }
    }
}

void Level::Update()
{
    LoadLayers();
    trainer->UpdateTrainer();
    MovePlayer();
}


void Level::MovePlayer()
{
    if (Input::KeyState(Key::W))
    {
        if (!level[trainer->collisionPoint.y * tileSizeY].collision)
        {
            trainer->yPos--;
        }
        //std::cout << (trainer->yPos * tileSizeY) - tileSizeY << "\n";
    }
    else if (Input::KeyState(Key::S))
    {
        trainer->yPos++;
    }
    else if (Input::KeyState(Key::A))
    {
        trainer->xPos--;
    }
    else if (Input::KeyState(Key::D))
    {
        trainer->xPos++;
    }
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
