
#include "collectable.h"

collectable::collectable(){
	
	
}

void collectable::init(SDL_Renderer* ren){
	
	game_renderer = ren;
	go.obj_init(game_renderer, "./bone.png");
	
	tileField.x = x*TILE_WIDTH;
	tileField.y = y*TILE_WIDTH;
	tileField.w = TILE_WIDTH;
	tileField.h = TILE_WIDTH;
	
	go.obj_set_x_pos(x*tileField.w);
	go.obj_set_y_pos(y*tileField.h);
	go.obj_update();
	
}

void collectable::render(SDL_Rect* background){
	
	go.obj_render(game_renderer);
}

void collectable::quit(int, SDL_Renderer*){
	
	go.obj_quit();
	
}

SDL_Rect collectable::getRect(){
	
	return tileField;
	
}
