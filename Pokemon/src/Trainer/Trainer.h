#pragma once
#include "../Window.h"
#include "../Pokemon/Pokemon.h"
#include "../Sprite.h"

class Trainer
{
public:
	Trainer(Window* window, std::string name, const char* texturePath, int xPos, int yPos, int width, int height);
	~Trainer();

	void UpdateTrainer();
	void DrawTrainer();
	SDL_Rect& GetTrainerPos();

	int GetXPos();
	int GetYPos();
	int GetWidth();
	int GetHeight();
	int xPos;
	int yPos;
	SDL_Rect collisionPoint;
private:
	void MoveTrainer();


private:
	SDL_Rect trainerPos;
	SDL_Rect trainerSrc;
	Pokemon* pokebag[5];
	std::vector<Pokemon*> pc;
	const char* texturePath;
	Sprite* sprite;
	Window* window;
	std::string name;
	int width;
	int height;
};