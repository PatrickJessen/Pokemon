#pragma once
#include "../Window.h"
#include "../Pokemon/Pokemon.h"
#include "../Sprite.h"

class Trainer
{
public:
	Trainer(Window* window, std::string name, const char* texturePath, int xPos, int yPos, int width, int height, int money);
	~Trainer();

	void UpdateTrainer();
	void DrawTrainer();
	SDL_Rect& GetTrainerPos();
	SDL_Rect& GetInteractRect();

	int GetXPos();
	int GetYPos();
	void SetXPos(int value);
	void SetYPos(int value);
	void SetXYPos(int x, int y);
	int GetWidth();
	int GetHeight();
	int GetTileX(int tileSize);
	int GetTileY(int tileSize);
	void SetTileX(int value, int tileSize);
	void SetTileY(int value, int tileSize);
	int GetMoney();
	void SetMoney(int value);
	SDL_Rect collisionPoint;
	int xPos;
	int yPos;
	Pokemon* pokebag[5];
	const char* starterPokemon;

	Pokemon* GetPokemonByName(const char* pokemonName);
private:
	void MoveTrainer();


private:
	SDL_Rect trainerPos;
	SDL_Rect trainerSrc;
	SDL_Rect interactPoint;
	std::vector<Pokemon*> pc;
	const char* texturePath;
	Sprite* sprite;
	Window* window;
	std::string name;
	int width;
	int height;
	int money;
};