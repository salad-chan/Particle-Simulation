#include "Swarm.h"

namespace MyParticleSimulation {
	
	Swarm::Swarm() : lastTime(0) {
		Particles = new Particle[N_PARTICLES];
	}

	Swarm::~Swarm() {
		delete[] Particles;
	}

	void Swarm::update(int elapsed) {
		int interval = elapsed - lastTime;
		
		for (int i = 0; i < N_PARTICLES; i++) {
			Particles[i].update(interval);
		}

		lastTime = elapsed;
	}
}