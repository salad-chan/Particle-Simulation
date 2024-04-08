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
		// Unoptimized box blur algorithm
		void boxBlur();
	
	public:
		const static int SCREEN_WIDTH = 1280;
		const static int SCREEN_HEIGHT = 720;
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		Uint32* buffer;
		Uint32* buffer2;
		SDL_Event event;
	};
}
