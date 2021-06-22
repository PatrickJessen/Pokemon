#pragma once
#include "../../Level.h"

class ProfOakLab : public Level
{
public:
	ProfOakLab(Window* window, Trainer* trainer, const char* filePath, const char* texturePath, int zoneLevel, int width, int height, int tileSize, int zoom);
	~ProfOakLab();

private:
	virtual void HandlePokeSpawns() override;
	virtual Level* UpdateLevel() override;
	virtual void CustomMapUpdate() override;
	virtual void NewTrainerPosition() override;

	void PlacePokeballs();
	void InteractWithPokeball();

	void ChoosePokemon(const char* name);
	Pokemon* CreateStarterPokemon(std::string name);
private:
	Level* palletTown = nullptr;
	Sprite* sprite = nullptr;
	Sprite* pokemon = nullptr;
	SDL_Rect pokemonRect;
	SDL_Rect ballRect1;
	SDL_Rect ballRect2;
	SDL_Rect ballRect3;

private:
	bool hasBeenChosen = false;
};

