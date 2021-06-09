#include "particleSystem.h"

namespace LilSpheres {
    extern const int maxParticles;
    extern int firstParticleIdx;
    extern int particleCount;
    extern void updateParticles(int startIdx, int count, float* array_data);
}

ParticleSystem::ParticleSystem(int _numParticles)
{
    positions = new glm::vec3[_numParticles];
}