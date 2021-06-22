#define _VECTOR

#ifdef _VECTOR
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	while (notQuit) {
		float vx = mathMouseX;
		float mag = vx < 0 ? -vx : vx;
		float nvx = vx / mag;
		clear(200);
		mathAxis(5.1f);
		strokeWeight(10);
		stroke(0);
		mathArrow(0, 0, vx, 0);
		stroke(255, 0, 0);
		mathArrow(0, 0, nvx, 0);

		textSize(50);
		text(vx, 0, 50);
		text(mag, 0, 100);
	}
}
#endif

#ifdef _STAR
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	struct POS {
		float x, y, z;
	};
	const int num = 1000;
	struct POS p[num];
	for (int i = 0; i < num; i++) {
		p[i].x = random(-1.0f, 1.0f);
		p[i].y = random(-0.5f, 0.5);
		p[i].z = random(0.0f, 1.0f);
	}
	while (notQuit) {
		for (int i = 0; i < num; i++) {
			p[i].z -= 0.005f;
			if (p[i].z <= 0.0f) {
				p[i].z = 1.0f;
			}
		}
		fill(0, 0, 0, 60);
		strokeWeight(0);
		rect(0, 0, width, height);
		mathAxis(1.0f);
		stroke(200,255,255);
		for (int i = 0; i < num; i++) {
			float size = (1.0f - p[i].z) * 20.0f;
			strokeWeight(size);
			mathPoint(p[i].x/p[i].z, p[i].y / p[i].z);
		}
	}
}
#endif

#ifdef _HOSHI
#include "libOne.h"

int createTriangle() {
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3);
}
int createPolygon() {
	const int NUM = 6;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		vertices[i].x = sin(deg * i);
		vertices[i].y = -cos(deg * i);
	}
	return createShape(vertices, NUM);
}

int createStar() {
	const int NUM = 10;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		float radius = 0.5f + 0.5f * (i % 2);
		vertices[i].x = sin(deg * i)*radius;
		vertices[i].y = cos(deg * i)*radius;
	}
	return createShape(vertices, NUM);
}
int createHeart() {
	const int NUM = 80;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		float t = deg * i;
		vertices[i].x = 
			pow(sin(t),3);
		vertices[i].y = -(
			13 * cos(t) -
			5 * cos(2 * t) -
			2 * cos(3 * t) -
			1 * cos(4 * t))/16;
	}
	return createShape(vertices, NUM);
}
void gmain() {
	window(1000, 1000);
	int idx = createHeart();
	//int idx = createStar();
	//int idx = ();
	float deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		deg += 1;
		clear(200);
		strokeWeight(5);
		fill(255, 200, 200);
		shape(idx, 500, 500, deg, 200);
	}
}
#endif

#ifdef _TAKAKUKE
#include "libOne.h"

int createPolygon() {
	const int NUM = 6;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		vertices[i].x = sin(deg*i);
		vertices[i].y = -cos(deg*i);
	}
	return createShape(vertices, NUM);
}
void gmain() {
	window(1000, 1000);
	int idx = createPolygon();
	float deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		deg += 1;
		clear(200);
		strokeWeight(5);
		fill(255, 255, 0);
		shape(idx, width / 2, height / 2, deg, 200);
	}
}
#endif

#ifdef _CUSTOM
#include "libOne.h"
int createTriangle() {
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3);
}
void gmain() {
	window(1000, 1000);
	int idx = createTriangle();
	float deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		deg += 1;
		clear(200);
		strokeWeight(5);
		fill(255, 255, 0);
		shape(idx, width/2, height/2, deg, 200);
	}
}
#endif

#ifdef _JIKAN
#include"libOne.h"
#include<time.h>
void gmain() {
	window(1000, 1000);
	float x, y, deg = 0;
	float second = 0, minute = 0, hour = 0;
	angleMode(DEGREES);
	time_t stdTime;
	struct tm local;
	while (notQuit) {
		time(&stdTime);
		localtime_s(&local, &stdTime);
		second = local.tm_sec;
		minute = local.tm_min;
		hour = local.tm_hour;

		//second += 20;
		//if (second >= 60) { minute++; second = 0; }
		//if (minute >= 60) { hour++; minute = 0; }
		clear(200);

		deg = 30 * hour + 30 * minute / 60;
		x = sin(deg) * 300;
		y = -cos(deg) * 300;
		strokeWeight(20);
		line(500, 500, 500 + x, 500 + y);  

		deg = 6 * minute + 6 * second / 60;
		x = sin(deg) * 400;
		y = -cos(deg) * 400;
		strokeWeight(10);
		line(500, 500, 500 + x, 500 + y);

		deg = 6 * second;
		x = sin(deg) * 400;
		y = -cos(deg) * 400;
		strokeWeight(5);
		line(500, 500, 500 + x, 500 + y);
	}
}
#endif

#ifdef _ACTION
#include"libOne.h"
#include"obstacle.h"
#include"player.h"
#include"rect_area.h"
int collision(struct PLAYER* p, struct OBSTACLE* o) {
	float pLeft = p->p.x + p->r.dx;
	float pRight = pLeft + p->r.w;
	float pTop = p->p.y + p->r.dy;
	float pBottom = pTop + p->r.h;
	float oLeft = o->p.x + o->r.dx;
	float oRight = oLeft + o->r.w;
	float oTop = o->p.y + o->r.dy;
	float oBottom = oTop + o->r.h;
	if (pRight < oLeft || oRight < pLeft ||
		pBottom < oTop || oBottom < pTop) {
		return 0;
	}
	return 1;
}
void gmain() {
	window(1920, 1080, full);
	struct OBSTACLE obstacle;
	struct OBSTACLE* o = &obstacle;
	struct PLAYER player;
	load(&obstacle);
	load(&player);
	init(&obstacle);
	init(&player);
	while (notQuit) {
		move(&obstacle);
		move(&player);
		if (collision(&player, &obstacle))
			clear(250, 0, 0);
		else
			clear(70, 0, 70);
		draw(&obstacle);
		draw(&player);
		drawRectArea(&obstacle.p, &obstacle.r);
		drawRectArea(&player.p, &player.r);
	}
}
#endif

#ifdef _三角関数
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	let x, y, z, deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		if (isPress(KEY_W)) deg += 1;
		if (isPress(KEY_S)) deg -= 1;
		x = cos(deg);
		y = sin(deg);
		z = sqrt(x * x + y * y);
		clear(128);
		mathAxis(1.2);
		strokeWeight(10);
		stroke(160, 200, 255);
		mathLine(0, 0, x, y);
		stroke(255, 255, 200);
		mathLine(0, 0, x, 0);
		stroke(255, 200, 200);
		mathLine(x,y,x,0);

		textSize(50);
		text(x, 0, 60);
		text(y, 0, 120);
		text(z, 0, 180);
	}
}

#endif

#ifdef _HANTEI
#include"libOne.h"
void gmain () {
	window(1000, 1000);
	struct CIRCLE {
		float x, y, z;
	};
	struct CIRCLE c1, c2;
	c1.x = width / 2;
	c1.y = height / 2 + 100;
	c1.z = 50;
	c2.x = 0;
	c2.y = 0;
	c2.z =100;

	while (notQuit) {
		c2.x = MouseX;
		c2.y = MouseY;

		float a = c2.x - c1.x;
		float b = c2.y - c1.y;
		float distance = sqrt(a * a + b * b);

		if (distance <= c1.z + c2.z) {
			fill(255, 0, 0,128);
		}
		else {
			fill(255);
		}

		clear(160);
		circle(c1.x, c1.y, c1.z * 2);
		circle(c2.x, c2.y, c2.z * 2);
		line(c1.x, c1.y, c2.x, c2.y);
		line(c1.x, c1.y, c2.x, c1.y);
		line(c2.x, c2.y, c2.x, c1.y);

		textSize(50);
		text(distance, 0, 60);
	}
}


#endif 

#ifdef _OSERO
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

enum {
	COLOR_NONE=-1,
	COLOR_BLACK=0,
	COLOR_WHITE=1,
	COLOR_MAX
};
enum {
	DIRECTION_UP,
	DIRECTION_UP_LEFT,
	DIRECTION_LEFT,
	DIRECTION_DOWN_LEFT,
	DIRECTION_DOWN,
	DIRECTION_DOWN_RIGTH,
	DIRECTION_RIGHT,
	DIRECTION_UP_RIGHT,
	DIRECTION_MAX
};
int directions[][2] = {
	{0,-1},// DIRECTION_UP
	{-1,-1},// DIRECTION_UP_LEFT
	{-1,0},// DIRECTION_LEFT
	{-1,1},// DIRECTION_DOWN_LEFT
	{0,1},// DIRECTION_DOWN
	{1,1},// DIRECTION_DOWN_RIGTH
	{1,0},// DIRECTION_RIGHT
	{1,-1},// DIRECTION_UP_RIGHT
};
char colorNames[][5 + 1] = {
	"Black",
	"White"
};

int cells[BOARD_HEIGHT][BOARD_WIDTH];

int cursorX, cursorY;
int turn;

bool checkCanPut(int _color, int _x, int _y,bool _turnOver) {
	if(cells[_y][_x] != COLOR_NONE)
		return false;

	for (int i = 0; i < DIRECTION_MAX; i++) {
		int x = _x, y = _y;
		x += directions[i][0];
		y += directions[i][1];
		if (cells[y][x] != (_color ^ 1))
			continue;
		while (1) {
			x += directions[i][0];
			y += directions[i][1];

			if ((x < 0) || (x >= BOARD_WIDTH) || (y < 0) || (y >= BOARD_HEIGHT))
				break;
			if (cells[y][x] == COLOR_NONE)
				break;
			if (cells[y][x] == _color) {
				if(!_turnOver)
					return true;

				int x2 = _x, y2 = _y;
				while(1){
					cells[y2][x2] = _color;

					x2 += directions[i][0];
					y2 += directions[i][1];

					if ((x2 == x) && (y2 == y))
						break;
				}
			}
		}
	}
	return false;
}

/*bool checkCanPutAll(int _color) {
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (checkCanPut(_color, x, y, false))
				return true;

		return false;
	}



}*/
void drowBoard() {
	system("cls");
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++)
			if ((x == cursorX) && (y == cursorY))
				printf("◎");
			else {
				switch (cells[y][x]) {
				case COLOR_NONE: printf("・"); break;
				case COLOR_BLACK:printf("〇"); break;
				case COLOR_WHITE:printf("●"); break;
				}
			}
		printf("\n");
	}
}
int main() {
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++)
			cells[y][x] = COLOR_NONE;
	}
	cells[3][3] = cells[4][4] = COLOR_WHITE;
	cells[4][3] = cells[3][4] = COLOR_BLACK;
	bool cantPut = false;
	while (1) {
		drowBoard();
		
		if (cantPut)
			printf("Can't put!\n");
		else
			printf("%s turn \n", colorNames[turn]);

		cantPut = false;
		switch (_getch()) {
		case'w': cursorY--; break;
		case's': cursorY++; break;
		case'a': cursorX--; break;
		case'd': cursorX++; break;
		default:
			if (!checkCanPut(turn, cursorX, cursorY, false)) {
				cantPut = true;
				break;
			}

			checkCanPut(turn, cursorX, cursorY, true);

			cells[cursorY][cursorX] = turn;
			turn ^= 1;	//１だったら０、０だったら１に変換

			/*if (!checkCanPutAll(turn))
				turn ^= 1;*/
			
			break;
		}
		/*if ((!checkCanPutAll(COLOR_BLACK)) && (!checkCanPutAll(COLOR_WHITE))) {
			int count[COLOR_MAX] = {};
			for (int y = 0; y < BOARD_HEIGHT; y++) 
				for (int x = 0; x < BOARD_WIDTH; x++)
					if (cells[y][x] != COLOR_NONE)
						count[cells[y][x]]++;

			drowBoard();
			for (int i = 0; i < COLOR_MAX; i++)
				printf("%s:%d\n", colorNames[i], count[i]);

			if (count[COLOR_BLACK] == count[COLOR_WHITE])
				printf("Doraw!\n");
			    
			else {
				if (count[COLOR_BLACK] > count[COLOR_WHITE])
					printf("%s\n", colorNames[COLOR_BLACK]);
				else printf("%s\n", colorNames[COLOR_WHITE]);

				printf(" Won1\n");
			}

			_getch();
			break;
		}*/
	}
}
#endif
#ifdef _sircle
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	clear(200);

	strokeWeight(20);
	stroke(0, 255, 0);
	fill(255, 0, 0);

	float px = 500, py = 500, radius = 200;
	circle(px, py, radius * 2);

	pause();
}
#endif
#ifdef _ZUKEI
#include"libone.h"
void gmain() {
	window(800, 450, full);
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 16; i++) {
			if ((j + i) % 2 == 0)fill(0);
			else fill(0, 100, 0);
			rect(50 * i, 50 * j, 50, 50);
		}
	}
	pause();
}
#endif

#ifdef _YUKI
#include"libOne.h"
void yukiX(float px, float py) {
	strokeWeight(0); stroke(0);
	fill(255, 255, 0);
	rect(px - 72, py - 372, 150, 20);
	rect(px - 32, py - 480, 70, 120);
	strokeWeight(5); stroke(0);
	fill(255, 255, 255);
	circle(px, py - 250, 200);
	circle(px, py, 300);
	fill(0); stroke(0);
	circle(px + 40, py - 280, 30);
	circle(px - 40, py - 280, 30);
	strokeWeight(15); stroke(0);
	line(px, py - 200, 920, 320);
	line(px, py - 200, 1000, 320);
	stroke(239, 159, 0);
	line(px - 120, py - 90, 750, 340);
	line(px + 120, py - 90, 1200, 340);
	stroke(0);
	circle(px, py - 90, 15);
	circle(px, py - 20, 15);
}
void yukiY(float px, float py) {
	float hue = 190;
	float satu = 255;
	float value = 255;
	strokeWeight(0); stroke(0);
	fill(hue, satu, 0);
	rect(px - 72, py - 372, 150, 20);
	rect(px - 32, py - 480, 70, 120);
	strokeWeight(5); stroke(0);
	fill(hue, satu, 0);
	circle(px, py - 250, 200);
	circle(px, py, 300);
	fill(0); stroke(0);
	circle(px + 40, py - 280, 30);
	circle(px - 40, py - 280, 30);
	strokeWeight(15); stroke(0);
	line(px, py - 200, 920, 320);
	line(px, py - 200, 1000, 320);
	stroke(239, 159, 0);
	line(px - 120, py - 90, 750, 340);
	line(px + 120, py - 90, 1200, 340);
	stroke(0);
	circle(px, py - 90, 15);
	circle(px, py - 20, 15);
}
void gmain() {
	window(1920, 1080);
	float px = width / 2;
	float py = height / 2;
	int sw = 1;
	while (notQuit) {
		if (isTrigger(KEY_SPACE)) { sw = 1 - sw; }
		clear(60, 120, 240);
		if (sw == 1) {
			yukiX(px, py);
		}
		else {
			yukiY(px, py);

		}
	}
}
#endif
#ifdef _HEIHOU
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	let a, b, c;
	while (notQuit) {
		a = mathMouseX;
		b = mathMouseY;
		c = sqrt(a * a + b * b);

		clear(140);
		mathAxis(4.1);

		stroke(60, 120, 240);
		strokeWeight(4);
		mathLine(0, 0, a, b);
		mathLine(0, 0, a, 0);
		mathLine(a, 0, a, b);

		textSize(50);
		text("底辺=" + a, 0, 60);
		text("高さ=" + b, 0, 120);
		text("斜辺=" + c, 0, 180);

	}
}
#endif

#ifdef _MENSEKI
#include"libone.h"
void gmain() {
	window(1000, 1000);
	let area = 4;
	let length = 0;
	while (notQuit) {
		if (isTrigger(KEY_D)) {
			++area;
		}
		if (isTrigger(KEY_A)) {
			--area;
		}

		length = sqrt(area);

		clear(60);
		mathAxis(9.1);

		fill(255,200,200);
		mathRect(0, 0, length, -length);

		textSize(50);
		text("面積 =" + area, 0, 60);
		text("√" + area + " = " + length, 0, 120);
	}
}
#endif
#ifdef _KYU
#include"libOne.h"
struct POS {
	float x, y, z;
};
void gmain() {
	window(1000, 1000);
	colorMode(HSV);
	float hue = 0;
	float satu = 255;
	float value = 255;
	int numCorners = 38;
	int numRings = numCorners / 2 + 1;
	int numVertices = numCorners * numRings;
	float deg = 360.0f / numCorners;
	angleMode(DEGREES);
	struct  POS* op = new POS[numVertices];
	for (int j = 0; j < numRings; j++) {
		float r = sin(deg * j);
		float z = cos(deg * j);
		for (int i = 0; i < numCorners; i++) {
			int k = j * numCorners + i;
			op[k].x = sin(deg * i) * r;
			op[k].y = cos(deg * i) * r;
			op[k].z = z;// 1.0f - 2.0f / (numRings - 1) * j;
		}
	}
	struct POS* p = new POS[numVertices];
	deg = 0;
	int state = 0;
	while (notQuit) {
		if (random() && hue < 360)hue += -2;
		if (random() && hue > 0)hue += 2;
		if (random() && hue < 360)hue += -5;
		if (random() && hue > 0)hue += 5;
		if (random() && satu < 360)satu += -5;
		if (random() && satu > 0)satu += 5;
		if (random() && value < 360)value += -15;
		if (random() && value > 0)value += 15;
		float s = sin(deg);
		float c = cos(deg);
		deg++;
		if (deg > 360) {
			deg = 0;
			++state %= 2;
		}
		for (int i = 0; i < numVertices; i++) {
			if (state  == 0) {
				p[i].x = op[i].x * c + op[i].z * -s;
				p[i].y = op[i].y;
				p[i].z = op[i].x * s + op[i].z * c;
			}
			else {
				p[i].x = op[i].x;
				p[i].y = op[i].y * c + op[i].z * -s;
				p[i].z = op[i].y * s + op[i].z * c;
			}
			p[i].z += 5;

			p[i].x /= p[i].z;
			p[i].y /= p[i].z;
		}
		clear(0,0,0);
		mathAxis(0.5);
		stroke(hue, satu, value);
		for (int i = 0; i < numVertices; i++) {
			mathPoint(p[i].x, p[i].y);
			int j = i + 1;
			if (j % numCorners == 0)j -= numCorners;
			strokeWeight(2);
			mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			if (i < numVertices - numCorners) {
				j = i + numCorners;
				mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			}
		}
	}
	delete[]op;
	delete[]p;
}


#endif 
#ifdef _RIPPOU
#include"libOne.h"
struct POS {
	float x, y, z;
};
void gmain() {
	window(1000, 1000);
	const int numVertices = 8;
	struct  POS op[numVertices] = {
		-1,1,-1,
		-1,-1,-1,
		1,-1,-1,
		1,1,-1,
		-1,1,1,
		-1,-1,1,
		1,-1,1,
		1,1,1,
	};
	struct POS p[numVertices];
	float deg = 0;
	angleMode(DEGREES);
	int state = 0;
	while (notQuit) {
		float s = sin(deg);
		float c = cos(deg);
		deg++;
		if (deg > 360) {
			deg = 0;
			++state %= 2;
		}
		for (int i = 0; i < numVertices; i++) {
			if (state == 0) {
				p[i].x = op[i].x * c + op[i].z * -s;
				p[i].y = op[i].y;
				p[i].z = op[i].x * s + op[i].z * c;
			}
			else {
				p[i].x = op[i].x;
				p[i].y = op[i].y * c + op[i].z * -s;
				p[i].z = op[i].y * s + op[i].z * c;
			}
			p[i].z += 5;

			p[i].x /= p[i].z;
			p[i].y /= p[i].z;
		}
		clear(128);
		mathAxis(0.5);
		stroke(250, 220, 40);
		strokeWeight(10);
		for (int i = 0; i < 4; i++) {
			int j = (i + 1) % 4;
			mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			mathLine(p[i+4].x, p[i+4].y, p[j+4].x, p[j+4].y);
			mathLine(p[i].x, p[i].y, p[i+4].x, p[i+4].y);
		}
	}
}


#endif 
#ifdef _COLOR
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	colorMode(HSV);
	angleMode(DEGREES);
	float hue = 0;
	float satu = 255;
	float value = 255;
	while (notQuit) {
		if (isPress(KEY_A) && hue < 360)hue += 5;
		if (isPress(KEY_D) && hue > 0)hue += -5;
		if (isTrigger(KEY_W) && hue < 360)hue += 5;
		if (isTrigger(KEY_S) && hue > 0)hue += -5;
		if (isPress(KEY_R) && satu < 360)satu += 5;
		if (isPress(KEY_F) && satu > 0)satu += -5;
		if (isPress(KEY_T) && value < 360)value += 5;
		if (isPress(KEY_G) && value > 0)value += -5;

		clear(0, 0, 0);
		fill(hue, satu, value);
		textSize(120);
		text((let)"hue=" + hue, 600, 400);
		text((let)"satu=" + satu, 600, 600);
		text((let)"value=" + value, 600, 800);
		int numVertices = 128;
		float angle = hue / numVertices;
		for (int i = 0; i < numVertices; i++) {
			float px = cos(angle * i) * 200;
			float py = -sin(angle * i) * 200;
			fill(angle * i, satu, value);
			noStroke();
			circle(1500 + px, 540 + py, 50);
		}
	}
}
#endif
#ifdef _SROT
#include"libOne.h"
void gmain() {
	window(1100, 1000);
	const int numVertices = 20;
	int score[numVertices];
	int r, c;
	for (int i = 0; i < numVertices; i++) {
		score[i] = random() % 1001;
	}
	while (notQuit) {
		clear(60);

		if (isTrigger(KEY_A)) {
			for (int i = 0; i < numVertices; i++) {
				score[i] = random() % 1001;
			}
		}

		if (isTrigger(KEY_D)) {
			for (r = 0; r < numVertices - 1; r++) {
				for (c = r + 1; c < numVertices; c++) {
					if (score[r] < score[c]) {
						int w = score[r];
						score[r] = score[c];
						score[c] = w;
					}
				}
			}
		}
		for (int i = 0; i < numVertices; i++) {
			print(score[i]);
			rect(100, 50 * i, score[i], 40);
		}
	}
}
		  
#endif
#ifdef _SHOOT
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);

	struct PLAYER {
		float px, py, w, h, vx, ofsY;
	};
	struct BULLET {
		float px, py, w, h, vy;
		int hp = 0;
	};
	struct PLAYER p;
	p.px = width / 2;
	p.py = height - 150;
	p.w = 100;
	p.h = 200;
	p.vx = 10;
	p.ofsY = -100;
	const int numVerticesBullets = 10;
	struct BULLET b[numVerticesBullets];
	for (int i = 0; i < numVerticesBullets; i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 20;
		b[i].h = 40;
		b[i].vy = -10;
	}
	while (notQuit) {
		if (isPress(KEY_A)) { p.px += -p.vx; }
		if (isPress(KEY_D)) { p.px += p.vx; }
		if (isTrigger(KEY_SPACE)) {
			for (int i = 0; i < numVerticesBullets; i++) {
				if (b[i].hp == 0) {
					b[i].hp = 1;
					b[i].px = p.px;
					b[i].py = p.py + p.ofsY;
					i = numVerticesBullets;
				}
			}
		}
		for (int i = 0; i < numVerticesBullets; i++) {

			if (b[i].hp > 0) {
				b[i].py += b[i].vy;
				//ウィンドウの外に出た
				if (b[i].py < -b[i].h) {
					b[i].hp = 0;
				}
			}
			clear();
			rectMode(CENTER);
			rect(p.px, p.py, p.w, p.h);
			for (int i = 0; i < numVerticesBullets; i++) {
				if (b[i].hp > 0) {
					rect(b[i].px, b[i].py, b[i].w, b[i].h);
				}
			}
		}
	}
}
#endif
#ifdef _FACE
#include"libOne.h"
void roundFace(float px, float py) {
	fill(255, 255, 0);
	circle(px, py, 300);
	fill(255);
	circle(px + 50, py, 80);
	circle(px - 50, py, 80);
	fill(0);
	circle(px + 50, py, 30);
	circle(px - 50, py, 30);
	fill(255, 200, 200);
	circle(px, py + 80, 80);
}
void squareFace(float px, float py,float angle) {
	rectMode(CENTER);
	fill(255, 255, 0);
	rect(px, py, 300,300,angle);
	fill(255);
	rect(px + 50, py, 80,80,angle);
	rect(px - 50, py, 80,80,angle);
	fill(0);
	rect(px + 50, py, 30,30,angle);
	rect(px - 50, py, 30,30,angle);
	fill(255, 200, 200);
	rect(px, py + 80, 80,80,angle);
}
void gmain() {
	window(1920, 1080, full);
	float px = width / 2;
	float py = height / 2;
	float angle = 0;
	int sw = 1;
	float ofsX = 100;
	float ofsY = 100;
	while (notQuit) {
		ofsX = width / 2 - mouseX;
		ofsY = height / 2 - mouseY;
		if (isTrigger(KEY_SPACE)) { sw = 1 - sw; }
		angle += 0.01f;
		strokeWeight(10);
		clear(60, 120, 240);
		for (int i = -5; i <= 5; i++) {
			if (sw == 1) {
				roundFace(px + ofsX * i, py + ofsY * i);
			}
			else {
				squareFace(px + ofsX * i, py + ofsY * i, angle);
			}

		}
	}
}

#endif
#ifdef _MOVE
#include"libOne.h"
void gmain(){
	window(1920, 1080, full);
	float px = 1920 / 2;
	float py = 1080 / 2;
	float vx = 10;
	float radius = 150;
	float len = radius / 1.4142f * 2;
	float sw = radius / 8;
	float angle = 0;
	float angleSpeed = 0.03f;
	while (notQuit) {
		px += vx;
		angle += angleSpeed;
		if (px < 0 || px > 1920) {
			vx = -vx;
			angleSpeed = -angleSpeed;

		}
		clear(60);
		strokeWeight(sw);
		stroke(255, 0, 0);
		circle(px, py, radius * 2);
		rectMode(CENTER);
		rect(px, py, len, len, angle);
		strokeWeight(sw * 2);
		point(px, py);
		strokeWeight(sw);
		line(1920 / 2, 0, px, py);
	}

}
#endif
#ifdef _MINO
#include<stdio.h>
#include<stdlib.h>
#include<string.h>			//memsetを使えるようにする
#include<time.h>
#include<conio.h>

constexpr auto FIELD_WIDTH = 12;
constexpr auto FIELD_HEIGHT = 22;					//盤面の設定

char field[FIELD_HEIGHT][FIELD_WIDTH];				//フィールドを１か０で設定
char displayBuffer[FIELD_HEIGHT][FIELD_WIDTH];

enum {
	MINO_TYPE_I,
	MINO_TYPE_O,
	MINO_TYPE_S,
	MINO_TYPE_Z,
	MINO_TYPE_J,
	MINO_TYPE_L,
	MINO_TYPE_T,
	MINO_TYPE_MAX
};													//ブロックの宣言

enum {
	MINO_ANGLE_0,
	MINO_ANGLE_90,
	MINO_ANGLE_180,
	MINO_ANGLE_270,
	MINO_ANGLE_MAX
};

constexpr auto MINO_WIDTH = 4;
constexpr auto MINO_HEIGHT = 4;
char  minoShapes[MINO_TYPE_MAX][MINO_ANGLE_MAX][MINO_HEIGHT][MINO_WIDTH] = {
	//MINO_TYPE_I
	{
		// MINO_ANGLE_0
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
		},
		// MINO_ANGLE_90 
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
		},
		// MINO_ANGLE_180
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
		},
		// MINO_ANGLE_270
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
		},
		},
		//MINO_TYPE_O
		{
		// MINO_ANGLE_0
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_90
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_270
		{
		    0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		},
		//MINO_TYPE_S
		{
		// MINO_ANGLE_0
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
					},
		// MINO_ANGLE_90
		{
			0,1,0,0,
			0,1,1,0,
		    0,0,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
		},
		// MINO_ANGLE_270
		{
			0,0,0,0,			
			0,1,0,0,		
			0,1,1,0,
			0,0,1,0,
		},
		},
		//MINO_TYPE_Z
		{
		// MINO_ANGLE_0
		{
			0,0,0,0,
			1,1,0,0,
			0,1,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_90
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,0,
			0,1,0,0,
		},
		// MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,0,1,1,
			0,0,0,0,
		},
		// MINO_ANGLE_270
		{
			0,0,1,0,
			0,1,1,0,
			0,1,0,0,
			0,0,0,0,
		},
		},
		//MINO_TYPE_J
		{
		// MINO_ANGLE_0
		{
			0,0,1,0,
			0,0,1,0,
			0,1,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_90
		{
			0,0,0,0,
			1,1,1,0,
			0,0,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,1,0,0,
			0,1,0,0,
		},
		// MINO_ANGLE_270
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,1,
			0,0,0,0,
		},
		},
		//MINO_TYPE_L
		{
		// MINO_ANGLE_0
		{
			0,1,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_90
		{
			0,0,0,0,
			0,0,1,0,
			1,1,1,0,
			0,0,0,0,
		},
		// MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,0,1,0,
			0,0,1,0,
		},
		// MINO_ANGLE_270
		{
			0,0,0,0,
			0,1,1,1,
			0,1,0,0,
			0,0,0,0,
		},
		},
		//MINO_TYPE_T
		{
		// MINO_ANGLE_0
		{
			0,0,0,0,
			1,1,1,0,
			0,1,0,0,
			0,0,0,0,
		},
		// MINO_ANGLE_90
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,1,0,0,
		},
		// MINO_ANGLE_180
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,1,
			0,0,0,0,
		},
		// MINO_ANGLE_270
		{
			0,0,1,0,
			0,1,1,0,
			0,0,1,0,
			0,0,0,0,
		},
		},
};

int minoType = 0, minoAngle = 0;
int minoX = 5, minoY = 0;

void display() {
	memcpy(displayBuffer, field, sizeof(field));

	for (int i = 0; i < MINO_HEIGHT; i++)
		for (int j = 0; j < MINO_WIDTH; j++)
			displayBuffer[minoY + i][minoX + j] |=
			minoShapes[minoType][minoAngle][i][j];

	system("cls");
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++)
			printf(displayBuffer[i][j] ? "■" : "　");
		printf("\n");
	}
}

bool isHit(int _minoX, int _minoY, int _minoType, int _minoAngle) {
	for (int i = 0; i < MINO_HEIGHT; i++)
		for (int j = 0; j < MINO_WIDTH; j++)
			if (minoShapes[_minoType][_minoAngle][i][j]
				&& field[_minoY + i][_minoX + j])
				return true;
	return false;
}

void resetMino() {
	minoX = 5;
	minoY = 0;
	minoType = rand() % MINO_TYPE_MAX;
	minoAngle = rand() % MINO_ANGLE_MAX;
}
void main() {
	memset(field, 0, sizeof(field));				//メモリーの初期化：フィールドを０で初期化
	for (int i = 0; i < FIELD_HEIGHT; i++)			//
		field[i][0] = field[i][FIELD_WIDTH - 1] = 1;  //
	for (int i = 0; i < FIELD_WIDTH; i++)
		field[FIELD_HEIGHT - 1][i] = 1;

	resetMino();

	time_t t = time(NULL);
	while (1) {
		if (_kbhit()) {
			switch (_getch()) {
				//case 'w':
			case 's':
				if (!isHit(
					minoX,	// int _minoX
					minoY + 1,		// int _minoY
					minoType,	// int _minoType
					minoAngle))	// int _minoAngle
					minoY++;
				break;
			case 'a':
				if (!isHit(
					minoX - 1,	// int _minoX
					minoY,		// int _minoY
					minoType,	// int _minoType
					minoAngle))	// int _minoAngle
					minoX--;
				break;
			case 'd':
				if (!isHit(
					minoX + 1,	// int _minoX
					minoY,		// int _minoY
					minoType,	// int _minoType
					minoAngle))	// int _minoAngle
					minoX++;
				break;
			case 0x20:
				if (!isHit(
					minoX,								// int _minoX
					minoY,								// int _minoY
					minoType,							// int _minoType
					(minoAngle + 1) % MINO_ANGLE_MAX))	// int _minoAngle
					minoAngle = (minoAngle + 1) % MINO_ANGLE_MAX;
				break;
			}
			display();
		}
		if (t != time(NULL)) {
			t = time(NULL);

			if (isHit(
				minoX,			// int _minoX
				minoY + 1,		// int _minoY
				minoType,		// int _minoType
				minoAngle)) {	// int _minoAngle

				for (int i = 0; i < MINO_HEIGHT; i++)
					for (int j = 0; j < MINO_WIDTH; j++)
						field[minoY + i][minoX + j] |= minoShapes[minoType][minoAngle][i][j];
				{
					for (int i = 0; i < FIELD_HEIGHT - 1; i++) {
						bool lineFill = true;
						for (int j = 1; j < FIELD_WIDTH - 1; j++) {
							if (!field[i][j])
								lineFill = false;
						}

						if (lineFill)
							//for (int j = 1; j < FIELD_WIDTH - 1; j++)
							//	field[i][j] = 0;

							for (int j = i; 0 < j; j--)
								memcpy(field[j], field[j - 1], FIELD_WIDTH);
					}
				}
				resetMino();
			}
			else
				minoY++;

			display();

		}
	}

	int _getch();
}
#endif