#pragma once
#include "Pokemon.h"

class Bulbasaur : public Pokemon
{
public:
	Bulbasaur(Window* window, const char* spritePath, std::string name, Type type, int level) : Pokemon(window, spritePath, name, type, level) {}
	Bulbasaur(Window* window, const char* spritePath, std::string name, Type type, Type type2, int level) : Pokemon(window, spritePath, name, type, type2, level) {}

public:
	virtual void OnPokemonCreate() override;
	virtual void Evolve(int level) override;

};