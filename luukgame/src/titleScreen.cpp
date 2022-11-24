#include "titleScreen.h"

titleScreen::titleScreen(){
	
	
}

void titleScreen::init(const char* graphic, SDL_Renderer* ren){
	
	SDL_Surface* temp = IMG_Load(graphic);
	title_graphic = SDL_CreateTextureFromSurface(ren, temp);
	SDL_FreeSurface(temp);
	title.x = 0;
	title.y = 0;
	title.w = 640;
	title.h = 480; 
	
	//my_ren = ren;
	
}

void titleScreen::render(SDL_Renderer* ren){
	
	SDL_RenderCopy(ren, title_graphic, NULL, &title);
	//SDL_RenderPresent(my_ren);
	
}

void titleScreen::quit(){
	
	SDL_DestroyTexture(title_graphic);
}
