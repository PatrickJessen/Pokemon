#include "Level.h"
#include <fstream>

Level::Level(Window* window, const char* filePath, const char* texturePath, int col, int row, int zoneLevel, int tileSize, int zoom)
	:window(window), filePath(filePath), texturePath(texturePath), col(row), zoneLevel(zoneLevel), tileSize(tileSize), zoom(zoom)
{
	std::ifstream fs(filePath, std::ifstream::in);
	mapArr = new int* [row];
	for (int i = 0; i < col; i++)
	{
		mapArr[i] = new int[col];
	}
		
}

void Level::LoadMap()
{
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
		{
			dstRect = { c * tileSize * zoom, r * tileSize * zoom, tileSize * zoom, tileSize * zoom };
			srcRect = { mapArr[r][0] * tileSize, mapArr[0][c] * tileSize, tileSize, tileSize };
			SDL_RenderCopy(window->GetRender(), loadTexture(), &srcRect, &dstRect);
		}
}

void Level::CleanMapArr()
{
	for (int i = 0; i < col; i++)
	{
		delete [] mapArr[i];
	}
	delete [] mapArr;
}

SDL_Texture* Level::loadTexture()
{
    SDL_Surface* surface(SDL_LoadBMP(filePath));
    if (surface) {
        SDL_Texture* texture(SDL_CreateTextureFromSurface(window->GetRender(), surface));
        if (texture) {
            printf("Texture loaded successfully: %s\n", filePath);
            return texture;
        }
        printf("Failed to create texture: %s\n", filePath);
        return nullptr;
    }
    printf("Cannot find texture file: %s\n", filePath);
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
