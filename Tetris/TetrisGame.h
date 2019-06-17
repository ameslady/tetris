#ifndef TETRISGAME_H
#define TETRISGAME_H

#include "Gameboard.h"
#include "GridTetromino.h"
#include <SFML/Graphics.hpp>


class TetrisGame
{
public:
	// STATIC CONSTANTS
	static const int BLOCK_WIDTH = 32;			// pixel width of a tetris block
	static const int BLOCK_HEIGHT = 32;			// pixel height of a tetris block

	// MEMBER FUNCTIONS
	// constructors
	TetrisGame(sf::RenderWindow *window, sf::Sprite *blockSprite, Point gameboardOffset, Point nextShapeOffset);	 
	~TetrisGame();	

	void draw();								
	void onKeyPressed(sf::Event event);
	void processGameLoop(float secondsSinceLastLoop);
	void tick();

private:
	void reset(); 
	void pickNextShape();
	bool spawnNextShape();																	
	bool attemptRotate(GridTetromino &shape);
	bool attemptMove(GridTetromino &shape, int x, int y);											
	void drop(GridTetromino &shape); 
	void lock(GridTetromino &shape);
	
	// Graphics methods ==============================================
	void drawBlock(int x, int y, TetColor color, Point origin);
	void drawGameboard();
	void drawTetromino(GridTetromino tetromino, Point origin);
	void setScore(int score);

	// State & gameplay/logic methods ================================
	bool isPositionLegal(const GridTetromino &shape);					
	bool isShapeWithinBorders(const GridTetromino &shape);
	bool doesShapeIntersectLockedBlocks(const GridTetromino &shape);
	void determineSecsPerTick();

	// MEMBER VARIABLES

	// State members ---------------------------------------------
	int score = 0;				// the current game score.
    Gameboard board;			// the gameboard (grid) to represent where all the blocks are.
    GridTetromino nextShape;	// the tetromino shape that is "on deck".
    GridTetromino currentShape;	// the tetromino that is currently falling.

	// Graphics members ------------------------------------------
	Point gameboardOffset = {0,0};	// pixel XY offset of the gameboard on the screen
	Point nextShapeOffset = {0,0};	// pixel XY offset to the nextShape
	sf::Sprite *pBlockSprite;		// a pointer to the sprite used for all the blocks.
	sf::RenderWindow *pWindow;		// a pointer to the window that we are drawing on.

	sf::Font scoreFont;				// SFML font for displaying the score.
	sf::Text scoreText;				// SFML text object for displaying the score
	
								
	// Time members ----------------------------------------------
	// Note: a "tick" is the amount of time it takes a block to fall one line.

	const double MAX_SECS_PER_TICK = 0.75;		// start off with a slow (max) tick rate. (seconds per game tick)
	const double MIN_SECS_PER_TICK = 0.20;		// this is the fastest tick pace (seconds per game tick).
	double secsPerTick = MAX_SECS_PER_TICK;		// the number of seconds per tick (changes depending on score)
											
	double secondsSinceLastTick = 0.0;			// update this every game loop until it is >= secsPerTick,
												// we then know to trigger a tick.  Reduce this var (by a tick) & repeat.
	bool shapePlacedSinceLastGameLoop = false;	// Tracks whether we have placed (locked) a shape on
												// the gameboard in the current gameloop
};

#endif /* TETRISGAME_H */

