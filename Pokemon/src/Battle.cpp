#include "Battle.h"
#include "Input.h"

bool showMoves = false;

static Trainer* ash;
static Trainer* gary;
static Window* window;

void Battle::StartBattle(Trainer* s_ash, Trainer* s_gary, Window* s_window)
{
    ash = s_ash;
    gary = s_gary;
    window = s_window;
    ShowMoves();
    GetCurrentMove();
    GetRandomMove();

    if (DoIGoFirst())
    {
        ash->GetBattlePokemon()->currentMove->UseMove(gary->GetBattlePokemon());
        std::cout << gary->GetBattlePokemon()->stats.HP << ash->GetBattlePokemon()->currentMove->GetMoveName() <<"\n";
        gary->GetBattlePokemon()->currentMove->UseMove(ash->GetBattlePokemon());
        std::cout << ash->GetBattlePokemon()->stats.HP << gary->GetBattlePokemon()->currentMove->GetMoveName() <<"\n";
    }
    else if (!DoIGoFirst() && ash->GetBattlePokemon()->currentMove != nullptr)
    {
        gary->GetBattlePokemon()->currentMove->UseMove(ash->GetBattlePokemon());
        std::cout << ash->GetBattlePokemon()->stats.HP << gary->GetBattlePokemon()->currentMove->GetMoveName() << "\n";
        ash->GetBattlePokemon()->currentMove->UseMove(gary->GetBattlePokemon());
        std::cout << gary->GetBattlePokemon()->stats.HP << ash->GetBattlePokemon()->currentMove->GetMoveName() << "\n";
    }
    SetMoveToNULL();

    GUI::ShowHealthbar(ash, gary);
}

void Battle::ShowMoves()
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

void Battle::GetCurrentMove()
{
    while (showMoves)
    {
        if (Input::KeyPressed(Key::NUM_1) && ash->GetBattlePokemon()->moveset[0] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[0];
            ClearMoveTab();
            break;
        }
        else if (Input::KeyPressed(Key::NUM_2) && ash->GetBattlePokemon()->moveset[1] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[1];
            ClearMoveTab();
            break;
        }
        else if (Input::KeyPressed(Key::NUM_3) && ash->GetBattlePokemon()->moveset[2] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[2];
            ClearMoveTab();
            break;
        }
        else if (Input::KeyPressed(Key::NUM_4) && ash->GetBattlePokemon()->moveset[3] != NULL)
        {
            ash->GetBattlePokemon()->currentMove = ash->GetBattlePokemon()->moveset[3];
            ClearMoveTab();
            break;
        }


        if (Input::KeyPressed(Key::ESCAPE))
        {
            ClearMoveTab();
        }
        window->Update();
    }
}

void Battle::GetRandomMove()
{
    int moveCount = 1;
    int randMove;
    for (int i = 0; i < 3; i++)
    {
        if (gary->GetBattlePokemon()->moveset[i] != NULL)
        {
            moveCount += i;
        }
    }
    randMove = rand() % moveCount;

    gary->GetBattlePokemon()->currentMove = gary->GetBattlePokemon()->moveset[randMove];
}

void Battle::ClearMoveTab()
{
    showMoves = false;
    window->Clear();
    GUI::RenderBattleScene(ash, gary);
}

void Battle::SetMoveToNULL()
{
    ash->GetBattlePokemon()->currentMove = nullptr;
    gary->GetBattlePokemon()->currentMove = nullptr;
}

bool Battle::DoIGoFirst()
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
