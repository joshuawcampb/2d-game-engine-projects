#include "pauseMenu.h"

pauseMenu::pauseMenu(){
	
	
}

void pauseMenu::init(const char* graphic, SDL_Renderer* ren){
	
	SDL_Surface* temp = IMG_Load(graphic);
	pause_graphic = SDL_CreateTextureFromSurface(ren, temp);
	SDL_FreeSurface(temp);
	pause.x = 0;
	pause.y = 0;
	pause.w = 640;
	pause.h = 480; 
	
	my_ren = ren;
	
}

void pauseMenu::render(SDL_Renderer* ren){
	
	SDL_RenderCopy(ren, pause_graphic, NULL, &pause);
	//SDL_RenderPresent(my_ren);
	
}

void pauseMenu::quit(){
	
	SDL_DestroyTexture(pause_graphic);
}
