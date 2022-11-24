#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <string.h>

class font{
	
	public:
		
		font();
		void init(SDL_Renderer*);
		void update(const char*);
		void render();
		void quit();
	
	
	private:
	
		TTF_Font* uiFont;
		SDL_Texture* font_graphic;
		SDL_Renderer* my_ren;
		SDL_Rect font_rect;
		SDL_Color color;
	
};

#endif
