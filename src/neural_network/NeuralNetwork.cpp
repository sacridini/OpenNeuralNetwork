#include "../../include/NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(
    vector<int> topology,
    double bias,
    double learningRate,
    double momentum
) {
    this->topology      = topology;
    this->topologySize  = topology.size();
    this->learningRate  = learningRate;
    this->momentum      = momentum;
    this->bias          = bias;

  for (int i = 0; i < topologySize; i++) {
    if (i > 0 && i < (topologySize - 1)) {
      this->layers.push_back(new Layer(topology.at(i), this->hiddenActivationType));
    } else if (i == (topologySize - 1)) {
      this->layers.push_back(new Layer(topology.at(i), this->outputActivationType));
    } else {
      this->layers.push_back(new Layer(topology.at(i)));
    }
  }

    for (int i = 0; i < (topologySize - 1); i++) {
        Matrix *weightMatrix = new Matrix(topology.at(i), topology.at(i + 1), true);
        this->weightMatrices.push_back(weightMatrix);
    }

    for (int i = 0; i < topology.at(topologySize - 1); i++) {
        errors.push_back(0.00);
        derivedErrors.push_back(0.00);        
    }

    this->error = 0.00;
}

NeuralNetwork::NeuralNetwork(
    vector<int> topology,
    int hiddenActivationType,
    int outputActivationType,
    int costFunctionType,
    double bias,
    double learningRate,
    double momentum
) {
    this->topology      = topology;
    this->topologySize  = topology.size();
    this->learningRate  = learningRate;
    this->momentum      = momentum;
    this->bias          = bias;
    this->hiddenActivationType      = hiddenActivationType;
    this->outputActivationType      = outputActivationType;
    this->costFunctionType          = costFunctionType;

  for (int i = 0; i < topologySize; i++) {
    if (i > 0 && i < (topologySize - 1)) {
      Layer *l  = new Layer(topology.at(i), this->hiddenActivationType);
      this->layers.push_back(l);
    } else if (i == (topologySize - 1)) {
      Layer *l  = new Layer(topology.at(i), this->outputActivationType);
      this->layers.push_back(l);
    } else {
      Layer *l  = new Layer(topology.at(i));
      this->layers.push_back(l);
    }
  }

    for (int i = 0; i < (topologySize - 1); i++) {
        Matrix *weightMatrix = new Matrix(topology.at(i), topology.at(i + 1), true);
        this->weightMatrices.push_back(weightMatrix);
    }

    for (int i = 0; i < topology.at(topologySize - 1); i++) {
        errors.push_back(0.00);
        derivedErrors.push_back(0.00);
    }

    this->error = 0.00;
}

void NeuralNetwork::setCurrentInput(vector<double> input) {
   this->input = input;

   for (int i = 0; i < input.size(); i++) {
       this->layers.at(0)->setVal(i, input.at(i));
   }
}

