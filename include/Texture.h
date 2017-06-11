/*
	Classe responsável por facilitar o uso das Texturas SDL.

	Declaração: o construtor sem parâmetros não inicializa nada, enquanto que o que recebe seis parâmetros, uma std::string, um renderizador do SDL e quatro inteiros, cria a Texture, utilizando os dois primeiros inteiros para a posição e os outros dois para o tamanho.
	Métodos:
		setSize: recebe dois inteiros, x e y, respectivamente, e muda a posição da carta, usando os valores de x e y.
		setPosition: recebe dois inteiros, h e w, altura e largura, respectivamente, e muda o tamanho da carta, usando os valores de h e w.
		render: renderiza a carta na janela principal.
	Detalhes:
*/

#ifndef TEXTURA
#define TEXTURA

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

class Texture {
	SDL_Rect rect;
	SDL_Texture* tex;
	SDL_Renderer* renderer;
	std::string img_path;
	
	SDL_Texture* loadTexture();

	public:
		Texture();
		Texture(std::string, SDL_Renderer*, SDL_Rect);

		void setRenderer(SDL_Renderer*);
		SDL_Point getSize() const;
		void setSize(SDL_Point);
		SDL_Point getPosition() const;
		void setPosition(SDL_Point);
		SDL_Texture* getTexture() const;
		void render();
};

SDL_Texture* Texture::loadTexture() {
	if (this->img_path != "") {
		// Textura final
		SDL_Texture* new_Texture = NULL;

		// Carrega imagem a partir de um caminho
		SDL_Surface* loaded_surface = IMG_Load(this->img_path.c_str());
		if (loaded_surface == NULL) {
//			cout << "Unable to load image " << this->img_path.c_str() << ". SDL_Image Error: " << IMG_GetError() << endl;
		} else {
			// Cria Texture dos pixels da superficie
			new_Texture = SDL_CreateTextureFromSurface(this->renderer, loaded_surface);
			if (new_Texture == NULL) {
//				cout << "Unable to create Texture from " << this->img_path.c_str() << ". SDL Error: " << SDL_GetError() << endl;
			}

			// Deleta a superficie
			SDL_FreeSurface(loaded_surface);
		}

		return new_Texture;
	}
	return NULL;
}

Texture::Texture(std::string path, SDL_Renderer* renderer, SDL_Rect rectangle):rect(rectangle), renderer(renderer) {
	this->img_path = path;
	this->tex = this->loadTexture();
}

void Texture::setRenderer(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->tex = this->loadTexture();
}

SDL_Point Texture::getSize() const {
	return {this->rect.w, this->rect.h};
}
void Texture::setSize(SDL_Point size) {
	this->rect.w = size.x;
	this->rect.h = size.y;
}

SDL_Point Texture::getPosition() const {
	return {this->rect.x, this->rect.y};
}
void Texture::setPosition(SDL_Point coord) {
	this->rect.x = coord.x;
	this->rect.y = coord.y;
}
SDL_Texture* Texture::getTexture() const {
	return this->tex;
}
void Texture::render() {
	SDL_RenderCopy(this->renderer, this->tex, NULL, &this->rect);
}


#endif