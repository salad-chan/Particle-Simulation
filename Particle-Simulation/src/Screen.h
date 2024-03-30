#pragma once
#include "SDL.h"
#include <iostream>

namespace MyParticleSimulation {

	class Screen {
	public:
		Screen();
		bool init();
		void update();
		void setPixelColor(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		bool processEvent();
		void shutdown();
	
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		Uint32* buffer;
		SDL_Event event;
	};
}
