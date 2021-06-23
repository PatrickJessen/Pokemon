#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include "../Window.h"
#include "../Sprite.h"

class GUI
{
public:
	static void Init(Window* windows);
	static void MessageBox(int x, int y, int w, int h, std::string message);
	static void ChangeFont(int value);
	static void ChangeFontSize(int x, int y, int w, int h);
	static void MainMenu();
};