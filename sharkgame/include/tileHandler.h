#ifndef TILEHANDLER_H
#define TILEHANDLER_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <iostream>

class tileHandler{
	
	public:
		tileHandler();
		void tile_init(SDL_Renderer* ren);
		void tile_render(SDL_Rect* background);
		void tile_quit();
	
	
	
	private:
	
		SDL_Renderer* game_renderer;
		SDL_Rect tileField;
		const int NUM_TILES = 1200;
		SDL_Texture* tile_graphic = NULL;
		const int TILE_WIDTH = 32;
		const int water = 0;
		const int floor = 1;
		const int fish = 2;
		const int tileFieldW = 1280;
		const int tileFieldH = 960;
		
	
};

#endif
