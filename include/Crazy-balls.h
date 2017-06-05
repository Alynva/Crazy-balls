#ifndef CRAZY_BALLS
#define CRAZY_BALLS

#include "SDL2/SDL.h"

#include "Ball.h"

class CrazyBalls {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	Ball ball;

	public:
		CrazyBalls():window(nullptr), renderer(nullptr), ball(this->renderer, {10, 10}, {10, 10}) {};
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
	this->window = SDL_CreateWindow("Crazy Balls", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
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
	Ball temp(this->renderer, {10, 10}, {10, 10});
	this->ball = temp;
	return true;
}

void CrazyBalls::run() {
	bool quit = false;
	SDL_Rect* r = new SDL_Rect;
	r->x = 20;
	r->y = 40;
	r->w = 50;
	r->h = 50;
	while (!quit) {
		while (SDL_PollEvent(&this->event)) {
			switch(this->event.type) {
				case SDL_QUIT:
					quit = true;
					break;
			}
		}
		SDL_RenderClear(this->renderer);
		SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
		SDL_Point pos;
		SDL_GetMouseState(&pos.x, &pos.y);
		ball.setPosition(pos);
		ball.render();
		r->x = pos.x - 1;
		r->y = pos.y - 1;
		SDL_RenderFillRect(this->renderer, r); 
		SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
		SDL_RenderPresent(this->renderer);
	}
}

#endif
