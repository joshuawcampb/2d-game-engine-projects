#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <iostream>

class spriteManager{
	
	public:
		
		spriteManager();
		void sprite_init(const char* graphic, SDL_Renderer* ren,
			int frames, int frame_duration, int start_width,
			int start_height);
			
		SDL_Rect sprite_update();
		void sprite_render(SDL_Renderer* ren);
		void sprite_quit();
	
	
	private:
		
		SDL_Texture* sprite_graphic;
		SDL_Rect frame_rect;
		
		int frame = 0;
		int frame_count;
		int frame_duration;
		
		SDL_Renderer* game_renderer;
		
		
	
	
	
};

#endif
