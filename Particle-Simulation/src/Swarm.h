#pragma once

#include "Particle.h"

namespace MyParticleSimulation {
	
	class Swarm {
	public:
		Swarm();
		~Swarm();
		const Particle* const getParticles() { return Particles; };
		void update();
	
	public:
		const static int N_PARTICLES = 1000;

	private:
		Particle* Particles;
	};
}