#include "gameEngine.h"

Uint32 this_start_time;
int this_duration;
double frame_duration = 16.667;

int main(){
	
	GameEngine* ge = new GameEngine();
	
	ge->init();
	
	while(ge->get_game_is_running()){
	
		this_start_time = SDL_GetTicks();
		
		ge->handleEvents();
		ge->updateMechanics();
		ge->render();
	
		this_duration = SDL_GetTicks() - this_start_time;
		
		if(this_duration < frame_duration){
		
			SDL_Delay(frame_duration - this_duration);
		
		}
	
	}

	ge->quit();

	return 0;

}
