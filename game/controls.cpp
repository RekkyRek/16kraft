#include "controls.hpp"

void Controls::mouse(int x, int y) {
	static auto const BOUND = 89.9999;
	mousePos = glm::vec2((float)x, (float)y);

	change = lastMousePosition - mousePos;

	if((int)change.x > -25 && (int)change.x < 25) {
		rot.y += change.x * sensitivity;
		rot.x += -change.y * sensitivity;

		if      (rot.x >  BOUND) rot.x =  BOUND;
		else if (rot.x < -BOUND) rot.x = -BOUND;

		if      (rot.y >  360)   rot.y = 0;
		else if (rot.y < 0)      rot.y = 360;
	}

	lastMousePosition = mousePos;
}

void Controls::keyboard(unsigned char key, int x, int y) {
  if(key == 'w') {keyW = true;}
  if(key == 's') {keyS = true;}
  if(key == 'a') {keyA = true;}
  if(key == 'd') {keyD = true;}
  if(key == 32)  {keySpace = true;}
}
void Controls::keyboardUp(unsigned char key, int x, int y) {
  if(key == 'w') {keyW = false;}
  if(key == 's') {keyS = false;}
  if(key == 'a') {keyA = false;}
  if(key == 'd') {keyD = false;}
  if(key == 32)  {keySpace = false;}
}
void Controls::specialKeys( int key, int x, int y ) {
  if(key == 3) {keyF3 = true;}
  if(key == 4) {keyF4 = true;}
  if(key == 112) {keyShift = true;}
}
void Controls::specialKeysUp( int key, int x, int y ) {
  if(key == 3) {keyF3 = false;}
  if(key == 4) {keyF4 = false;}
  if(key == 112) {keyShift = false;}
}