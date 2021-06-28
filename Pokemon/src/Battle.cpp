#include "Battle.h"
#include "Input.h"

void Battle::StartBattle(Trainer* ash, Trainer* gary, Window* window)
{
	while (!ash->GetBattlePokemon()->stats.HP > 0 || gary->GetBattlePokemon()->stats.HP)
	{
        ShowMoves(ash);

        if (ash->GetBattlePokemon()->stats.Speed > gary->GetBattlePokemon()->stats.Speed)
        {

        }

        window->Update();
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
