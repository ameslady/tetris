#include "Tetromino.h"
#include <iostream>
using namespace std;

/**** CONSTRUCTORS ****/
// Create a default Tetromino object
Tetromino::Tetromino() {
	setShape(TetShape::SHAPE_T);

}


/**** FUNCTIONS ****/
// Get the colour
TetColor Tetromino::getColor() {
	return color;
}

// Get the shape
TetShape Tetromino::getShape() {
	return shape;
}

// Get random shape
TetShape Tetromino::getRandomShape() {
	int shapeCount = static_cast<int> (TetShape::TetShapeCount);
	int randomShape = rand() % shapeCount;

	return static_cast<TetShape>(randomShape);
}

// Set the shape
void Tetromino::setShape(TetShape shape) {
// Clear any blockLocs set previously
	blockLocs.clear();

// Set the blockLocs & colour for the shape 
	switch (shape) {
	case TetShape::SHAPE_S:
		blockLocs = { Point(0,0), Point(0,1), Point(1,1), Point(-1,0) };
		color = TetColor::RED;
		break;
	case TetShape::SHAPE_Z:
		blockLocs = { Point(0,0), Point(0,1), Point(-1,1), Point(1,0) };
		color = TetColor::GREEN;
		break;
	case TetShape::SHAPE_L:
		blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(1,-1) };
		color = TetColor::ORANGE;
		break;
	case TetShape::SHAPE_J:
		blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(-1,-1) };
		color = TetColor::BLUE_DARK;
		break;
	case TetShape::SHAPE_O:
		blockLocs = { Point(0,0), Point(0,1), Point(1,1), Point(1,0) };
		color = TetColor::YELLOW;
		break;
	case TetShape::SHAPE_I:
		blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(0,2) };
		color = TetColor::BLUE_LIGHT;
		break;
	case TetShape::SHAPE_T:
		blockLocs = { Point(0,0), Point(1,0), Point(-1,0), Point(0,-1) };
		color = TetColor::PURPLE;
		break;
	}
}

// Rotate shape 90 degrees around [0,0] (clockwise)
void Tetromino::rotateCW() {
	for (Point &point : blockLocs) {
		point.multiplyX(-1);
		point.swapXY();
	}
}

// Print a grid to display current shape
void Tetromino::printToConsole() {
// Start at top left [-3,3] go to bottom right [3,-3] (use nested for loops)
// For each [x,y] point, loop through the blockLocks and if 
// the point exists in the list, print an 'x' instead of a '.'
	for (int y = 3; y >= -3; y--) {
		for (int x = -3; x <= 3; x++) {
			bool pointExists = false;
			for (Point point : blockLocs) {
				if (point.getX() == x && point.getY() == y) {
					pointExists = true;
				}
			}
			if (pointExists) {
				cout << " x ";
			}
			else {
				cout << " . ";
			}
		}
		cout << endl;
	}
}