#pragma once
#include <vector>

// GL Includes
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
namespace Camera_Direction {
	enum Camera_Direction {
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
}
class Camera2D
{
public:
	Camera2D(glm::vec3 position);
	void ProcessInput(Camera_Direction::Camera_Direction direction, GLdouble deltaTime);
	glm::mat4 GetViewMatrix();
	glm::vec3 m_Position;

	~Camera2D();
private:
	void CalculateVectors();
private:
	float m_pMovementSpeed;
	glm::vec3 m_pFront;
	glm::vec3 m_pRight;
	glm::vec3 m_pUp;
	glm::vec3 m_pWorldUp;
	
};

