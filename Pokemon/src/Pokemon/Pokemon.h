#pragma once
#include "../Sprite.h"
//#include "Move.h"
#include <vector>
#include <string>
#include <map>

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
	Pokemon(Sprite* sprite, std::string name, Stats stats, Type type, int level);
	Pokemon(Sprite* sprite, std::string name, Stats stats, Type type, Type type2, int level);
	~Pokemon();

public:
	//virtual void OnPokemonCreate() = 0;
	int GetLevel();
	void SetLevel(int value);
	std::string GetName();

	bool LevelUp();

	Stats stats;
	Type type;
	Type type2;
protected:
	std::map<int, Move> learnableMoves;
	//Move moveset[3];
private:
	int level;
	int experience;
	int requiredExp;
	Sprite* sprite;
	std::string name;
};