#include "Sphere.h"
#include <iostream>

void SphereClass::SolverEuler(glm::vec3 forceBuorancy, float _dt)
{

	force = gravity + forceBuorancy;

	position = position + velocity * _dt;
	velocity = velocity + (force / mass) * _dt;

}

glm::vec3 SphereClass::CalculateBuoyancy(Mesh wave, float densityFluid, float _gravity)
{
	for (int i = 0; i < wave.height; i++)
	{
		for (int j = 0; j < wave.width; j++)
		{
			if (position.y - radius < wave.positions[get_indexz(i, wave.width, j)].y &&
				position.x - radius < wave.positions[get_indexz(i, wave.width, j)].x && position.x + radius > wave.positions[get_indexz(i, wave.width, j)].x &&
				position.z - radius < wave.positions[get_indexz(i, wave.width, j)].z && position.z + radius > wave.positions[get_indexz(i, wave.width, j)].z)
			{
				float volume = (glm::pi<float>() * glm::pow(glm::length((position.y - radius) - wave.positions[get_indexz(i, wave.width, j)].y), 2) / 3) * (3 * radius - (glm::length((position.y - radius) - wave.positions[get_indexz(i, wave.width, j)].y)));

				//std::cout << volume << std::endl;

				return (densityFluid * _gravity * volume * glm::vec3(0.0f, 1.0f, 0.0f));
			}
		}
	}


	return glm::vec3(0.0f, 0.0f, 0.0f);
}
