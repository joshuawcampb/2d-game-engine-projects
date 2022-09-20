#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "particle.h"

class ParticleEmitter{
	
	public:
		ParticleEmitter();
	
		void pe_init(const char* graphic, SDL_Renderer* ren, int start_x, int start_y, int width, int height, int type);
		void pe_update();
		void pe_render(SDL_Renderer* ren);
		
		void pe_quit();
		
	private:

		const char* image;
		SDL_Renderer* my_renderer;
		int x;
		int y;
		int w;
		int h;
		int t;

		Particle particles[MAX_PARTS];
		const int PART_TYPE_BUBBLE = 0;
		const int MAX_PARTS_BUBBLE = 15;
		int pos_x;
		int pos_y;
		int part_type;
	
};

#endif
