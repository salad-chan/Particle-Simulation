#include "Screen.h"

int main(int argc, char* argv[]) {
	
	MyParticleSimulation::Screen screen;

	if (!screen.init()) {
		std::cout << "Error in SDL initialization" << std::endl;
	}

	// Main loop
	while (true) {
		
		for (int i = 0; i < MyParticleSimulation::Screen::SCREEN_HEIGHT; i++) {
			for (int j = 0; j < MyParticleSimulation::Screen::SCREEN_WIDTH; j++) {
				screen.setPixelColor(j, i, 0x00, 0xff, 0x00);
			}
		}
		
		screen.update();
		
		if (screen.processEvent() == false) {
			break;
		}
	}

	screen.shutdown();

	return 0;
}