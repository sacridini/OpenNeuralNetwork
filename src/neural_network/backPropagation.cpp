#include "../../include/NeuralNetwork.hpp"
#include "../../include/utils/Math.hpp"

void NeuralNetwork::backPropagation() {
    vector<Matrix *> newWeights;
    Matrix *deltaWeights;
    Matrix *gradients;
    Matrix *derivedValues;
    Matrix *gradientsTransposed;
    Matrix *zActivatedVals;
    Matrix *tempNewWeights;
    Matrix *pGradients;
    Matrix *transposedPWeights;
    Matrix *hiddenDerived;

    /**
     * PART 1: OUTPUT TO LAST HIDDEN LAYER
     */
    int indexOutputLayer = this->topology.at(this->topology.size() - 1);
    
    deltaWeights = new Matrix(this->weightMatrices.at(indexOutputLayer - 1)->getNumRows(),
                                      this->weightMatrices.at(indexOutputLayer - 1)->getNumCols(),
                                      false
    );
    
    gradients = new Matrix(1, this->topology.at(indexOutputLayer), false);

    derivedValues = this->layers.at(indexOutputLayer)->matrixifyDerivedVals();

    for (int i = 0; i < topology.at(indexOutputLayer); i++) {
        double e = this->derivedErrors.at(i);
        double y = this->derivedValues->getValue(0, i);
        double g = e * y;
        gradients->setValue(0, i, g);
    }

    // Gt * Z
    gradientsTransposed  = gradients->transpose();
    zActivatedVals       = this->layers.at(indexOutputLayer - 1)->matrixifyActivatedVals();
    utils::Math::multiplyMatrix(gradientsTransposed, zActivatedVals, deltaWeights);


    // COMPUTE FOR NEW WEIGHTS (LAST HIDDEN <--> OUTPUT)
    // -------------------------------------------------------------------    
    tempNewWeights = new Matrix(
        this->topology.at(indexOutputLayer - 1),
        this->topology.at(indexOutputLayer),
        false
    );

    // Set values form tempNewWeights
    for (int r = 0; r < this->topology.at(indexOutputLayer - 1); r++) {
        for (int c = 0; c < topology.at(indexOutputLayer); c++) {
            double originalValue            = this->weightMatrices.at(indexOutputLayer - 1)->getValue(r, c);
            double deltaValue               = this->deltaWeights.getValue(r, c);
            
            originalValue           = this->momentum * originalValue;
            deltaValue              = this->learningRate * deltaValue;  

            tempNewWeights ->setValue(r, c, (originalValue - deltaValue));
        }
    }
 
    newWeights.push_back(new Matrix(*tempNewWeights));
    // -------------------------------------------------------------------

    /**
     * PART 2: LAST HIDDEN LAYER TO INPUT LAYER
     */

    for (int i = (indexOutputLayer - 1); i > 0; i--) {
        pGradients = new Matrix(gradients);
        gradients = new Matrix(1, this->topology.at(i), false);
        
        transposedPWeights      = this->weightMatrices.at(i)->transpose(); 
        utils::Math::multiplyMatrix(pGradients, transposedPWeights, gradients);
        hiddenDerived           = this->layers.at(i)->matrixifyDerivedVals(); 

        for (int colCounter = 0; colCounter < hiddenDerived->getNumRows(); colCounter++) {
            double g = gradients->getValue(0, colCounter) * hiddenDerived->getValue(0, colCounter);
            gradients->setValue(0, colCounter, g);
        }
    }

    delete hiddenDerived;
    delete transposedPWeights;
    delete pGradients;
    delete gradients;
}