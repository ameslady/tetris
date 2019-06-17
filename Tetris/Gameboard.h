#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "Point.h"

class Gameboard
{
public:
	// CONSTANTS
	static const int MAX_X = 10;		
	static const int MAX_Y = 19;		
	static const int EMPTY_BLOCK = -1;	

	// MEMBER FUNCTIONS
	Gameboard();								
    
	int getContent(Point pt) const;				
    int getContent(int x, int y) const;			

	void setContent(Point pt, int content);		
	void setContent(int x, int y, int content);	
	void setContent(std::vector<Point> locs, int content);	

	bool areLocsEmpty(std::vector<Point> locs) const;
	int removeCompletedRows();					
	void empty();								
	Point getSpawnLoc() const;					
	void printToConsole() const;				


private:
	bool isRowCompleted(int rowIndex) const;
	std::vector<int> getCompletedRowIndices() const;	
	void removeRow(int rowIndex);				
	void removeRows(std::vector<int> rowIndices); 

	void fillRow(int rowIndex, int content);	

	void copyRowIntoRow(int sourceRowIndex, int targetRowIndex);	

    // MEMBER VARIABLES -------------------------------------------------
    int grid[MAX_X][MAX_Y];				 
	const Point spawnLoc {MAX_X/2, 0};	

	// FRIENDS
	friend class TestSuite;				
};

#endif /* GAMEBOARD_H */

