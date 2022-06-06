#ifndef _CELLGRID_H_
#define _CELLGRID_H_

class Cellgrid {
private:
// dimensions of the grid, think rowCount, columnCount
int rows, cols;
// grid will store the actual grid in 1D space
bool *grid;
public:
/* Class constructors and destructors */
// class constructor using a file
Cellgrid(const char *fname, int m, int n);
// class destructor
~Cellgrid();
/* Member functions */
// count the number of cells in grid
int countCells(int row, int col, int conn);
// counts the number of blobs in grid
int countBlobs(int conn);
// prints the Cellgrid in 2D format
void print();
};
#endif