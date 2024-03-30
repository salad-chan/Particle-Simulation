#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[]) {
	
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialization failed" << std::endl;
		return 1;
	}

	// Window Creation
	SDL_Window* window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// Window Check
	if (window == nullptr) {
		SDL_Quit();
		return 2;
	}

	// Creation of SLD renderer, last argument prevents screen tearing
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << "Renderer could not be creater." << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (texture == nullptr) {
		std::cout << "Texture could not be creater." << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	memset(buffer, 0xff, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	bool exit_program = false;
	SDL_Event event;

	SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);

	// Main loop
	while (!exit_program) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit_program = true;
			}
		}
	}

	delete[] buffer;

	// Cleanup after SDL
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}