#include "Camera2D.h"
#include <iostream>
Camera2D::Camera2D(glm::vec3 position)
{
	this->m_Position = position;
	this->m_pFront = glm::vec3(0.0f, 0.0f, -1.0f);
	this->m_pWorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->m_pMovementSpeed = 128.0f;

	this->CalculateVectors();
}

void Camera2D::ProcessInput(Camera_Direction::Camera_Direction direction, GLdouble deltaTime)
{
	float velocity = this->m_pMovementSpeed * deltaTime;
	if (direction == Camera_Direction::Camera_Direction::LEFT)
		this->m_Position += this->m_pRight * velocity;
	if (direction == Camera_Direction::Camera_Direction::RIGHT)
		this->m_Position -= this->m_pRight * velocity;
	if (direction == Camera_Direction::Camera_Direction::UP)
		this->m_Position -= this->m_pUp * velocity;
	if (direction == Camera_Direction::Camera_Direction::DOWN)
		this->m_Position += this->m_pUp * velocity;

}

glm::mat4 Camera2D::GetViewMatrix()
{
	return glm::lookAt(this->m_Position, this->m_Position + this->m_pFront, this->m_pUp);
}


Camera2D::~Camera2D()
{
}

void Camera2D::CalculateVectors()
{
	this->m_pRight = glm::normalize(glm::cross(this->m_pFront, this->m_pWorldUp));
	this->m_pUp = glm::normalize(glm::cross(this->m_pRight, this->m_pFront));
}
