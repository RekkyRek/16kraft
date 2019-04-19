#ifndef _R_H
#define _R_H

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "cube.hpp"

class Renderer {
	public:
		int width, height;
		glm::vec3 transform;
		void Display();
		void Transform(glm::vec3 pos, glm::vec2 rot);
		void Flush();
		void InitWindow(char* name, int w, int h);
		void DrawText(const char* text, int length, int x, int y);
		void DrawTopFace(float x, float y, float z, glm::vec3 color);
		Cube cube;
};

#endif