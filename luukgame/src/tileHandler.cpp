#include "tileHandler.h"

tileHandler::tileHandler(){
	
}

void tileHandler::tile_init(SDL_Renderer* ren){
	
	game_renderer = ren;
	
	SDL_Surface* temp = IMG_Load("./tilesheet2.png");
	tile_graphic = SDL_CreateTextureFromSurface(game_renderer, temp);
	SDL_FreeSurface(temp);
	
	tileField.x = 0;
	tileField.y = 0;
	tileField.w = TILE_WIDTH;
	tileField.h = TILE_WIDTH;
	
}

void tileHandler::tile_render(SDL_Rect* background){

	
	bool cloud = false;
	bool bottom = false;
	int k = 0;
	
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 20; j++){
			
			tile_check.x = (i * 32);
			tile_check.y = (j * 32);
			tile_check.w = TILE_WIDTH;
			tile_check.h = TILE_WIDTH;
			
			if(i == 0){
				
				cloud = true;
				
			}
			
			else if(i == 13 || i == 14){ bottom = true; }
			
			
			SDL_RenderCopy(game_renderer, tile_graphic, &tileField, background);
			
			if(cloud){
					
				tileField.x = (2*tileField.w);
				SDL_RenderCopy(game_renderer, tile_graphic, &tileField, background);
					
			
			}
			
			else if(bottom){
			
				tileField.x += (1*tileField.w);
				SDL_RenderCopy(game_renderer, tile_graphic, &tileField, background);
			
			}
			
			if(((i>=1 && i <=4) && (j == 7 || j == 15)) || ((i>=10 && i <=12) && (j == 7 || j == 15))) {	
				
				go[k].obj_init(game_renderer, "./saw.png");
				go[k].obj_set_x_pos(j*32);
				go[k].obj_set_y_pos(i*32);
				go[k].obj_update();
				go[k].obj_render(game_renderer);
				k++;
				goRect[k].x = j*32;
				goRect[k].y = i*32;
				goRect[k].w = 32;
				goRect[k].h = 32;
				
			
			}
			
			if( i == 2 && j == 18 ){
				
				go[k].obj_init(game_renderer, "./bone.png");
				go[k].obj_set_x_pos(j*32);
				go[k].obj_set_y_pos(i*32);
				go[k].obj_update();
				go[k].obj_render(game_renderer);
				k++;
				
				
			}
			
			cloud = false;
			bottom = false;
		
			tileField.x = 0;
			
			background->x += background->w;
			
			
		}
		
		background->x = 0;
		background->y += background->h;
	
	}
	
}

void tileHandler::tile_quit(int num, SDL_Renderer* ren){
	
}

SDL_Rect tileHandler::getRect(int num){
	
	return go[num].getRect();
	
}
