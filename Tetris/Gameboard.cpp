

#include "Gameboard.h"
#include "Point.h"
#include <iostream>
#include <iomanip>
using namespace std;



// constructor - empty() the grid
Gameboard::Gameboard() {
	empty();
}

// return the content at a given point
int Gameboard::getContent(Point pt) const {
	return grid[pt.getX()][pt.getY()];
}

// return the content at an x,y grid loc
int Gameboard::getContent(int x, int y) const {
	return grid[x][y];
}

// set the content at a given point
void Gameboard::setContent(Point pt, int content) {
	grid[pt.getX()][pt.getY()] = content;
}

// set the content at an x,y grid loc
void Gameboard::setContent(int x, int y, int content) {
	grid[x][y] = content;
}

// set the content for an array of grid locs
void Gameboard::setContent(std::vector<Point> locs, int content) {
	for (unsigned int i = 0; i < locs.size(); i++) {
		grid[locs[i].getX()][locs[i].getY()] = content;
	}
}	

// return true if the content at all the locs specified is empty
//   IMPORTANT NOTE: invalid x,y values can be passed to this method.
//   Invalid meaning: outside the bounds of the grid.
//   * Only test valid points (disregard the others - and ensure you
//   don't use them to index into the grid).  Testing invalid points
//   would likely result in an out of bounds error or segmentation fault!
bool Gameboard::areLocsEmpty(std::vector<Point> locs) const {
	for (unsigned int i = 0; i < locs.size(); i++) {
		int x = locs[i].getX();
		int y = locs[i].getY();
		if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y) {
			if (grid[x][y] != EMPTY_BLOCK) {
				return false;
			}
		}
	}
	return true;
}

// removes all completed rows from the board
//   use getCompletedRowIndices() and removeRows() 
//   return the # of completed rows removed
int Gameboard::removeCompletedRows() {
	std::vector<int> rowsToRemove = getCompletedRowIndices();
	for (unsigned int i = 0; i < rowsToRemove.size(); i++) {
		removeRow(rowsToRemove[i]);
	}
	return rowsToRemove.size();
}

// fill the board with EMPTY_BLOCK 
//   (iterate through each rowIndex and fillRow() with EMPTY_BLOCK))
void Gameboard::empty() {
	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			grid[x][y] = EMPTY_BLOCK;
		}
	}
}
											
Point Gameboard::getSpawnLoc() const {
	return spawnLoc;
}

// print the grid contents to the console (for debugging purposes)
// use setw(2) to space the contents out.
// getter for the spawnLoc for new blocks
void Gameboard::printToConsole() const {
	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			cout << setw(2) << (grid[x][y]);
		}
		std::cout << std::endl;
	}
}


///// PRIVATE FXS ////


// return a bool indicating if a given row is full (no EMPTY_BLOCK in the row)
bool Gameboard::isRowCompleted(int rowIndex) const {
	for (int x = 0; x < MAX_X; x++) {
		if (grid[x][rowIndex] == EMPTY_BLOCK) {
			return false;
		}
	}
	return true;
}	
	

// scan the board for completed rows.
//   Iterate through grid rows and use isRowCompleted(rowIndex)
//   return a vector of completed row indices.
std::vector<int> Gameboard::getCompletedRowIndices() const {
	std::vector<int> rows;
	for (int i = 0; i < MAX_Y; i++) {
		if (isRowCompleted(i)) {
			rows.push_back(i);
		}
	}
	return rows;
}
	
// In gameplay, when a full row is completed (filled with content)
// it gets "removed".  To be exact, the row itself is not removed
// but the content from the row above it is copied into it.
// This continues all the way up the grid until the first row
// is copied into the second row.  Finally, the first row is 
// filled with EMPTY_BLOCK
// given a row index:
//   1) Starting at rowIndex, copy each row above the removed
//     row "one-row-downwards" in the grid.
//     (loop from y=rowIndex to 0, and copyRowIntoRow(y-1, y)).
//   2) call fillRow() on the first row (and place EMPTY_BLOCKs in it).
void Gameboard::removeRow(int rowIndex) {
	for (int i = rowIndex; i > 0; i--) {
		copyRowIntoRow(i - 1, i);
	}
	fillRow(0, EMPTY_BLOCK);
}


// given a vector of row indices, remove them 
//   (iterate through the vector and and call removeRow()
//   on each row index).  
void Gameboard::removeRows(std::vector<int> rowIndices) {
	for (unsigned int i = 0; i < rowIndices.size(); i++) {
		removeRow(rowIndices[i]);
	}
}

// fill a given grid row with specified content
void Gameboard::fillRow(int rowIndex, int content) {
	for (int i = 0; i < MAX_X; i++) {
		grid[i][rowIndex] = content;
	}
}


// copy a source row's contents into a target row.
void Gameboard::copyRowIntoRow(int sourceRowIndex, int targetRowIndex) {
	for (int i = 0; i < MAX_X; i++) {
		grid[i][targetRowIndex] = grid[i][sourceRowIndex];
	}
}