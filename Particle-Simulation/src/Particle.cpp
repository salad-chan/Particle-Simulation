#include "Particle.h"
#include <stdlib.h>
#include <math.h>
#include <numbers>

namespace MyParticleSimulation {
	
	Particle::Particle() : x(0), y(0) {
		direction = (2 * std::numbers::pi * rand()) / RAND_MAX;
		speed = (0.0001 * rand()) / RAND_MAX;
	}

	void Particle::update(int interval) {
		double x_speed = speed * cos(direction);
		double y_speed = speed * sin(direction);

		x += x_speed * interval;
		y += y_speed * interval;
	}
}