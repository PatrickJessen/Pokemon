#include "Pokemon.h"

Pokemon::Pokemon(Sprite* sprite, std::string name, Stats stats, Type type, int level)
{
	this->sprite = sprite;
	this->name = name;
	this->stats = stats;
	this->type = type;
	this->level = level;

	experience = 0;
	requiredExp *= level;
}

Pokemon::Pokemon(Sprite* sprite, std::string name, Stats stats, Type type, Type type2, int level)
{
	this->sprite = sprite;
	this->name = name;
	this->stats = stats;
	this->type = type;
	this->type2 = type2;
	this->level = level * level;

	experience = 0;
}

Pokemon::~Pokemon()
{
}

int Pokemon::GetLevel()
{
	return level;
}

void Pokemon::SetLevel(int value)
{
	level = value * level;
}


std::string Pokemon::GetName()
{
	return name;
}

bool Pokemon::LevelUp()
{
	if (experience >= requiredExp)
	{
		return true;
	}
	return false;
}