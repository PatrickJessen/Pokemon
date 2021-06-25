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

std::string Move::GetMoveName()
{
    switch (moves)
    {
    case Moves::TACKLE: return "Tackle";
        break;
    case Moves::GROWL: return "Growl";
        break;
    case Moves::SCRATCH: return "Scratch";
        break;
    case Moves::EMBER: return "Ember";
        break;
    case Moves::LEER: return "Leer";
        break;
    case Moves::RAGE: return "Rage";
        break;
    case Moves::SLASH: return "Slash";
        break;
    case Moves::FLAMETHROWER: return "Flamethrower";
        break;
    case Moves::FIRESPIN: return "Firespin";
        break;
    case Moves::LEECHSEED: return "Leech seed";
        break;
    case Moves::VINEWHIP: return "Vinewhip";
        break;
    case Moves::POISONPOWDER: return "Poison Powder";
        break;
    case Moves::RAZORLEAF: return "Razorleaf";
        break;
    case Moves::GROWTH: return "Growth";
        break;
    case Moves::SLEEPPOWDER: return "Sleep Powder";
        break;
    case Moves::SOLARBEAM: return "Solarbeam";
        break;
    case Moves::TAILWHIP: return "Tailwhip";
        break;
    case Moves::BUBBLE: return "Bubble";
        break;
    case Moves::WATERGUN: return "Watergun";
        break;
    case Moves::BITE: return "Bite";
        break;
    case Moves::WITHDRAW: return "Withdraw";
        break;
    case Moves::SKULLBASH: return "Skullbash";
        break;
    case Moves::HYDROPUMP: return "Hydropump";
        break;
    }
    return "";
}

Type Move::GetType()
{
    return type;
}

int Move::GetAccuracy()
{
    return accuracy;
}

int Move::GetDamage()
{
    return damage;
}
