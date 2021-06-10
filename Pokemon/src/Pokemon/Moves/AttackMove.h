#pragma once
#include "Type.h"

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