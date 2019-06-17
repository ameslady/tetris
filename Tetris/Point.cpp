#include "Point.h"

/**** CONSTRUCTORS ****/
// Construct a default Point object
Point::Point() {
	x = 0;
	y = 0;
}
// Construct a Point object
Point::Point(int newX, int newY) {
	x = newX;
	y = newY;
}

/**** FUNCTIONS ****/
// Return x 
int Point::getX() const {
	return x;
}
// Return y 
int Point::getY() const {
	return y;
}
// Set x
void Point::setX(int x) {
	this->x = x;
}
// Set y
void Point::setY(int y) {
	this->y = y;
}
// Accept 2 values and set them
void Point::setXY(int x, int y) {
	setX(x);
	setY(y);
}
// Swap x and y
void Point::swapXY() {
	int temp = 0;
	temp = x;
	x = y;
	y = temp;

	// or std::swap(x, y);
}
// Multiply x by some factor
void Point::multiplyX(int factor) {
	x = x * factor;
}
// Multiply y by some factor
void Point::multiplyY(int factor) {
	y = y * factor;
}
// Return a string in the form "[x,y]" to represent
// the state of the Point instance (for debugging)
std::string Point::toString() const {
	return "[" + std::to_string(x) + "," + std::to_string(y) + "]";
}