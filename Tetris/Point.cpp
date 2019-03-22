//
//  Point.cpp
//  L6Q1
//
//  Created by Andrew on 2019-03-04.
//  Copyright © 2019 ICS214. All rights reserved.
//

#include "Point.h"
#include <string>
using namespace std;

Point::Point() 
{
	x = y = 0;
}

Point::Point(int newX, int newY) 
{
	x = newX;
	y = newY;
}

int Point::getX() const 
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(int newX)
{
	x = newX;
}

void Point::setY(int newY)
{
	y = newY;
}

void Point::setXY(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Point::swapXY()
{
	int temp = x;
	x = y;
	y = temp;
}

void Point::multiplyX(int factor)
{
	x *= factor;
}

void Point::multiplyY(int factor)
{
	y *= factor;
}

string Point::toString() const
{
	string str = "[" + to_string(x) + "," + to_string(y) + "]";
	return str;
}
// return a string in the form "[x,y]" to represent
// the state of the Point instance (for debugging)
