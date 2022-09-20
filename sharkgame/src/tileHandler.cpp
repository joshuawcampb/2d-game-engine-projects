#include "tileHandler.h"

tileHandler::tileHandler(){
	
}

void tileHandler::tile_init(SDL_Renderer* ren){
	
	game_renderer = ren;
	
	SDL_Surface* temp = IMG_Load("./tilesheet.png");
	tile_graphic = SDL_CreateTextureFromSurface(game_renderer, temp);
	SDL_FreeSurface(temp);
	
	tileField.x = 0;
	tileField.y = 0;
	tileField.w = TILE_WIDTH;
	tileField.h = TILE_WIDTH;
	
}

void tileHandler::tile_render(SDL_Rect* background){

	
	bool fish = false;
	bool bottom = false;
	
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 20; j++){
			
			if((j == 2 && i == 5) || (j == 8 && i == 8) || (j == 12 && i == 12)){
				
				fish = true;
				
			}
			
			else if(i == 13 || i == 14){ bottom = true; }
			
			SDL_RenderCopy(game_renderer, tile_graphic, &tileField, background);
			
			if(fish){
				
				tileField.x += (2*tileField.w);
				SDL_RenderCopy(game_renderer, tile_graphic, &tileField, background);
				
			}
			
			else if(bottom){
			
				tileField.x += (1*tileField.w);
				SDL_RenderCopy(game_renderer, tile_graphic, &tileField, background);
			
			}
			
			fish = false;
			bottom = false;
			tileField.x = 0;
			
			background->x += background->w;
			
			
		}
		
		background->x = 0;
		background->y += background->h;
	
	}
	
}

void tileHandler::tile_quit(){
	
	
}
