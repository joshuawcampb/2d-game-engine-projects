#include "gameEngine.h"

GameEngine::GameEngine(){
	
}

void GameEngine::init(){
	
	if(!gameOver){
		SDL_Init(SDL_INIT_EVERYTHING); 	
		IMG_Init(IMG_INIT_PNG);
		
		my_window = SDL_CreateWindow("my_game", 
					SDL_WINDOWPOS_CENTERED, 
					SDL_WINDOWPOS_CENTERED, 
					SCREEN_WIDTH,
					SCREEN_HEIGHT, 0);
		my_renderer = SDL_CreateRenderer(my_window,-1,0);
		ft.init(my_renderer);
	}
	
	if(gameOver){
		
		deaths++;
		std::cout << deaths << std::endl;
		std::string num = std::to_string(deaths);
		std::string word = "Deaths: ";
		std::string word2 = "Deaths: ";
		word2 = word + num;
		
		const char* word3 = word2.c_str();
		
		ft.update(word3);
		
		title = false;
		pause = false;
		go.obj_set_x_pos(0);
		go.obj_set_y_pos(0);
		control_mode = 1;
		
	}		
	
	gameOver = false;

	go.obj_init(my_renderer, "./luuk3.png");
	tiles->tile_init(my_renderer);
	co.init(my_renderer);
	particleEmitter->pe_init("./particle.png", my_renderer, 0, 0, 32, 32, 0);
		
}

void GameEngine::handleEvents(){
	
	if(win){
		
		return;
		
	}
	
	if(!pause){
		for(int i = 0; i < NUM_ELEMS; i++){
				
				
			SDL_Rect two = tiles->getRect(i);
			
			if(go.checkRects(&two) && control_mode == 2){
				
				gameOver = true;
				pause = true;
				return;
				
			}
		
			SDL_Rect colRect = co.getRect();
			
			if(go.checkRects(&colRect) && control_mode == 2){

				win = true;
				return;
				
			}		
		}	
	}
	
	SDL_Event game_event;
	SDL_PollEvent(&game_event);
	
	if(control_mode == 1) {go.obj_set_y_pos(416);}
	
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
				go.obj_init(my_renderer, "./luukfly.png");
				if(game_event.type == SDL_KEYDOWN)
					std::cout << "Position Control Metaphor" 
						<< std::endl;
				break;
			
			default:
				break;
		
		}
		
		if(control_mode == 1){
			
			switch(game_event.key.keysym.sym){
				
				case SDLK_UP:
					go.obj_set_y_pos(300);	
								
					std::cout << "UP key pressed" << std::endl;
					break;
				
				case SDLK_LEFT:
					left = 1;
					go.obj_init(my_renderer, "./luukflip2.png");
					go.obj_set_x_vel(-1*PLAYER_VEL*5);
					
					
					std::cout << "LEFT key pressed" << std::endl;
					break;
					
				case SDLK_RIGHT:
					left = 0;
					go.obj_init(my_renderer, "./luuk2.png");
					go.obj_set_x_vel(PLAYER_VEL*5);
					

					std::cout << "RIGHT key pressed" << std::endl;
					break;	
				
					
				case SDLK_SPACE:
					if(pause){
						if(title){
							title = false;
							
							screen.quit();
						}
						
						pause = false;
					}
					
				
					break;
					
				case SDLK_ESCAPE:
					if(pause == false)
						pause = true;
						
					else
						game_is_running = false;
						
					break;
					
				default:
				
					break;
			}
										
		}
			
		else if(control_mode == 2){
			
			//make velocity 0 so it doesn't affect control metaphor
			go.obj_set_x_vel(0);
			go.obj_set_y_vel(0);
			
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
					left = 1;
					go.obj_set_x_pos(go.obj_get_x_pos()-PLAYER_STEP);
					std::cout << "LEFT key pressed" << std::endl;
					break;
					
				case SDLK_RIGHT:
					left = 0;
					go.obj_set_x_pos(go.obj_get_x_pos()+PLAYER_STEP);
					std::cout << "RIGHT key pressed" << std::endl;
					break;	
				
				case SDLK_SPACE:
					if(pause){
						if(title){
							title = false;
							
							screen.quit();
						}
						
						pause = false;
					}
					break;
					
				case SDLK_ESCAPE:
					if(pause == false)
						pause = true;
					
					else
						game_is_running = false;
							
					break;
					
				default:
				
					break;
				
			}	
		}
	}
	
	else{
				

		if(left == 1 && control_mode == 1){
			
			go.obj_init(my_renderer, "./luuk3flip.png");
			
		}
		
		else if(left == 0 && control_mode == 1){
			
			go.obj_init(my_renderer, "./luuk3.png");
			
		}
		
		else if(left == 1 && control_mode == 2){
			
			go.obj_init(my_renderer, "./luukflyflip.png");
		}
		
		else{
			
			go.obj_init(my_renderer, "./luukfly.png");
			
		}
		
		go.obj_set_x_vel(0);
		
	}

}

void GameEngine::updateMechanics(){
	
	if(win)
		return;
		
	if(gameOver){
	
		return;
	}
	
	if(title){
		
		ft.update("Deaths: 0");
		
	}
		
	if(!pause){
	
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
}

void GameEngine::render(){

	if(win){
				
		screen.init("./win.png", my_renderer);
		screen.render(my_renderer);
		
		SDL_Event game_event;
			SDL_PollEvent(&game_event);
		
		if(game_event.key.keysym.sym == SDLK_ESCAPE){
				
				game_is_running = false;
				
		}
					
	}
	
	else if(gameOver){
			
		screen.init("./gameover.png", my_renderer);
		screen.render(my_renderer);
		
		SDL_Event game_event;
		SDL_PollEvent(&game_event);
		
		if(game_event.key.keysym.sym == SDLK_ESCAPE){
			
			game_is_running = false;
			
		}
		
		else if(game_event.key.keysym.sym == SDLK_SPACE){
			
			go.obj_quit();			
			init();
			
		}
			
	}
	
	else if(pause){
		
		if(title){
			screen.init("./title.png", my_renderer);
			screen.render(my_renderer);
		}
		
		else{
			menu.init("./pause.png", my_renderer);
			menu.render(my_renderer);
		}
		
	}
				
	else{
		
		tiles->tile_render(&background);
		particleEmitter->pe_render(my_renderer);
		go.obj_render(my_renderer);
		ft.render();
		
	}
	
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
