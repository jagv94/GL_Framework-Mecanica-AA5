#include "WaveSystem.h"

int WaveSystem::get_indexz(int _row, int _col)
{
	return _row * width + _col;
}

WaveSystem::WaveSystem(glm::vec3* _initPos, int _width, int _height, Wave _newWaves[]) : width(_width), height(_height)
{
	int size = width * height;
	initialPositions = new glm::vec3[size];

	for (int i = 0; i < 2; i++)
	{
		myWaves[i] = _newWaves[i];
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			initialPositions[get_indexz(row, col)] = _initPos[get_indexz(row, col)];
		}
	}
}

void WaveSystem::CalculateWave(glm::vec3* _positions, float _dt)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			_positions[get_indexz(i, j)] = initialPositions[get_indexz(i, j)] - (GetXZPositions(initialPositions[get_indexz(i, j)], myWaves[0].waveDirection, myWaves[0].amplitude, myWaves[0].distBetweenWaves, myWaves[0].velocity, _dt) + GetXZPositions(initialPositions[get_indexz(i, j)], myWaves[1].waveDirection, myWaves[1].amplitude, myWaves[1].distBetweenWaves, myWaves[1].velocity, _dt)); //Se puede eliminar?
			_positions[get_indexz(i, j)].y = GetYPositions(initialPositions[get_indexz(i, j)], myWaves[0].waveDirection, myWaves[0].amplitude, myWaves[0].velocity, _dt) + GetYPositions(initialPositions[get_indexz(i, j)], myWaves[1].waveDirection, myWaves[1].amplitude, myWaves[1].velocity, _dt);
		}
	}
}

glm::vec3 WaveSystem::GetXZPositions(glm::vec3 _initialPos, glm::vec3 _waveDirection, float _amplitude, float _distBetweenWaves, float _velocity, float _dt)
{
	return glm::vec3((_waveDirection / (2 * glm::pi<float>() / _distBetweenWaves)) * _amplitude * glm::sin(glm::dot(_waveDirection, _initialPos) - _velocity * _dt));
}

float WaveSystem::GetYPositions(glm::vec3 _initialPos, glm::vec3 _waveDirection, float _amplitude, float _velocity, float _dt)
{
	return _amplitude * glm::cos(glm::dot(_waveDirection, _initialPos) - _velocity * _dt);
}

int WaveSystem::GetWidth()
{
	return width;
}

int WaveSystem::GetHeight()
{
	return height;
}
