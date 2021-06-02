#pragma once
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>

class WaveSystem
{


	void CalculateWave(glm::vec3 positions, glm::vec3 waveDirection, float distBetweenWaves, float amplitude, float velocity, float _dt);

};

