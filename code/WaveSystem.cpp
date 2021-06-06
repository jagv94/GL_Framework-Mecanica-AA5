#include "WaveSystem.h"
#include <iostream>

void WaveSystem::CalculateWave(glm::vec3* positions, glm::vec3 waveDirection, float distBetweenWaves, float amplitude, float velocity, float _dt)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			positions[get_indexz(i, j)] = initialPositions[get_indexz(i, j)] - (GetXZPositions(initialPositions[get_indexz(i, j)], myWaves[0].waveDirection, myWaves[0].amplitude, myWaves[0].distBetweenWaves, myWaves[0].velocity, _dt) + GetXZPositions(initialPositions[get_indexz(i, j)], myWaves[1].waveDirection, myWaves[1].amplitude, myWaves[1].distBetweenWaves, myWaves[1].velocity, _dt));
			positions[get_indexz(i, j)].y = GetYPositions(initialPositions[get_indexz(i, j)], myWaves[0].waveDirection, myWaves[0].amplitude, myWaves[0].distBetweenWaves, myWaves[0].velocity, _dt) + GetYPositions(initialPositions[get_indexz(i, j)], myWaves[1].waveDirection, myWaves[1].amplitude, myWaves[1].distBetweenWaves, myWaves[1].velocity, _dt);
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

glm::vec3 WaveSystem::GetXZPositions(glm::vec3 initialPos, glm::vec3 waveDirection, float amplitude, float distBetweenWaves, float velocity, float _dt)
{
	return glm::vec3((waveDirection / (2 * glm::pi<float>() / distBetweenWaves)) * amplitude * glm::sin(glm::dot(waveDirection, initialPos) - velocity * _dt));
}

float WaveSystem::GetYPositions(glm::vec3 initialPos, glm::vec3 waveDirection, float amplitude, float distBetweenWaves, float velocity, float _dt)
{
	return amplitude * glm::cos(glm::dot(waveDirection, initialPos) - velocity * _dt);
}
