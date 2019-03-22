//
//  Tetromino.h
//  L6Q1
//
//  Created by Andrew on 2019-03-04.
//  Copyright © 2019 ICS214. All rights reserved.
//



#ifndef TETROMINO_H
#define TETROMINO_H
#include "Point.h"
#include <vector>
#include <string>

enum class TetColor { RED, ORANGE, YELLOW, GREEN, BLUE_LIGHT, BLUE_DARK, PURPLE };

enum class TetShape { SHAPE_S, SHAPE_Z, SHAPE_L, SHAPE_J, SHAPE_O, SHAPE_I, SHAPE_T };

class Tetromino {

friend class TestSuite;// (allows TestSuite access to private members for testing) 

private:
	TetColor color;
	TetShape shape;

protected:
	std::vector<Point> blockLocs;

public:
	Tetromino();
	TetColor getColor();
	TetShape getShape();
	void setShape(TetShape shape);
	void rotateCW();
	void printToConsole();

};

#endif /* TETROMINO_H */