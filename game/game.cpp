#include "./game.hpp"
#include <string>
#include <algorithm>

void Game::DrawDebug(Renderer renderer) {
	std::string campostext;
	campostext = "Position | X ";
	campostext += std::to_string(player.pos.x);
	campostext += " Y ";
	campostext += std::to_string(player.pos.y);
	campostext += " Z ";
	campostext += std::to_string(player.pos.z);

	renderer.DrawText(campostext.data(), campostext.size(), 2, 2);

	std::string camrottext;
	camrottext = "Rotation | X ";
	camrottext += std::to_string(player.rot.x);
	camrottext += " Y ";
	camrottext += std::to_string(player.rot.y);

	renderer.DrawText(camrottext.data(), camrottext.size(), 2, 22);

	std::string camvectext;
	camvectext = "Forwards | x ";
	camvectext += std::to_string(player.fwd.x);
	camvectext += " y ";
	camvectext += std::to_string(player.fwd.y);
	camvectext += " z ";
	camvectext += std::to_string(player.fwd.z);
	renderer.DrawText(camvectext.data(), camvectext.size(), 2, 42);
}

void Game::DrawLog(Renderer renderer) {
	for (int i = 0; i < 6; ++i) {
    	renderer.DrawText(logHistory[i].data(), logHistory[i].size(), 2, renderer.height - (20 * i) + 2);
  	}
}

void Game::Log(std::string str) {
	time_t  timev;
	str = "[" + std::to_string(time(&timev)) + "] " + str;

	logHistory[5] = logHistory[4];
	logHistory[4] = logHistory[3];
	logHistory[3] = logHistory[2];
	logHistory[2] = logHistory[1];
	logHistory[1] = logHistory[0];
	logHistory[0] = str;
}

void Game::Move(Renderer renderer) {
  	player.fwd = glm::vec3(glm::sin(glm::radians(controls.rot.y)), 0.0f, glm::cos(glm::radians(controls.rot.y)));
  	player.right = glm::vec3(glm::sin(glm::radians(controls.rot.y - 90)), 0.0f, glm::cos(glm::radians(controls.rot.y - 90)));

	if(controls.keyW) {
		player.vel.x += player.fwd.x * player.speed;
		player.vel.z += player.fwd.z * player.speed;
	}
	if(controls.keyA) {
		player.vel.x -= player.right.x * player.speed;
		player.vel.z -= player.right.z * player.speed;
	}
	if(controls.keyS) {
		player.vel.x -= player.fwd.x * player.speed;
		player.vel.z -= player.fwd.z * player.speed;
	}
	if(controls.keyD) {
		player.vel.x += player.right.x * player.speed;
		player.vel.z += player.right.z * player.speed;
	}
	if(controls.keySpace) {
		player.vel.y -= player.speed;
	}
	if(controls.keyShift) {
		player.vel.y += player.speed;
	}

	player.pos += player.vel;
	player.rot = controls.rot;

	player.vel = player.vel * 0.8f;

	if(	controls.lastMousePosition.x < 25 ||
		controls.lastMousePosition.x > renderer.width - 25 ||
		controls.lastMousePosition.y < 25 ||
		controls.lastMousePosition.y > renderer.height - 25) {
		controls.lastMousePosition = glm::vec2(renderer.height/2, renderer.width/2);
		glutWarpPointer( renderer.width/2, renderer.height/2 );
	}
}

void Game::Draw(Renderer renderer, TextureAtlas textureAtlas) {
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			world.Draw(renderer, textureAtlas, x, y);
		}
	}
}

void Game::Init() {
	world.HeightGenerator.Set(1, 4, 6, 2, 12345);
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			world.Generate(x, y);
		}
	}
	Log(std::to_string(world.chunks[0][0].x));
	player = {
		.pos = glm::vec3(0.0f, 0.0f, 0.0f),
		.vel = glm::vec3(0.0f, 0.0f, 0.0f),
		.fwd = glm::vec3(0.0f, 0.0f, 0.0f),
		.right = glm::vec3(0.0f, 0.0f, 0.0f),
		.rot = glm::vec2(0.0f, 0.0f),
		.speed = 0.05f
	};
}