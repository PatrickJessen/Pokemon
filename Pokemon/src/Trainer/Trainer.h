#pragma once
#include "../Window.h"
#include "../Pokemon/Pokemon.h"
#include "../Sprite.h"
#include "../Collision.h"

class Trainer
{
public:
	Trainer(Window* window, std::string name, const char* texturePath, int xPos, int yPos, int width, int height, int money);
	~Trainer();

	void UpdateTrainer();
	void DrawTrainer(int camx, int camy);
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
	void SetSrcRect(int x, int y, int w, int h);
	bool CollisionWithTrainer(int trainerColX, int trainerColY, int tileSize, int zoom);

	void OnPokemonCatched();
	SDL_Rect collisionPoint;
	int xPos;
	int yPos;
	Pokemon* pokebag[5];
	const char* starterPokemon;
	bool movementIsDisabled;
	const char* spriteBack;
	const char* spriteFront;

	SDL_Rect interactPoint;
	Sprite* sprite;
	Sprite* frontSprite;
	Sprite* backSprite;
	Pokemon* GetPokemonByName(const char* pokemonName);
	SDL_Rect trainerPos;
private:
	void MoveTrainer();


private:
	SDL_Rect trainerSrc;
	std::vector<Pokemon*> pc;
	const char* texturePath;
	Window* window;
	std::string name;
	int width;
	int height;
	int money;
};