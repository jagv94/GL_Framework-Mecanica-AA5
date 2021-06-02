#include "WaveSystem.h"

void WaveSystem::CalculateWave(glm::vec3 positions, glm::vec3 waveDirection, float distBetweenWaves, float amplitude, float velocity, float _dt)
{
	positions = positions - (waveDirection / (2 * glm::pi<float>() / distBetweenWaves)) * amplitude * glm::sin(glm::dot(waveDirection, positions) - velocity * _dt);
	positions.y = amplitude * glm::cos(glm::dot(waveDirection, positions) - velocity * _dt);
}
