#define _HEIHOU
#ifdef _HEIHOU
#include"libone.h"
void gmain() {
	window(1000, 1000);
	let a, b, c;
	while (notQuit) {
		a = mathMouseX;
		b = mathMouseY;
		c = sqrt(a * a + b * b);

		clear(140);
		mathAxis(7.1);

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