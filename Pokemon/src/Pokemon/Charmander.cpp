#include "Charmander.h"

void Charmander::OnPokemonCreate()
{
	moveset[0] = new Move(Moves::GROWL, Type::STATUS, 100, 0);
	moveset[1] = new Move(Moves::SCRATCH, Type::NORMAL, 100, 40);

	InitStats(39, 52, 43, 60, 50, 65);
	learnableMoves.emplace(9, new Move(Moves::EMBER, Type::FIRE, 100, 40));
	learnableMoves.emplace(15, new Move(Moves::LEER, Type::STATUS, 100, 0));
	learnableMoves.emplace(22, new Move(Moves::RAGE, Type::NORMAL, 100, 20));
	learnableMoves.emplace(30, new Move(Moves::SLASH, Type::NORMAL, 100, 70));
	learnableMoves.emplace(38, new Move(Moves::FLAMETHROWER, Type::FIRE, 100, 90));
	learnableMoves.emplace(46, new Move(Moves::FIRESPIN, Type::FIRE, 85, 35));
}

void Charmander::Evolve(int level)
{
	if (GetLevel() == level)
	{
		//evolution = new Charmeleon();
	}
}
