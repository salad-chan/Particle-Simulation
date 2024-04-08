#pragma once

namespace MyParticleSimulation {
	
	class Particle {
	public:
		Particle();
		void update(int interval);

	public:
		double x, y;
		double speed;
		double direction;
	};
}