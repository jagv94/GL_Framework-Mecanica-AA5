#pragma once
#include "particleSystem.h"
#include <vector>

namespace ClothMesh
{
	extern void updateClothMesh(float* array_data);
	extern const int numRows;
	extern const int numCols;
}
extern bool renderCloth;

class Mesh : public ParticleSystem
{
private:
	int size;
	glm::vec3 posMalla = glm::vec3(-7.5f, 0.0f, -6.5f);

	int get_indexz(int row, int col)
	{
		return row * width + col;
	}

public:
	int width;
	int height;
	glm::vec3* forces = nullptr;

	Mesh() : Mesh(ClothMesh::numCols, ClothMesh::numRows) {};
	Mesh(int width, int height) : width(width), height(height), ParticleSystem(width* height), size(width* height)
	{
		float z = 0.0f;

		currentParticles = size;

		forces = new glm::vec3[size];
		positions = new glm::vec3[size];
		position_before = new glm::vec3[size];
		velocity = new glm::vec3[size];

		//Inicializar posicion de cada punto de la malla
		for (int row = 0; row < height; row++)
		{
			for (int col = 0; col < width; col++)
			{
				positions[get_indexz(row, col)] = glm::vec3(row + posMalla.x, posMalla.y, col + posMalla.z);
				position_before[get_indexz(row, col)] = glm::vec3(row + posMalla.x, posMalla.y, col + posMalla.z);
				velocity[get_indexz(row, col)] = glm::vec3(0.0f, 0.0f, 0.0f);
			}
		}
	}
};

