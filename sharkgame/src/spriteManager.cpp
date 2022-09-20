#include "spriteManager.h"

spriteManager::spriteManager(){
}

void spriteManager::sprite_init(const char* graphic, SDL_Renderer* ren,
	int frames, int frameDuration, int start_width,
	int start_height){
		
		frame_duration = frameDuration;
		game_renderer = ren;
		frame_count = frames;
		
		SDL_Surface* temp = IMG_Load(graphic);
		sprite_graphic = SDL_CreateTextureFromSurface(ren, temp);
		SDL_FreeSurface(temp);
		frame_rect.w = 80;
		frame_rect.h = 41;
		frame_rect.x = 0;
		frame_rect.y = 0;
		
}
	
SDL_Rect spriteManager::sprite_update(){
	
	int frame_time = (int)(SDL_GetTicks()/frame_duration) % frame_count;
	std::cout << "Frame:" << frame_time << std::endl;
	
	static int last_frame_time = 0;
	
	if(last_frame_time != frame_time){
		
		if(frame_time < 1){
			frame_rect.x = 0;
		}
		
		else{
			
			frame_rect.x += frame_rect.w;
			
		}
		
	}
	
	last_frame_time = frame_time;
	
	return(frame_rect);
	
	
}

void spriteManager::sprite_render(SDL_Renderer* ren){
	
	SDL_RenderCopy(ren, sprite_graphic, NULL, &frame_rect);
	
}

void spriteManager::sprite_quit(){
	
	
}
