#include "PalletTown.h"



void PalletTown::HandlePokeSpawns()
{
	//Pokemon Bulbasaur(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5);
	//Bulbasaur.InitStats(100, 100, 100, 100, 100, 100);
	pokeSpawn.emplace(100, new Pokemon(window, "Assets/Pokemons/Bulbasaur.png", "Bulbasaur", Type::GRASS, Type::POISON, 5));
	//pokeSpawn.emplace(100, Pokemon(window, "Assets/Pokemons/Charmander.png", "Charmander", Type::FIRE, 5));
	//pokeSpawn.emplace(100, Pokemon(window, "Assets/Pokemons/Squirtle.png", "Squirtle", Type::WATER, 5));
}

