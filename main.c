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
	initField ();

// main loop
	while (c != 'q') {
		c = getch ();
		switch (c) {
			case 'r':
				remap ();
		}
	}

	delwin (hud);
	endwin ();
	return 0;
}
