// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// GLM
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Display.h"
#include "Application.h"


glm::mat3 GetNormalMatrix(glm::mat4 matrix) {
	return glm::mat3(glm::transpose(glm::inverse(matrix)));
}

int main()
{
	
	Display::init();

	Application app;
	app.runMainGameLoop();
	
	Display::close();

	return 0;
}
