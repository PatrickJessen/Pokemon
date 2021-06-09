#pragma once

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

class Move
{
public:
	Move(Moves moves, Type type, int accuracy)
	{
        this->moves = moves;
        this->type = type;
        this->accuracy = accuracy;
	}
    ~Move() = default;
private:
    Moves moves;
    Type type;
    int accuracy;
};

class AttackMove : public Move
{
public:
    AttackMove(Moves moves, Type type, int accuracy, int damage, bool selfInflict) : Move(moves, type, accuracy)
    {
        this->damage = damage;
        this->selfInflict = selfInflict;
    }
    ~AttackMove() = default;

private:
    int damage;
    bool selfInflict;
};

class SpecialMove : public Move
{
public:

};