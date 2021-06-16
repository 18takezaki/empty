
#include"libOne.h"
#include"game.h"
void load(struct GAME* g) {
	load(&g->obstacle);                       @
	load(&g->player);
}
void init(struct GAME* g) {
	init(&g->obstacle);
	init(&g->player);
	g->state = g->PLAY;
}
void play(struct GAME* g) {
	move(&g->obstacle);
	move(&g->player);
	draw(g);
	if (collision(&g->player, &g->obstacle)) {
		g->state = g->OVER;
	}
}
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

void over(struct GAME* g) {
	draw(g);
	textSize(300);
	text("Game Over", 30, 200);
}
void clear(struct GAME* g);
void draw(struct GAME* g) {
	clear(70, 0, 70);
	draw(&g->obstacle);
	draw(&g->player);
	drawRectArea(&g->obstacle.p, &g->obstacle.r);
	drawRectArea(&g->player.p, &g->player.r);
}
