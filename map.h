#pragma once


/// Map side's size
#define SIDE_SIZE 3

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
