#define _MINO
#ifdef _YUKI
#include"libOne.h"
void yukiX(float px,float py) {
	strokeWeight(0); stroke(0);
	fill(255,255,0);
	rect(px - 72, py - 372, 150, 20);
	rect(px - 32, py - 480, 70, 120);
	strokeWeight(5); stroke(0);
	fill(255,255 ,255);
	circle(px, py - 250, 200);
	circle(px, py, 300);
	fill(0); stroke(0);
	circle(px + 40, py - 280, 30);
	circle(px - 40, py - 280, 30);
	strokeWeight(15); stroke(0);
	line(px, py - 200, 920, 320);
	line(px, py - 200, 1000, 320);
	stroke(239,159,0);
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
		clear(60,120,240);
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
			fill(angle*i, satu, value);
			noStroke();
			circle(1500+px, 540+py, 50);
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