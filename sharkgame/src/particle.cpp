#include "particle.h"

Particle::Particle(){
	
	
}
		
void Particle::obj_init(const char* graphic, SDL_Renderer* ren, int start_x, int start_y, int width, int height){
	
	SDL_Surface* temp = IMG_Load(graphic);
	obj_graphic = SDL_CreateTextureFromSurface(ren, temp);
	SDL_FreeSurface(temp);
	
	obj_rect.x = start_x;
	obj_rect.y = start_y;
	obj_rect.w = width;
	obj_rect.h = height;
	
}

void Particle::obj_update(){
	
	x_pos = obj_get_x_pos();
	y_pos = obj_get_y_pos();
	
	x_pos += x_vel;
	y_pos += y_vel;
	
	if(lifetime > 0){
			
		obj_rect.x = (int) x_pos;
		obj_rect.y = (int) y_pos;
		obj_rect.w = 32;
		obj_rect.h = 32;
	}
		//obj_rect.w = (int) width/2 + width * (int) (10*lifetime / 100);
		//obj_rect.h = (int) height/2 + height * (int) (10*lifetime / 100);	
		
	lifetime -= 1;

}

void Particle::obj_render(SDL_Renderer* ren){
	
	if(lifetime > 0){
		
		SDL_RenderCopy(ren, obj_graphic, NULL, &obj_rect);
		
	}
	
}

void Particle::obj_quit(){
	
	SDL_DestroyTexture(obj_graphic);
	
}

int Particle::obj_get_x_vel(){
	
	return (int) x_vel;
	
}

int Particle::obj_get_y_vel(){
	
	return (int) y_vel;
	
}

void Particle::obj_set_x_vel(float new_x_vel){
	
	x_vel = new_x_vel;
	
}

void Particle::obj_set_y_vel(float new_y_vel){
	
	y_vel = new_y_vel;
	
}

int Particle::obj_get_x_pos(){
	
	return (int) x_pos;
}

int Particle::obj_get_y_pos(){
	
	return (int) y_pos;
	
}

void Particle::obj_set_x_pos(float new_x_pos){
	
	x_pos = new_x_pos;
	
}

void Particle::obj_set_y_pos(float new_y_pos){
	
	y_pos = new_y_pos;
	
}

int Particle::obj_get_lifetime(){
	
	return lifetime;
	
}

void Particle::obj_set_lifetime(int new_lifetime){
	
	lifetime = new_lifetime;
	
}
