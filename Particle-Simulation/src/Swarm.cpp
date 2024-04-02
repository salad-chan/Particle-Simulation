#include "Swarm.h"

namespace MyParticleSimulation {
	
	Swarm::Swarm() {
		Particles = new Particle[N_PARTICLES];
	}

	Swarm::~Swarm() {
		delete[] Particles;
	}

	void Swarm::update() {
		for (int i = 0; i < N_PARTICLES; i++) {
			Particles[i].update();
		}
	}
}