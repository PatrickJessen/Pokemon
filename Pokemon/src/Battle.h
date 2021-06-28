#pragma once
#include "Trainer/Trainer.h"
#include "GUI/GUI.h"

class Battle
{
public:
	static void StartBattle(Trainer* ash, Trainer* gary, Window* window);
	static void StartBattle(Trainer* ash, Pokemon* poke, Window* window);

private:
	static void ShowMoves(Trainer* ash);
	static void GetCurrentMove(Trainer* ash, Window* window);
	static void GetRandomMove(Trainer* gary);
	static bool DoIGoFirst(Trainer* ash, Trainer* gary);

};