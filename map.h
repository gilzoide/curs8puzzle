#pragma once


/// Map side's size
#define SIDE_SIZE 3
/// Each cell's dimension
#define CELL_HEIGHT 5
#define CELL_WIDTH 7

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGT
} Directions;


/// Initialize Field WINDOW and draw it
void initField ();

/// Reroll map, with random positions
void remap ();

/// Please, move the blank
void moveBlank (Directions dir);

/// Destroy the Field WINDOW
void destroyField ();
