#include "Trainer.h"
#include "../Input.h"

Trainer::Trainer(Window* window, std::string name, const char* texturePath, int xPos, int yPos, int width, int height)
{
	this->window = window;
	this->name = name;
	this->texturePath = texturePath;
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;

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
	collisionPoint = { trainerPos.x + trainerPos.w / 2, trainerPos.y + trainerPos.h - 5, 15, 5 };
	SDL_RenderDrawRect(window->GetRender(), &collisionPoint);
	SDL_RenderDrawRect(window->GetRender(), &interactPoint);
	MoveTrainer();
	DrawTrainer();
}

SDL_Rect& Trainer::GetTrainerPos()
{
	return trainerPos;
}

SDL_Rect& Trainer::GetInteractRect()
{
	return interactPoint;
}

void Trainer::DrawTrainer()
{
	trainerPos = { xPos, yPos, width, height };
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
