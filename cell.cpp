#include "cellgrid.h"
#include <iostream>
#include <fstream>
using namespace std;

// reads a file containing 1's and 0's and the dimesnsions to expect and
// creates a Cellgrid object
Cellgrid::Cellgrid(const char *fname, int m, int n) {
    // assign row and col counters
    rows = m;
    cols = n;

    // create the grid on the heap, this will have to be deallocated later in
    // the destructor
    grid = new bool[rows*cols];

    // create a file reader stream to read data from a file
    ifstream infile;

    // open a stream to the given file
    infile.open(fname);

    // we are using row-major order in order to store this grid in 1D
    // instead of accessing grid like grid[a][b], we instead do:
    // grid[(a * number of columns) + b]
    for(int i = 0; i < rows; i++) {
        // calculate "(a * number of columns)" from above
        // in order to save some unnecessary computation
        int base = i * cols;
        for(int offset = 0; offset < cols; offset++) {
            // read data from filestream and store it in grid
            infile >> grid[base + offset];
        }
    }

    // close the filestream once we are done with it
    infile.close();
}

// destruct object where not implicit to the program
Cellgrid::~Cellgrid() {
    // since we allocated memory on the heap, we must deallocate that memory
    delete[] grid;
}

// this is the function call which will be made by the autograder to test
// your implementation for problem 1. (row, col) is the "start point" for
// counting the cells, conn is the type of connection to consider (4 or 8).
int Cellgrid::countCells(int row, int col, int conn) {
    // TODO:
    // implement solution for problem 1.

    // this is where your private helper method which does the
    // backtracking should be called

    // this will prevent a compiler error but should be changed
    // to return the cell count you have found
    bool *checked = new bool[this->rows * this->cols] {false};
    int cellCount = _countCells(row - 1, col - 1, conn, checked);

    return cellCount;
    // WORKS
}

int Cellgrid::_countCells(int row, int col, int conn, bool *checked) {
    if (grid[(this->cols * row) + col] == 0) {
        checked[(this->cols * row) + col] = true;
        return 0;
    }
    else if (checked[(this->cols * row) + col] == false) {
        checked[(this->cols * row) + col] = true;

        int number = 1;
        if (row > 0) {
            number += _countCells(row - 1, col, conn, checked);
        }
        if (row < this->rows - 1) {
            number += _countCells(row + 1, col, conn, checked);
        }
        if (col > 0) {
            number += _countCells(row, col - 1, conn, checked);
        }
        if (col < this->cols - 1) {
            number += _countCells(row, col + 1, conn, checked);
        }

        if (conn == 8) {
            if (row > 0) {
                if (col > 0) {
                    number += _countCells(row - 1, col - 1, conn, checked);
                }
                if (col < this->cols - 1) {
                    number += _countCells(row - 1, col + 1, conn, checked);
                }
            }
            if (row < this->rows - 1) {
                if (col > 0) {
                    number += _countCells(row + 1, col - 1, conn, checked);
                }
                if (col < this->cols - 1) {
                    number += _countCells(row + 1, col + 1, conn, checked);
                }
            }
        }

        return number;
    }
    else {
        return 0;
    }
}

// this is the funciton call which will be made by the autograder to test
// your implementation for problem 2. conn is the type of connection
// to consider (4 or 8).
int Cellgrid::countBlobs(int conn) {
    //TODO:
    // implement solution for problem 2

    // this is where your private helper method which does the
    // backtracking should be called

    // this will prevent compiler error but should be changed
    // to return the blob count which you have found using
    // your helper function
    bool *checked = new bool[this->rows * this->cols] {false};
    return _countBlobs(0, conn, checked);

    // WORKS
}

int Cellgrid::_countBlobs(int idx, int conn, bool *checked) {
    if (idx >= (this->rows * this->cols)) {
        return 0;
    }
    if (!checked[idx]) {
        if (this->grid[idx] == 0) {
            checked[idx] = true;
            return 0 + _countBlobs(idx + 1, conn, checked);
        }
        else {
            int col = idx % 9;
            int row = (idx - col) / 9;
            int cellsInBlob = _countCells(row, col, conn, checked);
            return 1 + _countBlobs(idx + 1, conn, checked);
        }
    }
    else {
        return 0 + _countBlobs(idx + 1, conn, checked);
    }
}

// this function prints your cellgrid in 2D format without trailing
// whitespace. Use this function to aid in debugging if you wish
void Cellgrid::print() {
    for(int i = 0; i < rows; i++) {
        int base = i * cols;
        std::cout << grid[base];
        for(int offset = 1; offset < cols; offset++) {
            std::cout << ' ' << grid[base + offset];
        }
        std::cout << std::endl;
    }
}

// WORKS