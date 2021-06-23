#include "GUI.h"
#include "../Input.h"

static SDL_Rect rect;
static SDL_Rect fontSize;
static Sprite* boxSprite;
static Sprite* menuSprite = nullptr;
static Sprite* pokeHolder = nullptr;
static Window* window;
static Trainer* trainer;
static TTF_Font* font;
static SDL_Texture* texture;
static bool menuClicked;

void GUI::Init(Window* windows, Trainer* trainers)
{
	window = windows;
	trainer = trainers;
	ChangeFont(12);
	menuSprite = new Sprite("Assets/GUI/Menu.png", window);
	pokeHolder = new Sprite("Assets/GUI/PokeHolder.png", window);
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

void GUI::MainMenu()
{
	SDL_Rect menuRect = { 0, window->GetHeight() - 400, 450, 400 };
	SDL_Rect pokeRect = { 10, 10, 50, 50 };

	for (int i = 0; i < 5; i++)
	{
		pokeRect.y += 50;
		if (trainer->pokebag[i] != NULL)
		{
			trainer->pokebag[i]->DrawPokemon(pokeRect);
		}
		else
		{
			SDL_RenderCopy(window->GetRender(), pokeHolder->tex, NULL, &pokeRect);
		}
	}

	SDL_RenderCopy(window->GetRender(), menuSprite->tex, NULL, &menuRect);
}
