#include "particleEmitter.h"

ParticleEmitter::ParticleEmitter(){
	
	
}
	
void ParticleEmitter::pe_init(const char* graphic, SDL_Renderer* ren, int start_x, int start_y, int width, int height, int type){
	
	srand(500);
	part_type = type;
	int max_parts = MAX_PARTS;
	image = graphic;
	my_renderer = ren;
	x = start_x;
	y = start_y;
	w = width;
	h = height;
	t = type;
	
	if(part_type == PART_TYPE_RAIN){
		max_parts = MAX_PARTS_RAIN;
		
		for(int i = 0; i < max_parts; i++){
				
				
				particles[i].obj_init(graphic, ren, start_x, start_y, width, height);
				//spread out each rain particle by 40
				particles[i].obj_set_x_pos(i*40);
				//spawn the rain under the clouds
				particles[i].obj_set_y_pos(16);
				particles[i].obj_set_x_vel(1.0);
				particles[i].obj_set_y_vel(1.0);
				//make the rain despawn at random (in a range)
				particles[i].obj_set_lifetime(350-(rand() % 249));
			
		}	
			
	}
	
}

void ParticleEmitter::pe_update(){
	
	int max_parts = MAX_PARTS;
	
	if(part_type == 0){
		max_parts = MAX_PARTS_RAIN;
		
		for(int i = 0; i < max_parts; i++){
			
			particles[i].obj_update();
			
			//when the rain despawns respawn it at og location
			if(particles[i].obj_get_lifetime() == 0){
				
				particles[i].obj_set_x_pos(i*40);
				particles[i].obj_set_y_pos(16);
				particles[i].obj_set_x_vel(1.0);
				particles[i].obj_set_y_vel(1.0);
				particles[i].obj_set_lifetime(350-(rand() % 249));
				
			}
		
		}	
		
	}	
	
}

void ParticleEmitter::pe_render(SDL_Renderer* ren){
	
	int max_parts = MAX_PARTS;
	
	if(part_type == PART_TYPE_RAIN){
		max_parts = MAX_PARTS_RAIN;
		
		for(int i = 0; i < max_parts; i++){
		
				particles[i].obj_render(ren);
			
		}
		
	}
	
}

void ParticleEmitter::pe_quit(){
	
	int max_parts = MAX_PARTS;
	
	if(part_type == PART_TYPE_RAIN){
		
		max_parts = MAX_PARTS_RAIN;
		
	}
	
	for(int i = 0; i < max_parts; i++){
		
			particles[i].obj_quit();
		
	}
	
}
