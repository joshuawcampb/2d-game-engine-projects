#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>


class pauseMenu{
	
	public:
	
		pauseMenu();
		void init(const char*, SDL_Renderer*);
		void render(SDL_Renderer*);
		void quit();
	
	
	
	private:
	
		SDL_Texture* pause_graphic;
		SDL_Rect pause;
		SDL_Renderer* my_ren;
	
	
};

#endif
