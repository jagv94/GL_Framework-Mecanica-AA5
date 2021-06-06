#pragma once
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>

class WaveSystem
{
	glm::vec3* initialPositions;

	int width = 0;
	int height = 0;

	int get_indexz(int row, int col)
	{
		return row * width + col;
	}

public:
	WaveSystem(glm::vec3* initPos, int _width, int _height) : width(_width), height(_height)
	{
		int size = width * height;
		initialPositions = new glm::vec3[size];

		for (int row = 0; row < height; row++)
		{
			for (int col = 0; col < width; col++)
			{
				initialPositions[get_indexz(row, col)] = initPos[get_indexz(row, col)];
			}
		}
	}
	void CalculateWave(glm::vec3* positions, glm::vec3 waveDirection, float distBetweenWaves, float amplitude, float velocity, float _dt);

	void CalculateForce(float densityFluid, float gravity, float volume, float dragCoeficient);

};

