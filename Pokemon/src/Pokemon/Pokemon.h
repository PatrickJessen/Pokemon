#pragma once
#include "../Sprite.h"
#include "Moves/Move.h"
#include <vector>
#include <string>
#include <map>
#include "../Window.h"

struct Stats
{
	int HP;
	int Attack;
	int Defense;
	float SPATK;
	float SPDEF;
	int Speed;
};

class Pokemon
{
public:
	Pokemon(Window* window, const char* spritePath, std::string name, Type type, int level);
	Pokemon(Window* window, const char* spritePath, std::string name, Type type, Type type2, int level);
	~Pokemon();

public:
	void InitStats(int hp, int attack, int defense, float spAtk, float spDef, int speed);
	//virtual void OnPokemonCreate() = 0;
	int GetLevel();
	void SetLevel(int value);
	std::string GetName();

	bool LevelUp();
	void DrawPokemon();
	void OnUpdate();

	Stats stats;
	Type type;
	Type type2;
	std::map<int, Move> learnableMoves;
	SDL_Rect pokeRect;
	Sprite* sprite;
protected:
	Move moveset[3];
private:
	int level;
	int experience;
	int requiredExp;
	std::string name;
};