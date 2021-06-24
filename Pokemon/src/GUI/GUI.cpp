#include "GUI.h"
#include "../Input.h"

static SDL_Rect rect;
static SDL_Rect fontSize;
static Sprite* boxSprite;
static Sprite* menuSprite = nullptr;
static Sprite* pokeHolder = nullptr;
static Sprite* battleSprite = nullptr;
static Window* window;
static Trainer* trainer;
static TTF_Font* font;
static SDL_Texture* texture;
static bool menuClicked;
static bool animIsOver = false;

void GUI::Init(Window* windows, Trainer* trainers)
{
	window = windows;
	trainer = trainers;
	TTF_Init();
	ChangeFont(12);
	menuSprite = new Sprite("Assets/GUI/Menu.png", window);
	pokeHolder = new Sprite("Assets/GUI/PokeHolder.png", window);
	boxSprite = new Sprite("Assets/GUI/msgBox.png", window);
}

void GUI::MessageBox(std::string message)
{
	rect = { window->GetWidth() / 2 - 250, window->GetHeight() - 150, 500, 150 };
	for (char item : message)
	{
		fontSize = { rect.x + 50, rect.y + 50, rect.w - item * 3, rect.h / 4 };
	}
	//boxSprite->ChangeSprite("Assets/GUI/msgBox.png");
	SDL_Color black = { 30, 30, 30 };
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
	SDL_Rect pokeRect = { 10, 10, 30, 30 };

	for (int i = 0; i < 5; i++)
	{
		pokeRect.y += 60;
		if (trainer->pokebag[i] != NULL)
		{
			pokeRect.w = 60;
			pokeRect.h = 60;
			trainer->pokebag[i]->DrawPokemon(pokeRect);
		}
		else
		{
			pokeRect.w = 30;
			pokeRect.h = 30;
			SDL_RenderCopy(window->GetRender(), pokeHolder->tex, NULL, &pokeRect);
		}
	}

	SDL_RenderCopy(window->GetRender(), menuSprite->tex, NULL, &menuRect);
}

void GUI::BattleSceneGUI(Trainer* ash, Trainer* gary)
{
	if (!animIsOver)
	{
		if (battleSprite == nullptr && ash->backSprite == nullptr && gary->frontSprite == nullptr)
		{
			battleSprite = new Sprite("Assets/Battle/Battle Backgrounds.png", window);
			gary->frontSprite = new Sprite("Assets/Trainers/garyFront.png", window);
			ash->backSprite = new Sprite("Assets/Trainers/AshBack.png", window);
		}

		SDL_Rect dstRect = { 0, 0, window->GetWidth(), window->GetHeight() };
		SDL_Rect srcRect = { 260 * 2, 45 * 4 + 10, 255, 100 };

		SDL_RenderCopy(window->GetRender(), battleSprite->tex, &srcRect, &dstRect);
		SDL_Rect ashRect = { -30, 650, 400, 250 };
		SDL_Rect garyRect = { 1260, 0, 300, 500 };

		while (ashRect.x < 130 && garyRect.x > 1100)
		{
			if (ashRect.x < 130 && garyRect.x > 1100)
			{
				ashRect.x++;
				garyRect.x--;
			}
			SDL_RenderCopy(window->GetRender(), ash->backSprite->tex, NULL, &ashRect);
			SDL_RenderCopy(window->GetRender(), gary->frontSprite->tex, NULL, &garyRect);
			window->Update();
			window->Clear();
			SDL_RenderCopy(window->GetRender(), battleSprite->tex, &srcRect, &dstRect);
			SDL_Delay(3);
		}
		SDL_RenderCopy(window->GetRender(), ash->backSprite->tex, NULL, &ashRect);
		SDL_RenderCopy(window->GetRender(), gary->frontSprite->tex, NULL, &garyRect);



		while (!Input::KeyPressed(Key::SPACE))
		{
			if (Input::KeyPressed(Key::SPACE))
			{
				return;
			}
			window->Update();
		}

		while (ashRect.x >= -190 && garyRect.x <= 1420)
		{
			if (ashRect.x >= -190 && garyRect.x <= 1420)
			{
				ashRect.x--;
				garyRect.x++;
			}
			SDL_RenderCopy(window->GetRender(), ash->backSprite->tex, NULL, &ashRect);
			SDL_RenderCopy(window->GetRender(), gary->frontSprite->tex, NULL, &garyRect);
			window->Update();
			window->Clear();
			SDL_RenderCopy(window->GetRender(), battleSprite->tex, &srcRect, &dstRect);
		}

		ashRect = { -30, 650, 400, 250 };
		garyRect = { 1260, 250, 200, 250 };
		while (ashRect.x < 130 && garyRect.x > 1100)
		{
			if (ashRect.x < 130 && garyRect.x > 1100)
			{
				ashRect.x++;
				garyRect.x--;
			}
			SDL_RenderCopy(window->GetRender(), ash->pokebag[0]->sprite->tex, NULL, &ashRect);
			SDL_RenderCopy(window->GetRender(), gary->pokebag[0]->sprite->tex, NULL, &garyRect);
			window->Update();
			window->Clear();
			SDL_RenderCopy(window->GetRender(), battleSprite->tex, &srcRect, &dstRect);
			SDL_Delay(3);
		}
		SDL_RenderCopy(window->GetRender(), ash->pokebag[0]->sprite->tex, NULL, &ashRect);
		SDL_RenderCopy(window->GetRender(), gary->pokebag[0]->sprite->tex, NULL, &garyRect);
		animIsOver = true;
	}
}
