#pragma once
#include "../Window.h"
#include "../Pokemon/Pokemon.h"
#include "../Input.h"
#include "../Sprite.h"

class Trainer
{
public:
	Trainer(Window* window, std::string name, const char* texturePath);
	~Trainer();

	void UpdateTrainer();
	SDL_Rect& GetTrainerPos();

private:
	void DrawTrainer();
	void MoveTrainer();

private:
	SDL_Rect trainerPos;
	Pokemon* pokebag[5];
	std::vector<Pokemon*> pc;
	const char* texturePath;
	Sprite* sprite;
	Window* window;
	std::string name;
};