#ifndef EVENT_MANAGER
#define EVENT_MANAGER

#include "SDL2/SDL.h"

class EventManager {
	SDL_Event event;
	bool* quit;
	SDL_Point* user_pos;

	public:
		EventManager(bool*, SDL_Point*);
		void update();
};

EventManager::EventManager(bool* q, SDL_Point* u_p):quit(q), user_pos(u_p) {}

void EventManager::update() {
	while (SDL_PollEvent(&this->event)) {
		switch (this->event.type) {
			case SDL_QUIT:
				*this->quit = true;
				break;
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&this->user_pos->x, &this->user_pos->y);
				break;
			case SDL_KEYDOWN:
				if (this->event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					this->user_pos->x -= 10;
				else if (this->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					this->user_pos->x += 10;
				break;
		}
	}
}

#endif 
