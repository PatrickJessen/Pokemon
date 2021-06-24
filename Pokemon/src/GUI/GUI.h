#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include "../Window.h"
#include "../Sprite.h"
#include "../Trainer/Trainer.h"

class GUI
{
public:
	static void Init(Window* windows, Trainer* trainers);
	static void MessageBox(std::string message);
	static void ChangeFont(int value);
	static void ChangeFontSize(int x, int y, int w, int h);
	static void MainMenu();
	static void BattleSceneGUI(Trainer* ash, Trainer* gary);
};