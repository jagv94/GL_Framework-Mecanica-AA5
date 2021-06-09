#pragma once
#include <glm\glm.hpp>

class ParticleSystem
{
public:
    glm::vec3* positions; //Posiciones de las particulas
    glm::vec3* velocity; //Velocidad de las particulas
    glm::vec3* position_before; //Posicion anterior de las particulas

    ParticleSystem(int _numParticles = 100);
};