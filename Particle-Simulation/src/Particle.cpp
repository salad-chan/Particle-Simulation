#include "Particle.h"
#include <stdlib.h>
#include <math.h>
#include <numbers>

namespace MyParticleSimulation {
	
	Particle::Particle() : x(0), y(0) {
		init();
	}

	void Particle::init() {
		x = 0;
		y = 0;

		direction = (2 * std::numbers::pi * rand()) / RAND_MAX;
		speed = (0.05 * rand()) / RAND_MAX;
		speed *= speed;
	}

	void Particle::update(int interval) {
		direction += interval * 0.0005;

		double x_speed = speed * cos(direction);
		double y_speed = speed * sin(direction);

		x += x_speed * interval;
		y += y_speed * interval;

		if (x < -1 || x > 1 || y < -1 || y > 1) 
			init();

		if (rand() < RAND_MAX / 100)
			init();
	}
}