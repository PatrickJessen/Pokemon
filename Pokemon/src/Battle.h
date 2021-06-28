#pragma once
#include "Trainer/Trainer.h"
#include "GUI/GUI.h"

class Battle
{
public:
	void StartBattle(Trainer* ash, Trainer* gary, Window* window);
	void StartBattle(Trainer* ash, Pokemon* poke, Window* window);

private:
	void ShowMoves(Trainer* ash);

private:
	bool showMoves = false;
};