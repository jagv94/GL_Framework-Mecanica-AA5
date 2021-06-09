#pragma once
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <iostream>
#include "../Mesh.h"

class SphereClass
{
	glm::vec3 position = { 0.0f, 0.0f, 0.0f }; //Posicion inicial de la esfera
	glm::vec3 velocity = { 0.0f, 0.0f, 0.0f }; //Velocidad inicial de la esfera
	glm::vec3 force = { 0.0f, 0.0f, 0.0f };	//Fuerza inicial de la esfera
	glm::vec3 gravity = { 0.0f, -9.81f, 0.0f }; //Gravedad

	float mass = 1.f; //Masa de la esfera

	float radius = 1.0f; //Radio de la esfera

	/// <summary>
	/// Calcular la posicion de los puntos de la maya
	/// </summary>
	/// <param name="row">Particulas de la maya de las olas en horizontal</param>
	/// <param name="width">Anchura de la maya</param>
	/// <param name="col">Particulas de la maya de las olas en vertical</param>
	/// <returns>Posicion de un punto concreto de la maya</returns>
	int get_indexz(int _row, int _width, int _col);

public:
	SphereClass(glm::vec3 _position, float _mass, float _radius);

	/// <summary>
	/// Solver para el movimiento de la esfera
	/// </summary>
	/// <param name="_forceBuorancy">Resultado del calculo de la fuerza de flotabilidad</param>
	/// <param name="_dt">Delta time</param>
	void SolverEuler(glm::vec3 _forceBuorancy, float _dt);

	/// <summary>
	/// Calcular flotabilidad de la esfera
	/// </summary>
	/// <param name="_wave">Maya de la ola en uso</param>
	/// <param name="_densityFluid">Densidad del fluido</param>
	/// <param name="_gravity">Gravedad en uso</param>
	/// <returns></returns>
	glm::vec3 CalculateBuoyancy(Mesh _wave, float _densityFluid, float _gravity);
	
	glm::vec3 GetPosition() { return position; }
	float GetMass() { return mass; }
	float GetRadius() { return radius; }
};

