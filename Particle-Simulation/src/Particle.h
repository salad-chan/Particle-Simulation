#pragma once

namespace MyParticleSimulation {
	
	class Particle {
	public:
		Particle();
		void update();

	public:
		double x, y;
		double speed;
		double x_speed;
		double y_speed;
	};
}