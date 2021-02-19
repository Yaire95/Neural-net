/** @file Activation.cpp
* @author  Yair Escott <yair.95@gmail.com>
*
* @brief Activation the neural network
*/

// ------------------------------ includes ------------------------------

#include "Activation.h"
#include <cmath>

// -------------------------- const definitions -------------------------

using namespace std;

// ------------------------------ functions -----------------------------

/**
 * @brief the Activation constructor
 * @param actType the activation type
 */
Activation::Activation(ActivationType actType)
{
    this->_act = actType;
}

/**
 * @brief activating oni a matrix
 * @param matrix the matrix
 * @return the matrix after activation
 */
Matrix Activation::operator()(Matrix matrix) const
{
    if(getActivationType() == Relu)
    {
        return _reluActivate(matrix);
    }
    else
    {
        return _softMaxActivate(matrix);
    }
}

/**
 * @brief activates the Relu function
 * @param matrix the matrix to activate it on
 */
Matrix Activation::_reluActivate(Matrix &matrix) const
{
    for(int i = 0; i < matrix.getRows(); i++)
    {
        for(int j = 0; j < matrix.getCols(); j++)
        {
            if(matrix(i, j) < 0)
            {
                matrix(i, j) = 0;
            }
        }
    }
    return matrix;
}

/**
 * @brief activates the Softmax function
 * @param matrix the matrix to activate it on
 */
Matrix Activation::_softMaxActivate(Matrix &matrix) const
{
    float devider = 0;
    for(int i = 0; i < matrix.getRows(); i++)
    {
        for(int j = 0; j < matrix.getCols(); j++)
        {
            devider += exp(matrix(i, j));
        }
    }
    float finalFraction = 1 / devider;
    for(int k = 0; k < matrix.getRows(); k++)
    {
        for(int l = 0; l < matrix.getCols(); l++)
        {
            matrix(k, l) = finalFraction * (exp(matrix(k, l)));
        }
    }
    return matrix;
}