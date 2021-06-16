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
    trainer = new Trainer(window, "Ash", "Assets/Trainers/MainTrainer.png", 200, 250, 62, 62);
    ReadFile inFile(filePath);
    level = new Tile*[width];

    for (int i = 0; i < width; i++)
    {
        level[i] = new Tile[height];
    }

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            level[y][x] = inFile.ReadClass<Tile>();
        }
}

void Level::LoadLayers()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            dstRect = { x * tileSize * zoom + moveMap.x, y * tileSize * zoom + moveMap.y, tileSize * zoom, tileSize * zoom };
            srcRect = { level[y][x].textureX * tileSize, level[y][x].textureY * tileSize, tileSize, tileSize };
            SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
            if (level[y][x].type != TileType::Depth)
            {
                SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
            }
            if (level[y][x].type == TileType::Collision)
            {
                SDL_Rect testing = { level[y][x].textureX * tileSize, level[y][x].textureY * tileSize, tileSize, tileSize };
                SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
                SDL_RenderDrawRect(window->GetRender(), &testing);
            }
        }
    trainer->DrawTrainer();
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            if (level[y][x].type == TileType::Depth)
            {
                dstRect = { x * tileSize * zoom + moveMap.x, y * tileSize * zoom + moveMap.y, tileSize * zoom, tileSize * zoom };
                srcRect = { level[y][x].textureX * tileSize, level[y][x].textureY * tileSize, tileSize, tileSize };
                SDL_RenderCopy(window->GetRender(), tex, &srcRect, &dstRect);
            }
        }
}

void Level::Update()
{
    LoadLayers();
    LoadNewLevel();
    trainer->UpdateTrainer();
    MovePlayer();
}


void Level::MovePlayer()
{
    //std::cout << (int)level[trainer->collisionPoint.y / tileSize][trainer->collisionPoint.x / tileSize].type << "\n";
    if (Input::KeyState(Key::W))
    {
        if (level[trainer->collisionPoint.y / tileSize][trainer->collisionPoint.x / tileSize].type != TileType::Collision)
        {
            trainer->yPos--;
        }
    }
    else if (Input::KeyState(Key::S))
    {
        if (level[trainer->collisionPoint.y / tileSize + 1][trainer->collisionPoint.x / tileSize].type != TileType::Collision)
        {
            trainer->yPos++;
        }
    }
    else if (Input::KeyState(Key::A))
    {
        if (level[trainer->collisionPoint.y / tileSize][trainer->collisionPoint.x / tileSize - 1].type != TileType::Collision)
        {
            trainer->xPos--;
        }
    }
    else if (Input::KeyState(Key::D))
    {
        if (level[trainer->collisionPoint.y / tileSize][(trainer->collisionPoint.x / tileSize) + 1].type != TileType::Collision)
        {
            trainer->xPos++;
        }
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
