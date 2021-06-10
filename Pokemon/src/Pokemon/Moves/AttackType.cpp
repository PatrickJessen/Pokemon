#include "AttackType.h"

std::map<Type, std::vector<AttackMove>> AttackType::atkMoves;

float AttackType::GetDamageMultiplyer(Type type, Pokemon* attackedPokemon)
{
    for (auto& item : atkMoves)
        {
            if (item.first == type)
            {
                for (int i = 0; i < item.second.size(); i++)
                {
                    if (item.second[i].type == attackedPokemon->type || item.second[i].type == attackedPokemon->type2)
                    {
                        return item.second[i].value;
                    }
                }
            }
        }
        return 1;
}
