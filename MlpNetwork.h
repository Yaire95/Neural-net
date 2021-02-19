//MlpNetwork.h
#ifndef MLPNETWORK_H
#define MLPNETWORK_H
#include "Dense.h"
#include "Digit.h"
#include "Matrix.h"
#include "Activation.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64},
                                  {10, 20}};
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},
                                  {10, 1}};

/**
 * @brief the class MlpNetwork
 */
class MlpNetwork
{
public:
    /**
     * @brief the MlpNetwork constructor
     * @param weights the array of weights
     * @param biases the array of biases
     */
    MlpNetwork(Matrix weights[], Matrix biases[]);
    /**
     * @brief applying the netork on the matrix representing the image
     * @param matrix the matrix
     * @return a Digit which contains the number most probable and its probability
     */
    Digit operator()(Matrix matrix);

private:
    // weights 1 to 4
    Matrix _w1;
    Matrix _w2;
    Matrix _w3;
    Matrix _w4;

    // biases 1 to 4
    Matrix _b1;
    Matrix _b2;
    Matrix _b3;
    Matrix _b4;
    // holds the matrix
    Matrix _ri;
};
#endif // MLPNETWORK_H
