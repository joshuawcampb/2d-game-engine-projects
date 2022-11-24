#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "gameObject.h"
#include "tileHandler.h"
#include "particle.h"
#include "particleEmitter.h"
#include "titleScreen.h"
#include "pauseMenu.h"
#include "collisionDetector.h"
#include "font.h"
#include "collectable.h"

class GameEngine{
	
	public:
		GameEngine();
	
		void init();
		void handleEvents();
		void updateMechanics();
		void render();
		void quit();
		bool get_game_is_running();
	
	private:
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;

		SDL_Window* my_window = NULL;
		SDL_Renderer* my_renderer = NULL;
		SDL_Event input;
		
		GameObject go = GameObject();
		SDL_Rect rect2;
		int control_mode = 1;
		const int PLAYER_STEP = 50;
		const int PLAYER_VEL = 1;
		int left = 0;
		bool title = true;
		bool pause = true;
		bool game_is_running = true;
		const int NUM_ELEMS = 200;
	
		
		spriteManager* sprites = new spriteManager();
		tileHandler* tiles = new tileHandler();
		SDL_Rect background;
		SDL_Rect tilef;
		//Particle* particle = new Particle();
		ParticleEmitter* particleEmitter = new ParticleEmitter;
		
		titleScreen screen = titleScreen();
		pauseMenu menu = pauseMenu();
		
		collisionDetector collide;
		SDL_Rect one;
		bool gameOver = false;
		int deaths = 0;
		bool win = false;
		
		font ft;
		collectable co;
	
};

#endif
