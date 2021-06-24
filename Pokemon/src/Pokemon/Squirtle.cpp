#include "Squirtle.h"

void Squirtle::OnPokemonCreate()
{
	moveset[0] = new Move(Moves::TAILWHIP, Type::STATUS, 100, 0);
	moveset[1] = new Move(Moves::TACKLE, Type::NORMAL, 100, 40);

	InitStats(44, 48, 65, 50, 64, 43);
	learnableMoves.emplace(8, new Move(Moves::BUBBLE, Type::WATER, 100, 40));
	learnableMoves.emplace(15, new Move(Moves::WATERGUN, Type::WATER, 100, 40));
	learnableMoves.emplace(22, new Move(Moves::BITE, Type::DARK, 100, 60));
	learnableMoves.emplace(28, new Move(Moves::WITHDRAW, Type::WATER, 0, 0));
	learnableMoves.emplace(35, new Move(Moves::SKULLBASH, Type::NORMAL, 100, 130));
	learnableMoves.emplace(42, new Move(Moves::HYDROPUMP, Type::WATER, 80, 110));
}

void Squirtle::Evolve(int level)
{
}
