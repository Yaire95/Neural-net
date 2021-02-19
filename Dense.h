#ifndef EX4_DENSE_H
#define EX4_DENSE_H
#include "Activation.h"
#include "Matrix.h"

/**
 * @brief the Dense class
 */
class Dense
{
public:
    /**
     * @brief the Dense constructor
     * @param w a weight
     * @param bias a bias
     * @param act the activation type
     */
    Dense(Matrix& w, Matrix& bias, ActivationType act):_activation(act), _bias(bias), _weight(w){};
    /**
     * @brief the weight getter
     * @return the weight
     */
    Matrix& getWeights() const{    return this->_weight; }
    /**
     * @brief the bias getter
     * @return the bias
     */
    Matrix& getBias() const{    return this->_bias; }
    /**
     * @brief the actiivation getter
     * @return the activation
     */
    Activation getActivation() const{    return this->_activation; }
    /**
    ` * @brief applying the layer on the matrix
     * @param matrix the matrix
     * @return the matrix after activating
     */
    Matrix operator()(const Matrix& matrix) const;

private:
    // stores the activation
    Activation _activation;
    // stores the bias
    Matrix& _bias;
    // stores the weight
    Matrix& _weight;


};
#endif //EX4_DENSE_H

