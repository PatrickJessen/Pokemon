#pragma once
#include "AttackMove.h"
#include "../Pokemon.h"
#include <vector>
#include <map>

class Pokemon;
class AttackType
{
public:
    static std::map<Type, std::vector<AttackMove>> atkMoves;

public:
    static float GetDamageMultiplyer(Type type, Pokemon* attackedPokemon);
};