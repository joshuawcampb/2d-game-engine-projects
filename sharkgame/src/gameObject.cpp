#include "gameObject.h"

GameObject::GameObject(SDL_Renderer* ren){
	obj_renderer = ren;
}

GameObject::GameObject(){
}

void GameObject::obj_init(SDL_Renderer* ren, const char* graphic){

	SDL_Surface* temp = IMG_Load(graphic);
	obj_graphic = SDL_CreateTextureFromSurface(ren, temp);
	SDL_FreeSurface(temp);
	obj_rect.x = 0;
	obj_rect.y = 0;
	obj_rect.w = 160;
	obj_rect.h = 82; 
	
	obj_sprite->sprite_init(graphic, ren, 2, 100, 0, 0);
	
}

void GameObject::obj_update(){
	
	x_position += x_velocity;
	y_position += y_velocity;

	if (x_position < (0 - SCREEN_WIDTH/2)) 
		{x_velocity += -1;}
	if (x_position > (SCREEN_WIDTH - SCREEN_WIDTH/2)) 
		{x_velocity += -1;}
	if (y_position < (0 - SCREEN_HEIGHT/2)) 
		{y_velocity += -1;}
	if (y_position > (SCREEN_WIDTH - SCREEN_HEIGHT/2)) 
		{y_velocity += -1;}

	if (x_position < (0 - SCREEN_WIDTH/2)) 
		{x_position = 0 - SCREEN_WIDTH/2;}
	if (x_position > (SCREEN_WIDTH - SCREEN_WIDTH/2)) 
		{x_position = SCREEN_WIDTH - SCREEN_WIDTH/2;}
	if (x_position < (0 - SCREEN_HEIGHT/2)) 
		{y_position = 0 - SCREEN_HEIGHT/2;}
	if (x_position > (SCREEN_WIDTH - SCREEN_HEIGHT/2)) 
		{y_position = SCREEN_HEIGHT - SCREEN_HEIGHT/2;}

	if (x_velocity < (-1*MAX_VEL)) {x_velocity = -1*MAX_VEL;}
	if (x_velocity > (MAX_VEL)) {x_velocity = MAX_VEL;}
	if (y_velocity < (-1*MAX_VEL)) {y_velocity = -1*MAX_VEL;}
	if (y_velocity > (MAX_VEL)) {y_velocity = MAX_VEL;}
	
	obj_rect.x = x_position;
	obj_rect.y = y_position;
	
	//seafloor rect
	seaFloor.x = 0;
	seaFloor.y = 416;
	seaFloor.w = 640;
	seaFloor.h = 64;
	
	//if the shark collides with the seafloor rect then make its
	//position right above the seafloor
	if(collide.collideBox(&obj_rect, &seaFloor)){
		
		obj_rect.y = 334;
		
	}
	
}

void GameObject::obj_render(SDL_Renderer* ren, SDL_Rect * background){
	
	
	SDL_Rect frame_rect = obj_sprite->sprite_update();
	SDL_RenderCopy(ren, obj_graphic, &frame_rect, &obj_rect);
	
}

void GameObject::obj_quit(){
	
	SDL_DestroyTexture(obj_graphic);
	
}

int GameObject::obj_get_x_vel(){
	
	return x_velocity;
	
}
void GameObject::obj_set_x_vel(int x_vel){
	
	x_velocity = x_vel;
	
}

int GameObject::obj_get_y_vel(){
	
	return y_velocity;
	
}

void GameObject::obj_set_y_vel(int y_vel){
	
	y_velocity = y_vel;
	
}

int GameObject::obj_get_x_pos(){
	
	return x_position;
	
}
void GameObject::obj_set_x_pos(int x_pos){
	
	x_position = x_pos;
	
}

int GameObject::obj_get_y_pos(){
	
	return y_position;
	
}

void GameObject::obj_set_y_pos(int y_pos){
	
	y_position = y_pos;
	
}
