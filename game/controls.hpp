#ifndef _CTRL_H
#define _CTRL_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

class Controls {
	public:
		bool keyW, keyA, keyS, keyD, keySpace, keyShift, keyF3, keyF4;
		float sensitivity = 0.5;
		glm::vec3 pos;
		glm::vec3 lastPosition;
		glm::vec2 rot;
		glm::vec2 mousePos;
		glm::vec2 lastMousePosition;
		glm::vec2 change;

		void mouse(int x, int y);
		void keyboard(unsigned char key, int x, int y);
		void keyboardUp(unsigned char key, int x, int y);
		void specialKeys(int key, int x, int y);
		void specialKeysUp(int key, int x, int y);
};

#endif