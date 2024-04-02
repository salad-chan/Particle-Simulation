#include "Screen.h"
#include <stdlib.h>
#include "Swarm.h"

int main(int argc, char* argv[]) {

	std::srand(time(nullptr));
	
	MyParticleSimulation::Screen screen;

	if (!screen.init()) {
		std::cout << "Error in SDL initialization" << std::endl;
	}

	MyParticleSimulation::Swarm swarm;

	const MyParticleSimulation::Particle* const pParticles = swarm.getParticles();

	// Main loop
	while (true) {

		int elapsed = SDL_GetTicks64();

		screen.clear();
		swarm.update();

		Uint8 red = (1 + sin(elapsed * 0.0005)) * 128;
		Uint8 green = (1 + sin(elapsed * 0.0002)) * 128;
		Uint8 blue = (1 + sin(elapsed * 0.0001)) * 128;

		for (int i = 0; i < MyParticleSimulation::Swarm::N_PARTICLES; i++) {
			MyParticleSimulation::Particle particle = pParticles[i];

			int x = (particle.x + 1) * (screen.SCREEN_WIDTH / 2);
			int y = (particle.y + 1) * (screen.SCREEN_HEIGHT / 2);

			screen.setPixelColor(x, y, red, green, blue);
		}

		screen.update();
		
		if (screen.processEvent() == false) {
			break;
		}
	}

	screen.shutdown();

	return 0;
}