#ifndef _TEXA_H
#define _TEXA_H

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

struct Texture {
	GLuint *data;
	int id;
	int width;
	int height;
};

class TextureAtlas {
	public:
		Texture textures[16];
		void Load(char* path, int id);
};

#endif