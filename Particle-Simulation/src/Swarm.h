#pragma once

#include "Particle.h"

namespace MyParticleSimulation {
	
	class Swarm {
	public:
		Swarm(int n_particles);
		~Swarm();
		const Particle* const getParticles() { return Particles; };
	
	private:
		Particle* Particles;
	};
}