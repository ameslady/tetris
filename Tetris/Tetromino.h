#pragma once
#include "Point.h"
#include <vector>

enum TetColor {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE_LIGHT,
	BLUE_DARK,
	PURPLE
};

enum TetShape {
	SHAPE_S,
	SHAPE_Z,
	SHAPE_L,
	SHAPE_J,
	SHAPE_O,
	SHAPE_I,
	SHAPE_T,
	TetShapeCount
};

class Tetromino {
	// Friends
	friend class TestSuite;

private:
	TetColor color;
	TetShape shape;

protected:
	std::vector<Point> blockLocs;

public:
	Tetromino();
	TetColor getColor();
	TetShape getShape();
	static TetShape getRandomShape();
	void setShape(TetShape shape);
	void rotateCW();
	void printToConsole();
};
