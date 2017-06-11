#ifndef OBJECT
#define OBJECT

#include "Texture.h"

class Object {
	Texture texture;

	public:
		Object();
		Object(std::string, SDL_Renderer*, SDL_Rect);

		void setRenderer(SDL_Renderer*);
		void setSize(SDL_Point);
		SDL_Point getSize() const;
		void setPosition(SDL_Point);
		SDL_Point getPosition() const;
		void render();
};

Object::Object(std::string s, SDL_Renderer* r, SDL_Rect rect):texture(s, r, rect) {
	/* EMPTY */
}

void Object::setRenderer(SDL_Renderer* renderer) {
	this->texture.setRenderer(renderer);
}

void Object::setSize(SDL_Point s) {
	this->texture.setSize(s);
}
SDL_Point Object::getSize() const {
	return this->texture.getSize();
}

void Object::setPosition(SDL_Point p) {
	this->texture.setPosition(p);
}
SDL_Point Object::getPosition() const {
	return this->texture.getPosition();
}

void Object::render() {
	this->texture.render();
}

#endif