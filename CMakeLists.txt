cmake_minimum_required(VERSION 3.0)
project(openANN)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++14")

add_executable(
    openANN
    src/main.cpp
    src/Neuron.cpp
    src/Matrix.cpp
    src/Layer.cpp
    src/neural_network/NeuralNetwork.cpp
    src/utils/Math.cpp
)


