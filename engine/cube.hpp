#ifndef _CUBE_H
#define _CUBE_H

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

class Cube {
	public:
		void Draw(float x, float y, float z, glm::vec3 color);
		void DrawTopFace(float x, float y, float z, glm::vec3 color);
		void DrawBottomFace(float x, float y, float z, glm::vec3 color);
		void DrawLeftFace(float x, float y, float z, glm::vec3 color);
		void DrawRightFace(float x, float y, float z, glm::vec3 color);
		void DrawFrontFace(float x, float y, float z, glm::vec3 color);
		void DrawBackFace(float x, float y, float z, glm::vec3 color);
};

#endif