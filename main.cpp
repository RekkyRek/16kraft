#include <stdio.h>
#include <iostream>
#include <string>

#include "./engine/renderer.hpp"
#include "./engine/world.hpp"
#include "./game/game.hpp"

Renderer renderer;
Game game;
World world;

void display () {
	renderer.Display();
	renderer.Transform(game.player.pos, game.player.rot);
	game.Move(renderer);
	game.Draw(renderer);
	if(game.controls.keyF3) { game.DrawDebug(renderer); }
	if(game.controls.keyF4) { game.DrawLog(renderer); }
	renderer.Flush();
}

void update() {
	glutPostRedisplay();
}

void mouse(int x, int y) { game.controls.mouse(x, y); }
void keyboard(unsigned char key, int x, int y) { game.controls.keyboard(std::tolower(key), x, y); }
void keyboardUp(unsigned char key, int x, int y) { game.controls.keyboardUp(std::tolower(key), x, y); }
void specialKeys(int key, int x, int y) { game.controls.specialKeys(key, x, y); }
void specialKeysUp(int key, int x, int y) { game.controls.specialKeysUp(key, x, y); }

int main(int argc, char* argv[]) {
	game.Log("Initializing GameManager");
	game.Init();

	game.Log("Initializing Renderer");
	glutInit(&argc,argv);
	renderer.InitWindow("16kraft", 800, 600);

	glutDisplayFunc(display);

	game.Log("Setting up event hooks");
	glutPassiveMotionFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);

	glutKeyboardUpFunc(keyboardUp);
	glutSpecialUpFunc(specialKeysUp);
	game.Log("Done.");

  	glutIdleFunc(update);
  	glutMainLoop();
	return 0;
}
