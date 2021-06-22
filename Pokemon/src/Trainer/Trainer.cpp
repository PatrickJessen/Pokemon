#include "Trainer.h"
#include "../Input.h"

Trainer::Trainer(Window* window, std::string name, const char* texturePath, int xPos, int yPos, int width, int height, int money)
{
	this->window = window;
	this->name = name;
	this->texturePath = texturePath;
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;
	this->money = money;

	sprite = new Sprite(texturePath, window);
}

Trainer::~Trainer()
{
	delete sprite;
}

void Trainer::UpdateTrainer()
{
	//DrawTrainer();
	interactPoint = { trainerPos.x + trainerPos.w / 2, trainerPos.y, 5, 5 };
	collisionPoint = { trainerPos.x + trainerPos.w / 2, trainerPos.y + trainerPos.h / 2, 15, 5 };
	SDL_RenderDrawRect(window->GetRender(), &collisionPoint);
	SDL_RenderDrawRect(window->GetRender(), &interactPoint);
}

SDL_Rect& Trainer::GetTrainerPos()
{
	return trainerPos;
}

SDL_Rect& Trainer::GetInteractRect()
{
	return interactPoint;
}

void Trainer::DrawTrainer(int camx, int camy)
{
	trainerPos = { xPos - camx, yPos - camy, width, height };
	trainerSrc = { 0, 0, 60, 60 };
	SDL_RenderCopy(window->GetRender(), sprite->tex, &trainerSrc, &trainerPos);
}

Pokemon* Trainer::GetPokemonByName(const char* pokemonName)
{
	return nullptr;
}

void Trainer::MoveTrainer()
{

}

int Trainer::GetXPos()
{
	return xPos;
}

int Trainer::GetYPos()
{
	return yPos;
}

void Trainer::SetXPos(int value)
{
	xPos = value;
}

void Trainer::SetYPos(int value)
{
	yPos = value;
}

void Trainer::SetXYPos(int x, int y)
{
	xPos = x;
	yPos = y;
}

int Trainer::GetWidth()
{
	return width;
}

int Trainer::GetHeight()
{
	return height;
}

int Trainer::GetTileX(int tileSize)
{
	return collisionPoint.x / tileSize;
}

int Trainer::GetTileY(int tileSize)
{
	return collisionPoint.y / tileSize;
}

void Trainer::SetTileX(int value, int tileSize)
{
	xPos = value / tileSize;
}

void Trainer::SetTileY(int value, int tileSize)
{
	yPos = value / tileSize;
}

int Trainer::GetMoney()
{
	return money;
}

void Trainer::SetMoney(int value)
{
	money += value;
}
