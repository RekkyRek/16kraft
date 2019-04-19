#include "renderer.hpp"
#include <iostream>

void Renderer::InitWindow(char* name, int w, int h) {
	width = w; height = h;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(w, h);
	glutCreateWindow(name);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();  
	
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90.0, (double)width / (double)height, 0.1, 2000.0);
}

void Renderer::Transform(glm::vec3 pos, glm::vec2 rot) {
	transform = pos;
	
	glRotatef( rot.x, 1.0, 0.0, 0.0 );
	glRotatef( rot.y, 0.0, -1.0, 0.0 );
	glRotatef( 0, 0.0, 0.0, 1.0 );

	glScalef(1.0f,1.0f,1.0f);
}

void Renderer::Flush() {
	glFlush();
	glutSwapBuffers();
}

void Renderer::DrawText(const char* text, int length, int x, int y){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, height, 0, width, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glColor3f( 1.0f,  1.0f,  1.0f );
	glRasterPos2i(x, y);
	for(int i=0; i<length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}

	glColor3f( 0.0f,  0.0f,  0.0f );
	glRasterPos2i(x+1, y-1);
	for(int i=0; i<length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}

	glMatrixMode(GL_PROJECTION);  
}

