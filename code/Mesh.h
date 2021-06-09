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

	int get_indexz(int row, int col);

public:
	int width;
	int height;
	glm::vec3* forces = nullptr;

	Mesh();
	Mesh(int width, int height);
};

