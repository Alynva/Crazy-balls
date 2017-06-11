#ifndef CRAZY_BALLS
#define CRAZY_BALLS

#include "EventManager.h"
#include "Ball.h"
#include "Player.h"

class CrazyBalls {
	SDL_Window* window;
	SDL_Renderer* renderer;
	EventManager event;
	bool quit;
	Ball ball;
	Player player;
	SDL_Point mouse_pas;

	public:
		CrazyBalls():window(nullptr), renderer(nullptr), event(&quit, &mouse_pas), quit(false), ball("../media/imgs/Dark_Matter_Ball.png", this->renderer, {10, 10, 10, 10}), player("../media/imgs/Dark_Matter_Rectangle.png", this->renderer, {50, 150, 50, 10}) {};
		~CrazyBalls();
		bool init();
		void run();
};

CrazyBalls::~CrazyBalls() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	this->renderer = nullptr;
	this->window = nullptr;

	SDL_Quit();
}

bool CrazyBalls::init() {
	this->window = SDL_CreateWindow("Crazy Balls v0.1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
	if (this->window == NULL) {
		SDL_Log("Window could not be created. SDL Error: %s", SDL_GetError());
		return false;
	} else {
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
		if (this->renderer == NULL) {
			SDL_Log("Renderer could not be created. SDL Error: %s", SDL_GetError());
			return false;
		} else {
			SDL_SetRenderDrawColor(this->renderer, 55, 55, 155, 255);
		}
	}
	this->ball.setRenderer(this->renderer);
	this->player.setRenderer(this->renderer);
	return true;
}

void CrazyBalls::run() {
	while (!this->quit) {
		this->event.update();		

		SDL_RenderClear(this->renderer);
		SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

		ball.render();

		player.setPosition({this->mouse_pas.x, 450});
		player.render();

		SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
		SDL_RenderPresent(this->renderer);
	}
}

#endif
