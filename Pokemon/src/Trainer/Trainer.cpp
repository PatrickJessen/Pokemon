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
}

void Trainer::UpdateTrainer()
{
	//DrawTrainer();
	collisionPoint = { trainerPos.x + trainerPos.w / 2, trainerPos.y + trainerPos.h, 15, 5 };
	SDL_RenderDrawRect(window->GetRender(), &collisionPoint);
	MoveTrainer();
}

SDL_Rect& Trainer::GetTrainerPos()
{
	return trainerPos;
}

void Trainer::DrawTrainer()
{
	trainerPos = { xPos, yPos, width, height };
	trainerSrc = { 0, 0, 60, 60 };
	SDL_RenderCopy(window->GetRender(), sprite->tex, &trainerSrc, &trainerPos);
}

void Trainer::MoveTrainer()
{
	/*if (Input::KeyState(Key::W))
	{
		yPos--;
	}
	else if (Input::KeyState(Key::S))
	{
		yPos++;
	}
	else if (Input::KeyState(Key::A))
	{
		xPos--;
	}
	else if (Input::KeyState(Key::D))
	{
		xPos++;
	}*/
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
