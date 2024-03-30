#include <iostream>
#include "SDL.h"
#include "Screen.h"

int main(int argc, char* argv[]) {
	
	MyParticleSimulation::Screen screen;

	if (!screen.init()) {
		std::cout << "Error in SDL initialization" << std::endl;
	}

	// Main loop
	while (true) {
		
		//h

		if (screen.processEvent() == false) {
			break;
		}
	}

	screen.shutdown();

	return 0;
}