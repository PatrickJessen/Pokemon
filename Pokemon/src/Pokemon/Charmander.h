#pragma once
#include "Pokemon.h"

class Charmander : public Pokemon
{
public:
	~Charmander();

public:
	virtual void OnPokemonCreate() override;

};