#pragma once

#include "Particle.h"

namespace MyParticleSimulation {
	
	class Swarm {
	public:
		Swarm();
		~Swarm();
		const Particle* const getParticles() { return Particles; };
		void update(int elapsed);
	
	public:
		const static int N_PARTICLES = 5000;

	private:
		Particle* Particles;
		int lastTime;
	};
}