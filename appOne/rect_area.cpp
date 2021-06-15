#include"libOne.h"
#include"float2.h"
#include"rect_area.h"
void drawRectArea(struct FLOAT2* p, struct RECT_AREA* r) {
	fill(0, 255, 0, 128);
	rect(p->x + r->dx, p->y + r->dy, r->w, r->h);
}