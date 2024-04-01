#include "Swarm.h"

namespace MyParticleSimulation {
	
	MyParticleSimulation::Swarm::Swarm(int n_particles) {
		Particles = new Particle[n_particles];
	}

	MyParticleSimulation::Swarm::~Swarm() {
		delete[] Particles;
	}
}