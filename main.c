#include <mosaic/color.h>

#include <stdlib.h>
#include <time.h>

#include "map.h"

WINDOW *hud;


void initCurses () {
	initscr ();
	keypad (stdscr, TRUE);
	start_color ();
	InitColors ();
	noecho ();
	raw ();
	curs_set (0);
}


void initHud () {
	hud = subwin (stdscr, 1, COLS, 0, 0);
	wbkgd (hud, COLOR_PAIR (WG) | A_BOLD);
	mvwaddstr (hud, 0, COLS/2 - 4, "8 puzzle");
	wrefresh (hud);
}


int main () {
	int c = 0;	// for getch ()

	srand (time (NULL));

	initCurses ();
	initHud ();
	initFields ();

	remap ();

	while (c != 'q') {
		c = getch ();
		switch (c) {
			case 'r':
				remap ();
				break;

			case KEY_UP:
				moveBlank (UP);
				break;

			case KEY_DOWN:
				moveBlank (DOWN);
				break;

			case KEY_LEFT:
				moveBlank (LEFT);
				break;

			case KEY_RIGHT:
				moveBlank (RIGHT);
				break;
		}
	}

	destroyFields ();
	delwin (hud);
	endwin ();
	return 0;
}
