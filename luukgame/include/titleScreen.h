#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>


class titleScreen{
	
	public:
	
		titleScreen();
		void init(const char*, SDL_Renderer*);
		//void update();
		void render(SDL_Renderer*);
		void quit();
	
	
	
	private:
	
		SDL_Texture* title_graphic;
		SDL_Rect title;
		SDL_Renderer* my_ren;
	
	
};

#endif
