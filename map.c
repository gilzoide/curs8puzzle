#include "map.h"

#include <mosaic/color.h>
#include <ncurses.h>
#include <stdlib.h>

WINDOW *field;

/// The number representations (in ASC)
const char *nonumber[] = {
	"",
	"",
	"",
	"",
	""
};
const char *number1[] = {
	"   _ ",
	"  / |",
	"  | |",
	"  | |",
	"  |_|"
};
const char *number2[] = {
	" ____  ",
	"|___ \\",
	"  __) |",
	" / __/ ",
	"|_____|"
};
const char *number3[] = {
	" _____",
	"|___ /",
	"  |_ \\ ",
	" ___) |",
	"|____/"
};
const char *number4[] = {
	" _  _ ",
	"| || |",
	"| || |_",
	"|__   _|",
	"   |_|"
};
const char *number5[] = {
	" ____ ",
	"| ___|",
	"|___ \\",
	" ___) |",
	"|____/"
};
const char *number6[] = {
	"  __",
	" / /_", 
	"| '_ \\", 
	"| (_) |",
	" \\___/"
};
const char *number7[] = {
	" _____ ",
	"|___  |",
	"   / /",
	"  / /",
	" /_/"
};
const char *number8[] = {
	"  ___ ",
	" ( _ )",
	" / _ \\",
	"| (_) |",
	" \\___/"
};
const char **numbers[] = {
	nonumber, number1, number2, number3, number4, number5, number6, number7, number8
};

/// Prints a number on the map
void printNumber (int num, int y, int x) {
	int i;
	for (i = 0; i < CELL_HEIGHT; i++) {
		mvwaddstr (field, y * (CELL_HEIGHT + 1) + i + 1, x * (CELL_WIDTH + 1) + 1,
				numbers[num][i]);
	}
	wrefresh (field);
}


/// Our map
int map[SIDE_SIZE][SIDE_SIZE];


void initField () {
	int height = SIDE_SIZE * CELL_HEIGHT + SIDE_SIZE + 1;
	int width = SIDE_SIZE * CELL_WIDTH + SIDE_SIZE + 1;

	field = subwin (stdscr, height, width,
			(LINES - height) / 2, (COLS - width) / 2);

	// the box
	box (field, ACS_VLINE, ACS_HLINE);

	int i, j;
	wattron (field, COLOR_PAIR (Normal));
	// put vertical lines
	for (i = 1; i < SIDE_SIZE; i++) {
		for (j = 1; j < height - 1; j++) {
			mvwaddch (field, j, i * (CELL_WIDTH + 1), ACS_VLINE);
		}
	}
	// and horizontal ones
	for (i = 1; i < SIDE_SIZE; i++) {
		for (j = 1; j < width - 1; j++) {
			mvwaddch (field, i * (CELL_HEIGHT + 1), j, ACS_HLINE);
		}
	}
	wrefresh (field);
}


void remap () {
	int i, j;
	// clean the map...
	for (i = 0; i < SIDE_SIZE; i++) {
		for (j = 0; j < SIDE_SIZE; j++) {
			map[i][j] = -1;
		}
	}

	// ...and put the new numbers
	int nums_left = SIDE_SIZE * SIDE_SIZE;
	while (nums_left) {
		i = rand () % SIDE_SIZE;
		j = rand () % SIDE_SIZE;
		if (map[i][j] == -1) {
			nums_left--;
			// set it in the map
			map[i][j] = nums_left;
			// and print, pliz
			printNumber (nums_left, i, j);
		}
	}
}


void moveBlank (Directions dir) {

}


void destroyField () {
	delwin (field);
}
