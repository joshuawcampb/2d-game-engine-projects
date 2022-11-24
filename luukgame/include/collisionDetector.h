#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <iostream>

class collisionDetector{
	
	public:
		
		collisionDetector();
		
		bool collideBox(SDL_Rect*, SDL_Rect*);
	
	
	private:
	
		int aL;
		int aR;
		int aB;
		int aT;
		int bL;
		int bR;
		int bT;
		int bB;
	
	
};

#endif
