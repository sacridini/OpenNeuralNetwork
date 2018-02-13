#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

class Matrix {
public:
    Matrix(int numRows, int numCols, bool isRandom);
    Matrix *transpose();
    Matrix *copy();

    // Debug
    void printToConsole();

    // Setter
    void setValue(int r, int c, double v) { this->values.at(r).at(c) = v; }    

    // Getters
    int getNumRows() { return this->numRows; };
    int getNumCols() { return this->numCols; };
    double getValue(int r, int c) { return this->values.at(r).at(c); }

private:
    int numRows;
    int numCols;
    vector< vector<double> > values;
    double generateRandomNumber();
};

#endif