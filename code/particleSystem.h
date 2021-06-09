#pragma once
#include <glm\glm.hpp>

class ParticleSystem
{
public:
    glm::vec3* positions;
    glm::vec3* velocity;
    glm::vec3* position_before;

    int currentParticles;
    int maxParticles;
    float* age;

    ParticleSystem(int _numParticles = 100);
    void UpdateParticle(int _idx, glm::vec3 _newPosition);
    void UpdateLilSpheres();
    void spawnParticle(glm::vec3 position);
    void updateAge(float _dt);
    void destroyOldParticles(float _maxAge);
};