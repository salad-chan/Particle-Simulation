#include "Screen.h"

namespace MyParticleSimulation {
	Screen::Screen() : 
		window(nullptr), renderer(nullptr), texture(nullptr), buffer(nullptr), buffer2(nullptr) {
		
	}

	bool Screen::init() {
		// Initialization of SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cout << "SDL initialization failed" << std::endl;
			return false;
		}

		// Window Creation
		window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		// Window Check
		if (window == nullptr) {
			SDL_Quit();
			return false;
		}

		// Creation of SLD renderer, last argument prevents screen tearing
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (renderer == nullptr) {
			std::cout << "Renderer could not be creater." << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}

		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (texture == nullptr) {
			std::cout << "Texture could not be creater." << std::endl;
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}

		buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		
		buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		
		memset(buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

	void Screen::update() {
		SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, nullptr, nullptr);
		SDL_RenderPresent(renderer);
	}

	void Screen::setPixelColor(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
			return;
		
		Uint32 color = 0;

		// Channel order is alpha, blue, green, red
		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xff;

		buffer[(y * SCREEN_WIDTH) + x] = color;
	}

	void Screen::boxBlur() {
		Uint32* temp = buffer;
		buffer = buffer2;
		buffer2 = temp;

		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {

				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;

				for (int row = -1; row <= 1; row++) {
					for (int col = -1; col <= 1; col++) {
						int currentX = x + col;
						int currentY = y + col;

						if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
							Uint32 color = buffer2[currentY * SCREEN_WIDTH + currentX];

							Uint8 red = color >> 24;
							Uint8 green = color >> 16;
							Uint8 blue = color >> 8;

							redTotal += red;
							greenTotal += green;
							blueTotal += blue;
						}
					}
				}

				Uint8 red = redTotal / 9;
				Uint8 green = greenTotal / 9;
				Uint8 blue = blueTotal / 9;

				setPixelColor(x, y, red, green, blue);
			}
		}
	}

	bool Screen::processEvent() {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}
	
	void Screen::shutdown() {
		// Free memory
		delete[] buffer;
		delete[] buffer2;

		// Cleanup after SDL
		SDL_DestroyTexture(texture);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}