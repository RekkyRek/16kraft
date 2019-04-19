#ifndef _WRLD_H
#define _WRLD_H

#include "./renderer.hpp"
#include "./noise.hpp"

struct Block {
	int type;
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
		void Draw(Renderer renderer, int x, int y);
};

#endif