#ifndef BALL
#define BALL

#include "SDL2/SDL.h"

class Ball {
	SDL_Renderer* renderer;
	SDL_Point position;
	SDL_Point size;

	public:
		Ball();
		Ball(SDL_Renderer* r, SDL_Point p, SDL_Point s):renderer(r), position(p), size(s) {};
		void render() {
			SDL_RenderDrawPoints(this->renderer, &this->position, 1);
		};
		void setPosition(SDL_Point p) {
			this->position = {p.x - 10, p.y - 10};
		}
};

#endif
