#include "Battle.h"
#include "Input.h"

bool showMoves = false;

void Battle::StartBattle(Trainer* ash, Trainer* gary, Window* window)
{
    ShowMoves(ash);
    GetCurrentMove(ash, window);
    GetRandomMove(gary);

    if (DoIGoFirst(ash, gary))
    {
        ash->GetBattlePokemon()->currentMove->UseMove(gary->GetBattlePokemon());
    }
    else
    {
        gary->GetBattlePokemon()->currentMove->UseMove(ash->GetBattlePokemon());
    }
}

void Battle::ShowMoves(Trainer* ash)
{
    if (Input::KeyPressed(Key::NUM_1))
    {
        showMoves = true;
    }
    else if (Input::KeyPressed(Key::ESCAPE))
    {
        showMoves = false;
    }
    if (showMoves)
    {
        GUI::ShowMoves(ash);
    }
}

void Battle::GetCurrentMove(Trainer* ash, Window* window)
{
    while (showMoves)
    {
        if (Input::KeyPressed(Key::NUM_1) && ash->GetBattlePokemon()->moveset[0] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[0];
            break;
        }
        else if (Input::KeyPressed(Key::NUM_2) && ash->GetBattlePokemon()->moveset[1] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[1];
            break;
        }
        else if (Input::KeyPressed(Key::NUM_3) && ash->GetBattlePokemon()->moveset[2] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[2];
            break;
        }
        else if (Input::KeyPressed(Key::NUM_4) && ash->GetBattlePokemon()->moveset[3] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[3];
            break;
        }


        if (Input::KeyPressed(Key::ESCAPE))
        {
            showMoves = false;
            window->Clear();
        }
        window->Update();
    }
}

void Battle::GetRandomMove(Trainer* gary)
{
    int moveCount = 0;
    int randMove;
    for (int i = 0; i < 3; i++)
    {
        if (gary->GetBattlePokemon()->moveset[i] != NULL)
        {
            moveCount = i;
        }
    }
    randMove = rand() % moveCount;

    gary->GetBattlePokemon()->currentMove = gary->GetBattlePokemon()->moveset[randMove];
}

bool Battle::DoIGoFirst(Trainer* ash, Trainer* gary)
{
    if (ash->GetBattlePokemon()->currentMove != nullptr)
    {
        if (ash->GetBattlePokemon()->stats.Speed > gary->GetBattlePokemon()->stats.Speed)
        {
            return true;
        }
        else if (ash->GetBattlePokemon()->stats.Speed < gary->GetBattlePokemon()->stats.Speed)
        {
            return false;
        }
        return true;
    }
    return false;
}
