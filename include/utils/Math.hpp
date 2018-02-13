#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cmath>
#include "../Matrix.hpp"

using namespace std;

namespace utils {
    class Math {
    public:
        static void multiplyMatrix(Matrix *a, Matrix *b, Matrix *c);
    private:
    };
}

#endif