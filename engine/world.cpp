#include "world.hpp"
#include "./renderer.hpp"

#include <iostream>

void World::Generate(int chunkX, int chunkY) {
	Chunk chunk;
	chunk.x = chunkX;
	chunk.y = chunkY;

	for (int x = 0; x < 16; ++x) {
		for (int y = 0; y < 32; ++y) {
			for (int z = 0; z < 16; ++z) {
				Block block = { .type = 0 };
				float noise = HeightGenerator.GetHeight(((chunkX * 16) + x) / 16.0f, ((chunkY * 16) + z) / 16.0f) + 6.0f;
				if(y < 3 || y < noise) { block.type = 1; }
				chunk.blocks[x][y][z] = block;
			}	
		}	
	}

	chunks[chunkX][chunkY] = chunk;
}

void World::Draw(Renderer renderer, int chunkX, int chunkY) {
	float ox = renderer.transform.x;
	float oy = renderer.transform.y;
	float oz = renderer.transform.z;

	Chunk chunk = chunks[chunkX][chunkY];
	if (chunk.x == chunkX && chunk.y == chunkY) {
		for (int x = 0; x < 16; ++x) {
			for (int y = 0; y < 32; ++y) {
				for (int z = 0; z < 16; ++z) {
					float absX = (chunk.x * 16) + x + ox;
					float absY = y + oy;
					float absZ = (chunk.y * 16) + z + oz;
					if(chunk.blocks[x][y][z].type > 0) {
						if (chunk.blocks[x][y+1][z].type != 1 || y == 32) { renderer.cube.DrawTopFace(absX, absY, absZ, glm::vec3(0.0f,1.0f,0.0f)); }
						if (chunk.blocks[x][y-1][z].type != 1 || y == 0) { renderer.cube.DrawBottomFace(absX, absY, absZ, glm::vec3(0.0f,0.4f,0.0f)); }
						if (chunk.blocks[x+1][y][z].type != 1 || x == 15) { renderer.cube.DrawRightFace(absX, absY, absZ, glm::vec3(0.0f,0.7f,0.0f)); }
						if (chunk.blocks[x-1][y][z].type != 1 || x == 0) { renderer.cube.DrawLeftFace(absX, absY, absZ, glm::vec3(0.0f,0.7f,0.0f)); }
						if (chunk.blocks[x][y][z+1].type != 1 || z == 15) { renderer.cube.DrawBackFace(absX, absY, absZ, glm::vec3(0.0f,0.7f,0.0f)); }
						if (chunk.blocks[x][y][z-1].type != 1 || z == 0) { renderer.cube.DrawFrontFace(absX, absY, absZ, glm::vec3(0.0f,0.7f,0.0f)); }
					}
				}
			}	
		}
	}
}