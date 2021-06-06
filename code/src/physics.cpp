#include <../Mesh.h>
#include <imgui\imgui.h>
#include <imgui\imgui_impl_sdl_gl3.h>
#include "../WaveSystem.h"
#include "../Sphere.h"

namespace LilSpheres {
	extern const int maxParticles;
	extern int firstParticleIdx;
	extern int particleCount;
	extern void updateParticles(int startIdx, int count, float* array_data);
}
extern bool renderParticles;

namespace Sphere {
	extern float radius;
	extern void updateSphere(glm::vec3 pos, float radius);
}
extern bool renderSphere;

bool show_test_window = false;
void GUI() {
	bool show = true;
	ImGui::Begin("Physics Parameters", &show, 0);

	{	
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);//FrameRate
	}
	
	ImGui::End();
}

double time;

Mesh mesh;
WaveSystem* wave;
SphereClass* mySphere;

void PhysicsInit() {
	renderParticles = false; //Desactivar para la entrega o añadir al GUI desactivado por defecto
	renderSphere = true;
	renderCloth = true;

	Wave myWaves[2] = { glm::vec3(1, 0, 0), 1.0f, 0.5f, 2.0f, glm::vec3(0, 0, 1), 1.0f, 0.5f, 2.0f };

	mesh = Mesh(ClothMesh::numCols, ClothMesh::numRows);
	wave = new WaveSystem(mesh.positions, ClothMesh::numCols, ClothMesh::numRows, myWaves);
	mySphere = new SphereClass(glm::vec3(0.0f, 8.0f, 0.0f), 50.0f, 1.0f);
	LilSpheres::particleCount = mesh.currentParticles;

	time = 0.0f;

}

void PhysicsUpdate(float dt) {

	time += dt;

	wave->CalculateWave(mesh.positions, glm::vec3(1, 0, 0), 1.0f, 0.5f, 2.0f, time);

	mySphere->SolverEuler(mySphere->CalculateBuoyancy(mesh, 0.997f, -9.81f), dt);

	ClothMesh::updateClothMesh(&(mesh.positions[0].x));
	LilSpheres::updateParticles(0, LilSpheres::particleCount, &(mesh.positions[0].x));
	Sphere::updateSphere(mySphere->GetPosition(), 1);
}

void PhysicsCleanup() {
}