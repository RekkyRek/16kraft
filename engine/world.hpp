#ifndef _WRLD_H
#define _WRLD_H

#include "./renderer.hpp"
#include "./noise.hpp"
#include "./textureAtlas.hpp"

struct Block {
	int type;
	int textureID;
};

struct Chunk {
	Block blocks[16][32][16];
	int x;
	int y;
};

class World {
	public:
		Chunk chunks[4][4];
		PerlinNoise HeightGenerator;
		void Generate(int x, int y);
		void Draw(Renderer renderer, TextureAtlas textureAtlas, int x, int y);
};

#endif