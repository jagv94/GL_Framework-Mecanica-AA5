#include "WaveSystem.h"
#include <iostream>

void WaveSystem::CalculateWave(glm::vec3* positions, glm::vec3 waveDirection, float distBetweenWaves, float amplitude, float velocity, float _dt)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//positions[get_indexz(i, j)] = positions[get_indexz(i, j)] - (waveDirection / (2 * glm::pi<float>() / distBetweenWaves)) * amplitude * glm::sin(glm::dot(waveDirection, positions[get_indexz(i, j)]) - velocity * _dt);
			//positions[get_indexz(i, j)].y = amplitude * glm::cos(glm::dot(waveDirection, positions[get_indexz(i, j)]) - velocity * _dt);

			positions[get_indexz(i, j)] = initialPositions[get_indexz(i, j)] - (waveDirection / (2 * glm::pi<float>() / distBetweenWaves)) * amplitude * glm::sin(glm::dot(waveDirection, initialPositions[get_indexz(i, j)]) - velocity * _dt);
			positions[get_indexz(i, j)].y = amplitude * glm::cos(glm::dot(waveDirection, initialPositions[get_indexz(i, j)]) - velocity * _dt);
		}
	}
	/*glm::vec3 result = (waveDirection / (2 * glm::pi<float>() / distBetweenWaves) * amplitude);
	std::cout << result.x << " " << result.y << " " << result.z << std::endl;*/

}

void WaveSystem::CalculateForce(float densityFluid, float gravity, float volume, float dragCoeficient)
{
	glm::vec3 buoyancyForce = (densityFluid * gravity * volume) * glm::vec3(0.0f, 1.0f, 0.0f); //añadir coeficiente?¿

	//glm::vec3 dragForces = -(1.0f/2.0f) * densityFluid * dragCoeficient * 

}
