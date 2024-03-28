#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[]) {
	
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialization failed" << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		SDL_Quit();
		return 2;
	}

	bool exit_program = false;
	SDL_Event event;

	while (!exit_program) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit_program = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}