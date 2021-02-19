/** @file Dense.cpp
* @author  Yair Escott <yair.95@gmail.com>
*
* @brief A layer in the neural network
*/

// ------------------------------ includes ------------------------------

#include "Dense.h"

// -------------------------- const definitions -------------------------

using namespace std;

// ------------------------------ functions -----------------------------

/**
 * @brief applying the layer on the matrix
 * @param matrix the matrix
 * @return the matrix after activating
 */
Matrix Dense::operator()(const Matrix &matrix) const
{
    return getActivation()((this->getWeights() * matrix) + this->getBias());
}
