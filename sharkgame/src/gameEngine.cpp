#include "gameEngine.h"

GameEngine::GameEngine(){
	
}

void GameEngine::init(){
	
	SDL_Init(SDL_INIT_EVERYTHING); 	
	IMG_Init(IMG_INIT_PNG);
	my_window = SDL_CreateWindow("my_game", 
				SDL_WINDOWPOS_CENTERED, 
				SDL_WINDOWPOS_CENTERED, 
				SCREEN_WIDTH,
				SCREEN_HEIGHT, 0);
	my_renderer = SDL_CreateRenderer(my_window,-1,0);
	go.obj_init(my_renderer, "./shark.png");
	tiles->tile_init(my_renderer);
	particleEmitter->pe_init("./particle.png", my_renderer, 0, 0, 32, 32, 0);
	
}

void GameEngine::handleEvents(){
	
	SDL_Event game_event;
	SDL_PollEvent(&game_event);
	if(game_event.type == SDL_QUIT) game_is_running = false;
	//prevent fake key presses
	if(game_event.type == SDL_KEYDOWN && game_event.key.repeat == 0){
		
		switch(game_event.key.keysym.sym){
			
			case SDLK_1:
				control_mode = 1;
				if(game_event.type == SDL_KEYDOWN)
					std::cout << "Velocity Control Metaphor" << std::endl;
				break;
			
			case SDLK_2:
				control_mode = 2;
				if(game_event.type == SDL_KEYDOWN)
					std::cout << "Position Control Metaphor" 
						<< std::endl;
				break;
			
			default:
				break;
		
		}
		
		if(control_mode == 1){
			
			go.obj_init(my_renderer, "./shark.png");
			
			switch(game_event.key.keysym.sym){
				
				case SDLK_UP:
					go.obj_set_y_vel(-1*PLAYER_VEL);
					std::cout << "UP key pressed" << std::endl;
					break;
					
				case SDLK_DOWN:
					go.obj_set_y_vel(PLAYER_VEL);
					std::cout << "DOWN key pressed" << std::endl;
					break;
				
				case SDLK_LEFT:
					go.obj_set_x_vel(-1*PLAYER_VEL);
					std::cout << "LEFT key pressed" << std::endl;
					break;
					
				case SDLK_RIGHT:
					go.obj_set_x_vel(PLAYER_VEL);
					std::cout << "RIGHT key pressed" << std::endl;
					break;	
				
			}
		}
		
		else{
			
			//make velocity 0 so it doesn't affect control metaphor
			go.obj_set_x_vel(0);
			go.obj_set_y_vel(0);
			
			go.obj_init(my_renderer, "./eat.png");
			
			switch(game_event.key.keysym.sym){
				
				case SDLK_UP:
					go.obj_set_y_pos(go.obj_get_y_pos()-PLAYER_STEP);
					std::cout << "UP key pressed" << std::endl;
					break;
					
				case SDLK_DOWN:
					go.obj_set_y_pos(go.obj_get_y_pos()+PLAYER_STEP);
					std::cout << "DOWN key pressed" << std::endl;
					break;
				
				case SDLK_LEFT:
					go.obj_set_x_pos(go.obj_get_x_pos()-PLAYER_STEP);
					std::cout << "LEFT key pressed" << std::endl;
					break;
					
				case SDLK_RIGHT:
					go.obj_set_x_pos(go.obj_get_x_pos()+PLAYER_STEP);
					std::cout << "RIGHT key pressed" << std::endl;
					break;	
					
				default:
					break;
				
			}	
		}
	}
	
}

void GameEngine::updateMechanics(){
 
	rect2.x = 0;
	rect2.y = SCREEN_HEIGHT-50;
	rect2.w = SCREEN_WIDTH;
	rect2.h = 50;
	
	background.x = 0;
	background.y = 0;
	background.w = 32;
	background.h = 32;
	
	go.obj_update();
	particleEmitter->pe_update();
	
}

void GameEngine::render(){
	
	tiles->tile_render(&background);
	
	go.obj_render(my_renderer, &background);
	particleEmitter->pe_render(my_renderer);

	SDL_RenderPresent(my_renderer);
	
	
}

bool GameEngine::get_game_is_running(){
	
	return game_is_running;
	
}

void GameEngine::quit(){
	
	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);
	go.obj_quit();

	IMG_Quit();
	SDL_Quit();
	
	
}
