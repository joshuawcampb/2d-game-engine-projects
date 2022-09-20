#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "spriteManager.h"
#include "tileHandler.h"
#include "collisionDetector.h"

class GameObject{

	public:
		GameObject(SDL_Renderer* ren);
		GameObject();
		
		void obj_init(SDL_Renderer*, const char*);
		void obj_update();
		void obj_render(SDL_Renderer*, SDL_Rect*);
		void obj_quit();
		
		int obj_get_x_vel();
		void obj_set_x_vel(int x_vel);
		int obj_get_y_vel();
		void obj_set_y_vel(int y_vel);
		
		int obj_get_x_pos();
		void obj_set_x_pos(int x_pos);
		int obj_get_y_pos();
		void obj_set_y_pos(int y_pos);
		
		
	private:
		SDL_Renderer* obj_renderer;
		
		SDL_Texture* obj_graphic = NULL;
		SDL_Rect obj_rect;
		
		spriteManager* obj_sprite = new spriteManager();
		
		SDL_Rect frame_rect;
		
		static const int SCREEN_WIDTH = 640;
		static const int SCREEN_HEIGHT = 480;
		int x_velocity;
		int y_velocity;
		int x_position;
		int y_position;
		const int MAX_VEL = 5;
		
		SDL_Rect seaFloor;
		collisionDetector collide;
	
};

#endif
