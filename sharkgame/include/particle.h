#ifndef PARTICLE_H
#define PARTICLE_H

const int MAX_PARTS = 100;
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <iostream>

class Particle {
	
	public:
		Particle();
		
		void obj_init(const char* graphic, SDL_Renderer* ren, int start_x, int start_y, int width, int height);
		
		void obj_update();
		void obj_render(SDL_Renderer*);
		
		void obj_quit();
		
		int obj_get_x_vel();
		int obj_get_y_vel();
		void obj_set_x_vel(float);
		void obj_set_y_vel(float);
		
		int obj_get_x_pos();
		int obj_get_y_pos();
		void obj_set_x_pos(float);
		void obj_set_y_pos(float);
		
		int obj_get_lifetime();
		void obj_set_lifetime(int);
		
		
		private:
			SDL_Texture* obj_graphic;
			SDL_Rect obj_rect;
			SDL_Rect tile_rect;
			
			float x_pos;
			float y_pos;
			float x_vel;
			float y_vel;
			
			int width;
			int height;
			
			int state;
			float lifetime;
			
			SDL_Renderer* obj_renderer;
	
	
};

#endif
