#pragma once
#include"float2.h"
#include"rect_area.h"
struct PLAYER {
	int imgIdx = 0;
	int imgW = 0;
	int imgH = 0;
	struct FLOAT2 p;
	float vx = 0;
	float vy = 0;
	float initVy = 0;
	float gravity = 0;
	int jumpFlag = 0;
	float limmitPy = 0;
	struct RECT_AREA r;
};
void load(struct PLAYER* p);
void init(struct PLAYER* p);
void move(struct PLAYER* p);
void draw(struct PLAYER* p);