#pragma once

namespace MyParticleSimulation {
	
	struct Particle {
	public:
		Particle();
		void update(int interval);
	
	private:
		void init();

	public:
		double x, y;

	private:
		double speed;
		double direction;
	};
}