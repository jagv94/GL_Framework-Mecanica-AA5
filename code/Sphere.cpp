#include "Sphere.h"

int SphereClass::get_indexz(int _row, int _width, int _col)
{
	return _row * _width + _col;
}

SphereClass::SphereClass(glm::vec3 _position, float _radius) : position(_position), radius(_radius) {}

void SphereClass::SolverEuler(glm::vec3 _forceBuorancy, float _dt)
{
	force = gravity + _forceBuorancy;

	position = position + velocity * _dt;
	velocity = velocity + (force / mass) * _dt;

}

glm::vec3 SphereClass::CalculateBuoyancy(Mesh _wave, float _densityFluid, float _gravity)
{
	for (int i = 0; i < _wave.height; i++)
	{
		for (int j = 0; j < _wave.width; j++)
		{
			glm::vec3 wavePoints = _wave.positions[get_indexz(i, _wave.width, j)]; //Posicion de los puntos de la maya de la ola

			//Calculamos la colision con la parte sumergida de la esfera con los puntos de la maya de la ola
			if (position.y - radius < wavePoints.y &&
				position.x - radius < wavePoints.x &&
				position.x + radius > wavePoints.x &&
				position.z - radius < wavePoints.z &&
				position.z + radius > wavePoints.z)
			{
				float h = glm::length((position.y - radius) - _wave.positions[get_indexz(i, _wave.width, j)].y); //Altura sumergida de la esfera
				float volume = (glm::pi<float>() * glm::pow(h, 2) / 3.0f) * ((3.0f * radius) - (h)); //Volumen sumergido de la esfera

				return (_densityFluid * _gravity * volume * glm::vec3(0.0f, 1.0f, 0.0f)); //Devolvemos la flotabilidad de la esfera
			}
		}
	}

	return glm::vec3(0.0f, 0.0f, 0.0f);
}
