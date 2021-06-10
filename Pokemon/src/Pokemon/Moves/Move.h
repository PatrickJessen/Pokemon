#pragma once
#include "Type.h"

enum class Moves
{
	tackle, growl, ember
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