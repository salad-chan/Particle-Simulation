#include "Particle.h"
#include <stdlib.h>

namespace MyParticleSimulation {
	
	MyParticleSimulation::Particle::Particle() {
		x = 2.0 * rand() / RAND_MAX - 1;
		y = 2.0 * rand() / RAND_MAX - 1;
	}
}