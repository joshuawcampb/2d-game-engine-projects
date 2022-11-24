#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <iostream>
#include "collisionDetector.h"
#include "gameObject.h"

class collectable{
	
	public:
		collectable();
		void init(SDL_Renderer* ren);
		void render(SDL_Rect* background);
		void quit(int, SDL_Renderer*);
		SDL_Rect getRect();
	
	
	
	private:
	
		SDL_Renderer* game_renderer;
		SDL_Rect tileField;
		const int NUM_TILES = 1200;
		SDL_Rect tile_check;
		SDL_Texture* tile_graphic = NULL;
		const int TILE_WIDTH = 32;
		const int sky = 0;
		const int floor = 1;
		const int cloud = 2;
		const int tileFieldW = 1280;
		const int tileFieldH = 960;
		collisionDetector collide;
		GameObject go;
		int x = 18;
		int y = 2;
		
		SDL_Rect goRect;
		
	
};

#endif
