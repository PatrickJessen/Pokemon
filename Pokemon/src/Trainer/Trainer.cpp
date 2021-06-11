#include "Trainer.h"

Trainer::Trainer(Window* window, std::string name, const char* texturePath)
{
	this->window = window;
	this->name = name;
	this->texturePath = texturePath;

	sprite = new Sprite(texturePath, window);
}

Trainer::~Trainer()
{
}

void Trainer::UpdateTrainer()
{
	DrawTrainer();
	MoveTrainer();
}

SDL_Rect& Trainer::GetTrainerPos()
{
	return trainerPos;
}

void Trainer::DrawTrainer()
{
	trainerPos = { 100, 100, 62, 62 };
	SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &trainerPos);
}

void Trainer::MoveTrainer()
{
	if (Input::KeyState(Key::W))
	{
		trainerPos.y--;
	}
	else if (Input::KeyState(Key::S))
	{
		trainerPos.y++;
	}
	else if (Input::KeyState(Key::A))
	{
		trainerPos.x--;
	}
	else if (Input::KeyState(Key::D))
	{
		trainerPos.x++;
	}
}
