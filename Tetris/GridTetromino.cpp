
#include "GridTetromino.h"
#include "Point.h"
#include <vector>

GridTetromino::GridTetromino() {
	gridLoc.setXY(0, 0);
}
// constructor, initialize gridLoc to 0,0

Point GridTetromino::getGridLoc() const {
	return gridLoc;
}	
// return the tetromino's grid/gameboard loc (x,y)

void GridTetromino::setGridLoc(int x, int y) {
	gridLoc.setXY(x, y);
}	
// sets the tetromino's grid/gameboard loc using x,y

void GridTetromino::setGridLoc(const Point& pt) {
	gridLoc.setXY(pt.getX(), pt.getY());
}		
// sets the tetromino's grid/gameboard loc using a Point

// transpose the gridLoc of this shape
//	(1,0) represents a move to the right (x+1)
//	(-1,0) represents a move to the left (x-1)
//	(0,1) represents a move down (y+1)

void GridTetromino::move(int xOffset, int yOffset) {
	gridLoc.setXY(gridLoc.getX() + xOffset, gridLoc.getY() + yOffset);
}

// build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {
	std::vector<Point> v;
	for (unsigned int i = 0; i < blockLocs.size(); i++) {
		v.push_back(Point(blockLocs[i].getX() + gridLoc.getX(), blockLocs[i].getY() + gridLoc.getY()));
	}
	return v;
}
