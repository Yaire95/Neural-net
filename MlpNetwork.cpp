/** @file MlpNetwork.cpp
* @author  Yair Escott <yair.95@gmail.com>
*
* @brief the neural network
*/

// ------------------------------ includes ------------------------------

#include "MlpNetwork.h"
using namespace std;
// ------------------------------ functions -----------------------------

/**
 * @brief the MlpNetwork constructor
 * @param weights the array of weights
 * @param biases the array of biases
 */
MlpNetwork::MlpNetwork(Matrix weights[], Matrix biases[]): _ri(28, 28)
{
    _w1 = weights[0];
    _w2 = weights[1];
    _w3 = weights[2];
    _w4 = weights[3];
    _b1 = biases[0];
    _b2 = biases[1];
    _b3 = biases[2];
    _b4 = biases[3];
}

/**
 * @brief applying the netork on the matrix representing the image
 * @param matrix the matrix
 * @return a Digit which contains the number most probable and its probability
 */
Digit MlpNetwork::operator()(Matrix matrix)
{
    Dense D1(_w1, _b1, Relu);
    _ri = D1(matrix);

    Dense D2(_w2, _b2, Relu);
    _ri = D2(_ri);

    Dense D3(_w3, _b3, Relu);
    _ri = D3(_ri);

    Dense D4(_w4, _b4, Softmax);
    _ri = D4(_ri);

    int digit = 0;
    float probability = 0;
    for(int i = 0; i < 10; i++)
    {
        if(_ri[i] >= probability)
        {
            probability = _ri[i];
            digit = i;
        }
    }
    Digit final;
    final.probability = probability;
    final.value = digit;
    return final;
}
