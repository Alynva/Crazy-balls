#ifndef BALL
#define BALL

#include "Object.h"

class Ball : public Object {

	public:
		Ball(std::string s, SDL_Renderer* r, SDL_Rect rect):Object(s, r, rect) {};
};

#endif
