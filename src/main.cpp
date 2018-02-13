#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <ostream>
#include <streambuf>
#include <ctime> 

#include "../include/Matrix.hpp"
#include "../include/utils/Math.hpp"
#include "../include/NeuralNetwork.hpp"

using namespace std;

int main(int argc, char **argv) {
       // Segundo teste:
        vector<double> input;
        input.push_back(0.2);
        input.push_back(0.5);
        input.push_back(0.1);
       
        vector<double> target;
        target.push_back(0.2); 
        target.push_back(0.5); 
        target.push_back(0.1);
    
        double learningRate  = 0.05;
        double momentum      = 1;
        double bias          = 1;

        vector<int> topology;
        topology.push_back(650);
        topology.push_back(213);
        topology.push_back(650);

        NeuralNetwork *n = new NeuralNetwork(topology, 2, 3, 1, 1, 0.05, 1);

        for (int i = 0; i < 1000; i++) {
            // cout << "Training at index " << i << endl;
            n->train(input, target, bias, learningRate, momentum);
            cout << "Error: " << n->error << endl;
        }
       // Primeiro teste:
/*     for (int i = 0; i < 100; i++) {
        Matrix *a = new Matrix(100, 100, true);
        Matrix *b = new Matrix(100, 100, true);
        Matrix *c = new Matrix(a->getNumRows(), b->getNumRows(), false);
        cout << "Multiplying matrix at index " << i << endl;
        utils::Math::multiplyMatrix(a, b, c);

        delete a;
        delete b;
        delete c;
    } */

    return 0;
}