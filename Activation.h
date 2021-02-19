//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H
#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

/**
 * @brief the activation class
 */
class Activation
{
public:
    /**
     * @brief the Activation constructor
     * @param actType the activation type
     */
    explicit Activation(ActivationType actType);
    /**
     * @brief activating oni a matrix
     * @param matrix the matrix
     * @return the matrix after activation
     */
    Matrix operator()(Matrix matrix) const;
    /**
     * @brief the activation type getter
     * @return the activation type
     */
    [[nodiscard]] ActivationType getActivationType() const{    return _act; }

private:
    // stors the activation type
    ActivationType _act;
    // a private function preforms the Relu operation
    Matrix _reluActivate(Matrix& matrix) const ;
    // a private function preforms the softmax operation
    Matrix _softMaxActivate(Matrix& matrix) const ;

};

#endif //ACTIVATION_H