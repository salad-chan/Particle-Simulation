#include "Particle.h"
#include <stdlib.h>

namespace MyParticleSimulation {
	
	Particle::Particle() {
		x = 2.0 * rand() / RAND_MAX - 1;
		y = 2.0 * rand() / RAND_MAX - 1;

		speed = 0.005;

		x_speed = speed * (2.0 * rand() / RAND_MAX - 1);
		y_speed = speed * (2.0 * rand() / RAND_MAX - 1);
	}

	void Particle::update() {
		x += x_speed;
		y += y_speed;

		if (x <= -1.0 || x >= 1.0) {
			x_speed = -x_speed;
		}

		if (y <= -1.0 || y >= 1.0) {
			y_speed = -y_speed;
		}
	}
}