#pragma once
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <iostream>

struct Wave
{
	glm::vec3 waveDirection; //Direccion de las olas
	float amplitude; //Amplitud de las olas
	float distBetweenWaves; //Distancia entre olas
	float velocity; //Velocidad de las olas
};


class WaveSystem
{
	glm::vec3* initialPositions; //Posiciones iniciales
	Wave myWaves[2]; //Olas en simulacion
	int width = 0;
	int height = 0;

	int get_indexz(int row, int col);

public:
	WaveSystem(glm::vec3* _initPos, int _width, int _height, Wave newWaves[]);

	/// <summary>
	/// Actualiza las posiciones de los puntos de la maya
	/// </summary>
	/// <param name="_positions">Posiciones de los puntos de la maya</param>
	/// <param name="_dt">Delta time</param>
	void CalculateWave(glm::vec3* _positions, float _dt);

	/// <summary>
	/// Calcula las posiciones de los puntos de la maya para hacer una ola
	/// </summary>
	/// <param name="_initialPos">Posicion inicial</param>
	/// <param name="_waveDirection">Direccion de la ola</param>
	/// <param name="_amplitude">Amplitud de la ola</param>
	/// <param name="_distBetweenWaves">Distancia entre olas</param>
	/// <param name="_velocity">Velocidad de la ola</param>
	/// <param name="_dt">Delta time</param>
	/// <returns></returns>
	glm::vec3 GetXZPositions(glm::vec3 _initialPos, glm::vec3 _waveDirection, float _amplitude, float _distBetweenWaves, float _velocity, float _dt);

	/// <summary>
	/// Recalcula las posiciones en Y de los puntos de la maya para ajustar la altura de la ola
	/// </summary>
	/// <param name="_initialPos">Posicion inicial</param>
	/// <param name="_waveDirection">Direccion de la ola</param>
	/// <param name="_amplitude">Amplitud de la ola</param>
	/// <param name="_velocity">Velocidad de la ola</param>
	/// <param name="_dt">Delta time</param>
	/// <returns></returns>
	float GetYPositions(glm::vec3 _initialPos, glm::vec3 _waveDirection, float _amplitude, float _velocity, float _dt);
	int GetWidth();
	int GetHeight();
};

