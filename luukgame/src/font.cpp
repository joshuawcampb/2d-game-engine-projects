#include "font.h"

font::font(){
	
	
}

void font::init(SDL_Renderer* ren){
	
	TTF_Init();
	my_ren = ren;
	
	uiFont = TTF_OpenFont("./font.ttf", 20);
	
	if(!uiFont)
		std::cout << "FONT DID NOT LOAD" << std::endl;
	
	color = {255, 255, 255};

	
	font_rect.x = 16;
	font_rect.y = 32;
	
}

void font::update(const char* word){
	
	SDL_Surface* temp = TTF_RenderText_Solid(uiFont, word, color);
	font_graphic = SDL_CreateTextureFromSurface(my_ren, temp);
	SDL_FreeSurface(temp);
	
	int w,h;
	SDL_QueryTexture(font_graphic, NULL, NULL, &w, &h);
	
	font_rect.w = w;
	font_rect.h = h;
	
}

void font::render(){
	
	SDL_RenderCopy(my_ren, font_graphic, NULL, &font_rect);	
	
}

void font::quit(){
	
	TTF_Quit();
	
}
