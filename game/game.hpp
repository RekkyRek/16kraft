#ifndef _G_H
#define _G_H

#include "../engine/renderer.hpp"

#include <string>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "controls.hpp"

struct Entity {
	glm::vec3 pos;
	glm::vec3 vel;
	glm::vec3 fwd;
	glm::vec3 right;
	glm::vec2 rot;
	float speed;
};

class Game {
	public:
		Entity player;
		Controls controls;
		std::string logHistory [6];
		void Init();
		void Move(Renderer renderer);
		void Draw(Renderer renderer);
		void DrawDebug(Renderer renderer);
		void DrawLog(Renderer renderer);
		void Log(std::string);
};

#endif