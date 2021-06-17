#include"libOne.h"
#include"game.h"

void gmain() {
	window(1920, 1080, full);
	struct GAME game;
	load(&game);
	while (notQuit) {
		if (game.state == game.INIT) {
			init(&game);
		}
		else if (game.state == game.PLAY) {
			play(&game);
		}
		else if (game.state == game.OVER) {
			over(&game);
		}
		else if (game.state == game.CLEAR) {
			clear(&game);
		}
	}
}