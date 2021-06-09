#pragma once
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <iostream>

struct Wave
{
	glm::vec3 waveDirection;
	float amplitude;
	float distBetweenWaves;
	float velocity;
};


class WaveSystem
{
	glm::vec3* initialPositions;
	Wave myWaves[2];
	int width = 0;
	int height = 0;

	int get_indexz(int row, int col);

public:
	WaveSystem(glm::vec3* initPos, int _width, int _height, Wave newWaves[]);
	void CalculateWave(glm::vec3* positions, glm::vec3 waveDirection, float distBetweenWaves, float amplitude, float velocity, float _dt);
	void CalculateForce(float densityFluid, float gravity, float volume, float dragCoeficient);
	glm::vec3 GetXZPositions(glm::vec3 initialPos, glm::vec3 waveDirection, float amplitude, float distBetweenWaves, float velocity, float _dt);
	float GetYPositions(glm::vec3 initialPos, glm::vec3 waveDirection, float amplitude, float distBetweenWaves, float velocity, float _dt);
	int GetWidth();
	int GetHeight();
};

