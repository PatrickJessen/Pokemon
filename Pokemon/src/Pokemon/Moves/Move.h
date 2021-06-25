#pragma once
#include "Type.h"
#include <string>

enum class Moves
{
	TACKLE, GROWL, SCRATCH, EMBER, LEER, RAGE, SLASH, FLAMETHROWER, FIRESPIN, LEECHSEED, VINEWHIP, POISONPOWDER, RAZORLEAF, GROWTH, SLEEPPOWDER, SOLARBEAM, TAILWHIP,
    BUBBLE, WATERGUN, BITE, WITHDRAW, SKULLBASH, HYDROPUMP
};


class Pokemon;
class Move
{
public:
    Move() = default;
    Move(Moves moves, Type type, int accuracy, int damage);
    ~Move() = default;

public:
    virtual void UseMove(Pokemon* pokemon);
    std::string GetMoveName();
    Type GetType();
    int GetAccuracy();
    int GetDamage();

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