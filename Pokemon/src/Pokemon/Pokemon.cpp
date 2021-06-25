#include "Pokemon.h"

Pokemon::Pokemon(Window* window, const char* spritePath, std::string name, Type type, int level)
{
	this->name = name;
	this->type = type;
	this->level = level;
	this->window = window;

	experience = 0;
	requiredExp *= level;

	sprite = new Sprite(spritePath, window);
}

Pokemon::Pokemon(Window* window, const char* spritePath, std::string name, Type type, Type type2, int level)
{
	this->name = name;
	this->type = type;
	this->type2 = type2;
	this->level = level * level;
	this->window = window;

	experience = 0;
	requiredExp *= level;

	sprite = new Sprite(spritePath, window);
}

Pokemon::~Pokemon()
{
}

void Pokemon::InitStats(int hp, int attack, int defense, float spAtk, float spDef, int speed)
{
	stats.HP = hp;
	stats.Attack = attack;
	stats.Defense = defense;
	stats.SPATK = spAtk;
	stats.SPDEF = spDef;
	stats.Speed = speed;
}

int Pokemon::GetLevel()
{
	return level;
}

int Pokemon::GetHP()
{
	return stats.HP;
}

void Pokemon::AddLevel()
{
	level++;
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

void Pokemon::DrawPokemon(SDL_Rect rect)
{
	SDL_RenderCopy(window->GetRender(), sprite->tex, NULL, &rect);
}

void Pokemon::OnUpdate()
{
}

std::string Pokemon::GetMoveName()
{
	for (int i = 0; i < 3; i++)
	{
		return moveset[i]->GetMoveName();
	}
}
