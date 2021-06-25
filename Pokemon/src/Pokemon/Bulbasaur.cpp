#include "Bulbasaur.h"

bool Bulbasaur::OnPokemonCreate()
{
	if (!created)
	{
		moveset[0] = new Move(Moves::GROWL, Type::STATUS, 100, 0);
		moveset[1] = new Move(Moves::TACKLE, Type::NORMAL, 100, 40);

		InitStats(45, 49, 49, 65, 65, 45);
		learnableMoves.emplace(7, new Move(Moves::LEECHSEED, Type::GRASS, 90, 0));
		learnableMoves.emplace(13, new Move(Moves::VINEWHIP, Type::GRASS, 100, 45));
		learnableMoves.emplace(20, new Move(Moves::POISONPOWDER, Type::POISON, 75, 0));
		learnableMoves.emplace(27, new Move(Moves::RAZORLEAF, Type::GRASS, 90, 55));
		learnableMoves.emplace(34, new Move(Moves::GROWTH, Type::NORMAL, 0, 0));
		learnableMoves.emplace(41, new Move(Moves::SLEEPPOWDER, Type::GRASS, 75, 0));
		learnableMoves.emplace(48, new Move(Moves::SOLARBEAM, Type::GRASS, 100, 120));

		return created = true;
	}
	return created = false;
}

void Bulbasaur::Evolve(int level)
{
}
