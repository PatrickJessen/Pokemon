#pragma once
#include "Pokemon.h"
#include <map>
#include <vector>

enum class Moves
{
	tackle, growl, ember
};

enum class Type
{
    NORMAL,
    GRASS,
    ELECTRIC,
    WATER,
    FIRE,
    BUG,
    GHOST,
    PSYCHIC,
    STEEL,
    DARK,
    FLYING,
    ICE,
    POISON,
    GROUND,
    ROCK,
    DRAGON,
    FIGHTING
};

enum class BuffDefense
{

};

class AttackMove
{
public:
    AttackMove(Type type, float value)
    {
        this->type = type;
        this->value = value;
    }

public:
    Type type;
    float value;
};

class AttackType
{
public:
    static std::map<Type, std::vector<AttackMove>> atkMoves;

public:
    static float GetDamageMultiplyer(Type type, Pokemon attackedPokemon)
    {
        for (auto item : atkMoves)
        {
            if (item.first == type)
            {
                for (int i = 0; i < item.second.size(); i++)
                {
                    if (item.second[i].type == attackedPokemon.type)
                    {
                        return item.second[i].value;
                    }
                }
            }
        }
        return 1;
    }
};

class Move
{
public:
	Move(Moves moves, Type type, int accuracy, int damage)
	{
        this->moves = moves;
        this->type = type;
        this->accuracy = accuracy;
        this->damage = damage;
	}
    ~Move() = default;

public:
    virtual void UseMove(Pokemon pokemon)
    {
        pokemon.stats.HP -= damage * AttackType::GetDamageMultiplyer(type, pokemon);
    }

private:
    Moves moves;
    Type type;
    int accuracy;
    int damage;
};

//class AttackMove : public Move
//{
//public:
//    AttackMove(Moves moves, Type type, int accuracy, int damage, bool selfInflict) : Move(moves, type, accuracy)
//    {
//        this->damage = damage;
//        this->selfInflict = selfInflict;
//    }
//    ~AttackMove() = default;
//
//public:
//    virtual void UseMove(Pokemon pokemon) override
//    {
//
//    }
//
//private:
//    int damage;
//    bool selfInflict;
//};

//class DefenseMove : public Move
//{
//public:
//    DefenseMove(Moves moves, Type type, int accuracy, BuffDefense buffDefense) : Move(moves, type, accuracy)
//    {
//        this->buffDefense = buffDefense;
//    }
//    ~DefenseMove() = default;
//
//private:
//    BuffDefense buffDefense;
//};