#include "Level.h"

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
