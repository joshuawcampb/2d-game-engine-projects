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
	
	int w, h;
	
	SDL_QueryTexture(obj_graphic, NULL, NULL, &w, &h);
	
	obj_rect.x = 0;
	obj_rect.y = 0;
	obj_rect.w = w/2;
	obj_rect.h = h; 
	
	obj_sprite->sprite_init(graphic, ren, 2, 100, 0, 0);
	
}

void GameObject::obj_update(){
	
	x_position += x_velocity;
	y_position += y_velocity;
	//keep luuk from going off the left of the screen
	if(x_position < 0)
		x_position = 0;
	//keep luuk from going into the clouds	
	if(y_position < 0+(obj_rect.h/2))
		y_position = 0+(obj_rect.h/2);
	//keep luuk from going off the right side of the screen	
	if(x_position > SCREEN_WIDTH-obj_rect.w)
		x_position = SCREEN_WIDTH-obj_rect.w;
	//keep luuk from going off the bottom of the screen	
	if(y_position > SCREEN_HEIGHT)
		y_position = SCREEN_HEIGHT;
	
	obj_rect.x = x_position;
	obj_rect.y = y_position;
	
	//floor rect
	floor.x = 0;
	floor.y = 416;
	floor.w = 640;
	floor.h = 64;
	
	//if luuk collides with the floor rect then make its
	//position right above the floor
	if(collide.collideBox(&obj_rect, &floor)){
		
		obj_rect.y = 416-obj_rect.h;
		
	}
	
}

void GameObject::obj_render(SDL_Renderer* ren){
	
	
	SDL_Rect frame_rect = obj_sprite->sprite_update();
	SDL_RenderCopy(ren, obj_graphic, &frame_rect, &obj_rect);
	
}

void GameObject::obj_quit(){
	
	obj_sprite->sprite_quit();
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

bool GameObject::checkRects(SDL_Rect* tile){
	
	if(collide.collideBox(&obj_rect, tile)) return true;
	
	return false;
	
}

SDL_Rect GameObject::getRect(){
	
	return obj_rect;
	
}
