#include "collisionDetector.h"

collisionDetector::collisionDetector(){
	
	
}

bool collisionDetector::collideBox(SDL_Rect* A, SDL_Rect* B){
	
	//Left, Right, Top, Bottom
	aL = A->x;
	aR = A->x + A->w;
	aT = A->y;
	aB = A->y + A->h;
	
	bL = B->x;
	bR = B->x + B->w;
	bT = B->y;
	bB = B->y + B->h;
	
	//right side A less than left side B
	if(aR < bL) return false;
	//left side A greater than right side B
	if(aL > bR) return false;
	//bottom A less than top B
	if(aB < bT) return false;
	//top A greater than bottom B
	if(aT > bB) return false;
	
	return true;
	
	
}
