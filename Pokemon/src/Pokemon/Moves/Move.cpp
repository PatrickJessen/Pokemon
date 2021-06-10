#include "Move.h"
#include "AttackType.h"

Move::Move(Moves moves, Type type, int accuracy, int damage)
{
    this->moves = moves;
    this->type = type;
    this->accuracy = accuracy;
    this->damage = damage;
}

void Move::UseMove(Pokemon* pokemon)
{
    pokemon->stats.HP -= damage * AttackType::GetDamageMultiplyer(type, pokemon);
}
