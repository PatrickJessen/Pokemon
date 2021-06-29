#pragma once
#include "Trainer/Trainer.h"
#include "GUI/GUI.h"

class Battle
{
public:
	static void StartBattle(Trainer* s_ash, Trainer* s_gary, Window* s_window);
	static void StartBattle(Trainer* ash, Pokemon* poke, Window* window);

private:
	static void ShowMoves();
	static void GetCurrentMove();
	static void GetRandomMove();
	static void ClearMoveTab();
	static void SetMoveToNULL();
	static bool DoIGoFirst();

};