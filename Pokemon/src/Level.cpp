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
    delete sprite;
}

int Level::LoadNewLevel()
{
    int y = trainer->GetTileX(tileSize);
    int x = trainer->GetTileY(tileSize);
    //std::cout << x << ", " << y << "\n";
    for (int i = 0; i < doorsPosition.size(); i++)
    {
        for (int j = 0; j < doorsPosition[i].size(); j++)
        {
            if (x == doorsPosition[i][j].x && y == doorsPosition[i][j].y)
            {
                return i;        
            }
        }
    }
    return -1;
}

void Level::InitMap()
{
    camera = { 0, 0, tileSize * zoom, tileSize * zoom };
    sprite = new Sprite(texturePath, window);
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

}

void Level::DrawBackground()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            dstRect = { x * tileSize * zoom + camera.x, y * tileSize * zoom + camera.y, camera.w, camera.h };
            srcRect = { level[y][x].textureX * tileSize, level[y][x].textureY * tileSize, tileSize, tileSize };
            if (level[y][x].type != TileType::Depth)
            {
                SDL_RenderCopy(window->GetRender(), sprite->tex, &srcRect, &dstRect);
            }
            if (level[y][x].type == TileType::Collision)
            {
                SDL_Rect testing = { level[y][x].textureX * tileSize * zoom + camera.x, level[y][x].textureY * tileSize * zoom + camera.y, tileSize * zoom, tileSize * zoom };
                SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
                SDL_RenderDrawRect(window->GetRender(), &testing);
            }
        }
}

void Level::DrawDepth()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            if (level[y][x].type == TileType::Depth)
            {
                dstRect = { x * tileSize * zoom + camera.x, y * tileSize * zoom + camera.y, camera.w, camera.h };
                srcRect = { level[y][x].textureX * tileSize, level[y][x].textureY * tileSize, tileSize, tileSize };
                SDL_RenderCopy(window->GetRender(), sprite->tex, &srcRect, &dstRect);
            }
        }
}

void Level::UpdateBackground()
{
    DrawBackground();
}

void Level::UpdateForeground()
{
    DrawDepth();
    CustomMapUpdate();
}

void Level::CleanMap()
{
    for (int x = 0; x < width; x++)
    {
        //std::cout << level[x]->textureX << ", " << level[x]->textureY << "\n";
        delete[] level[x];
        //std::cout << level[x]->textureX << ", " << level[x]->textureY << "\n";
    }
    delete[] level;
}

void Level::MovePlayerInWorld()
{
    //level->camera = { trainer->xPos - window->GetWidth() / 2, trainer->yPos - window->GetHeight() / 2, level->tileSize * level->zoom, level->tileSize * level->zoom };
    if (Input::KeyState(Key::W))
    {
        if (level[(trainer->collisionPoint.y / tileSize / zoom)][trainer->collisionPoint.x / tileSize / zoom].type != TileType::Collision)
        {
            //trainer->yPos--;
            camera.y++;
        }
    }
    else if (Input::KeyState(Key::S))
    {
        if (level[trainer->collisionPoint.y / tileSize / zoom + 1][trainer->collisionPoint.x / tileSize / zoom].type != TileType::Collision)
        {
            //trainer->yPos++;
            camera.y--;
        }
    }
    else if (Input::KeyState(Key::A))
    {
        if (level[trainer->collisionPoint.y / tileSize / zoom][trainer->collisionPoint.x / tileSize / zoom - 1].type != TileType::Collision)
        {

            //trainer->xPos--;
            camera.x++;
        }
    }
    else if (Input::KeyState(Key::D))
    {
        if (level[trainer->collisionPoint.y / tileSize / zoom][trainer->collisionPoint.x / tileSize / zoom + 1].type != TileType::Collision)
        {

            //trainer->xPos++;
            camera.x--;
        }
    }
    //trainer->SetXYPos(window->GetWidth() / 2, window->GetHeight() / 2);
    trainer->GetTrainerPos() = { trainer->xPos - camera.x, trainer->yPos - camera.y, 62, 62 };
    std::cout << trainer->GetTileX(tileSize) << ", " << trainer->GetTileY(tileSize) << "\n";
}

void Level::MovePlayerInside()
{
    if (Input::KeyState(Key::W))
    {
        if (level[(trainer->collisionPoint.y / tileSize / zoom - 1)][trainer->collisionPoint.x / tileSize / zoom].type != TileType::Collision)
        {
            trainer->yPos--;
        }
    }
    else if (Input::KeyState(Key::S))
    {
        if (level[trainer->collisionPoint.y / tileSize / zoom + 1][trainer->collisionPoint.x / tileSize / zoom].type != TileType::Collision)
        {
            trainer->yPos++;
        }
    }
    else if (Input::KeyState(Key::A))
    {
        if (level[trainer->collisionPoint.y / tileSize / zoom][trainer->collisionPoint.x / tileSize / zoom - 1].type != TileType::Collision)
        {
            trainer->xPos--;
        }
    }
    else if (Input::KeyState(Key::D))
    {
        if (level[trainer->collisionPoint.y / tileSize / zoom][trainer->collisionPoint.x / tileSize / zoom + 1].type != TileType::Collision)
        {
            trainer->xPos++;
        }
    }
}


void Level::SpawnPokemon()
{
	/*int x = rand() % 100;
	for (auto item : pokeSpawn)
	{
		if (x < item.first)
		{
			std::cout << "A wild " << item.second[item.first]->GetName() << " Appeard\n";
		}
	}*/
}
