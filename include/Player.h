#ifndef PLAYER
#define PLAYER

#include "Object.h"

class Player : public Object {

	public:
		Player(std::string s, SDL_Renderer* r, SDL_Rect rect):Object(s, r, rect) {};
};

#endif