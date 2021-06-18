#include "GUI.h"

void GUI::Init(Window* window)
{
	GUI::window = window;
	ChangeFont(12);
}

void GUI::MessageBox(int x, int y, int w, int h, std::string message)
{
	TTF_Init();
	rect = { x, y, w, h };
	boxSprite->ChangeSprite("Assets/GUI/msgBox.png");
	SDL_Color black = { 255, 255, 255 };
	SDL_Surface* text = TTF_RenderText_Solid(font, message.c_str(), black);
	
	texture = SDL_CreateTextureFromSurface(window->GetRender(), text);

	SDL_RenderCopy(window->GetRender(), boxSprite->tex, NULL, &rect);
	SDL_RenderCopy(window->GetRender(), texture, NULL, &fontSize);
	SDL_FreeSurface(text);
	SDL_DestroyTexture(texture);
}

void GUI::ChangeFont(int value)
{
	font = TTF_OpenFont("Assets/Font/arial.ttf", value);
}

void GUI::ChangeFontSize(int x, int y, int w, int h)
{
	fontSize = { x, y, w, h };
}
