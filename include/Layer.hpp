#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <iostream>
#include <vector>
#include "Neuron.hpp"
#include "Matrix.hpp"

using namespace std;

class Layer {
public:
    Layer(int size);
    Layer(int size, int activationType);

    // Setter
    void setVal(int i, double v);
    void setNeuron(vector<Neuron *> neurons) { this->neurons = neurons; }

    // Getters
    vector<double> getActivatedVals();
    vector<Neuron *> getNeurons() { return this->neurons; }

    Matrix *matrixifyVals();
    Matrix *matrixifyActivatedVals();
    Matrix *matrixifyDerivedVals();

private:
    int size;
    vector<Neuron *> neurons;
};

#endif