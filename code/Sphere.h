#pragma once
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "../Mesh.h"

class SphereClass
{
	glm::vec3 position = { 0.0f, 0.0f, 0.0f };;
	glm::vec3 velocity = { 0.0f, 0.0f, 0.0f };;
	glm::vec3 force = { 0.0f, 0.0f, 0.0f };
	glm::vec3 gravity = {0.0f, -9.81f, 0.0f};

	float mass;

	float radius = 1.0f;

	int get_indexz(int row, int width, int col)
	{
		return row * width + col;
	}

public:
	SphereClass(glm::vec3 _position, float _mass, float _radius) : position(_position), mass(_mass), radius(_radius){}

	void SolverEuler(glm::vec3 forceBuorancy, float _dt);
	glm::vec3 GetPosition() { return position; }
	float GetMass() { return mass; }
	glm::vec3 CalculateBuoyancy(Mesh wave, float densityFluid, float gravity);
	float GetRadius() { return radius; }
};

