//
//  Tetromino.cpp
//  L6Q1
//
//  Created by Andrew on 2019-03-04.
//  Copyright © 2019 ICS214. All rights reserved.
//

#include "Tetromino.h"
#include "Point.h"
#include <iostream>

TetShape Tetromino::getRandomShape() {
	int tetItem = rand() % static_cast<int>(TetShape::TetshapeCount);
	return static_cast<TetShape>(tetItem);
}

Tetromino::Tetromino() 
{
	setShape(TetShape::SHAPE_S);
}

TetColor Tetromino::getColor()
{
	return color;
}

TetShape Tetromino::getShape()
{
	return shape;
}

// set the shape     
//  - clear any blockLocs set previously     
//  - set the blockLocs for the shape     
//  - set the color for the shape
void Tetromino::setShape(TetShape shape)
{
	blockLocs.empty();
	switch (shape) {
		case TetShape::SHAPE_S:
			blockLocs = { Point(0,0), Point(-1,0), Point(0,1), Point(1,1) };
			color = TetColor::RED;
			break;
		case TetShape::SHAPE_Z:
			blockLocs = { Point(0,0), Point(1,0), Point(0,1), Point(-1,1) };
			color = TetColor::GREEN;
			break;
		case TetShape::SHAPE_L:
			blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(1,1) };
			color = TetColor::ORANGE;
			break;
		case TetShape::SHAPE_J:
			blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(-1,1) };
			color = TetColor::BLUE_DARK;
			break;
		case TetShape::SHAPE_O:
			blockLocs = { Point(0,0), Point(0,1), Point(1,1), Point(1,0) };
			color = TetColor::YELLOW;
			break;
		case TetShape::SHAPE_I:
			blockLocs = { Point(0,0), Point(0,2), Point(0,1), Point(0,-1) };
			color = TetColor::BLUE_LIGHT;
			break;
		case TetShape::SHAPE_T:
			blockLocs = { Point(0,0), Point(-1,0), Point(1,0), Point(0,-1) };
			color = TetColor::PURPLE;
			break;

	}
}

// rotate the shape 90 degrees around [0,0] (clockwise)     
// to do this:     
//  - iterate through blockLocs     
//  - rotate each Point 90 degrees around [0,0]     
// hint: rotate the point [1,2] clockwise around [0,0] and note     
// how the x,y values change. There are 2 functions in the Point     
// class that can be used to accomplish a rotation.   
void Tetromino::rotateCW() 
{
	for (int i = 0; i < blockLocs.size(); i++) 
	
	{
		blockLocs[i].swapXY();
		blockLocs[i].multiplyY(-1);
	}
}

// print a grid to display the current shape     
// to do this:     
// print out a “grid” of text to represent a co-ordinate     
// system.  Start at top left [-3,3] go to bottom right [3,-3]     
// (use nested for loops)     
//  for each [x,y] point, loop through the blockLocs and if    
//  the point exists in the list, print an 'x' instead of a '.'     
// You should end up with something like this:     
// (results will vary depending on shape and rotation, eg: this     
//  one shows a T shape rotated clockwise once)     
//  .......     
//  .......     
//  ...x...     
//  ..xx...     
//  ...x...     
//  ....... 
void Tetromino::printToConsole()
{
	for (int x = -3; x < 3; x++) {
		for (int y = 3; y > -3; y--) {
			bool found = false;
			for (int i = 0; i < blockLocs.size(); i++) {
				if (blockLocs[i].getX() == x && blockLocs[i].getY() == y) {
					std::cout << "x";
					found = true;
					break;
				}
			}
			if (!found) {
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
}