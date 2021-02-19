// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

/**
 * @brief the matrix class
 */
class Matrix
{
public:
    /**
    * @brief a constructor
    * @param rows the number of rows
    * @param cols number of columns
    * @return the matrix
    */
    Matrix(int rows, int cols);
    /**
     * @brief the default constructor
     */
    Matrix(): Matrix(1, 1) {};
    /**
     * @brief Constructs matrix from another Matrix m
     * @param m the matrix to copy
     */
    Matrix(const Matrix &m);
    /**
     * @brief destructs the matrix
     */
    ~Matrix();
    /**
     * @brief the number of rows getter
     * @return the number of rows
     */
    [[nodiscard]] int getRows() const{    return _dim.rows; }
    /**
     * @brief the number of columns getter
     * @return the number of columns
     */
    [[nodiscard]] int getCols() const{    return _dim.cols; }
    /**
     * @brief turns the matrix into a vector
     * @return itself
     */
    Matrix vectorize();
    /**
     * @brief Prints matrix elements, no return value, prints space after each element
     */
    void plainPrint() const;
    /**
     * @brief overloads the '=' operator
     * @param obj the matrix to copy
     * @return the matrix with the new values
     */
    Matrix& operator =(const Matrix &obj);
    /**
    * @brief defines multiplication of 2 matrice's
    * @param obj the matrix to multiply by
    * @return a new matrix
    */
    Matrix operator *(const Matrix &obj) const;
    /**
     * @brief defines multiplying a matrix with a number
     * @param scalar the number
     * @return the new matrix
     */
    Matrix operator *(const float scalar);
    /**
     * @brief defines multiplying a number with a matrix
     * @param scalar the number
     * @param obj the matrix
     * @return a new matrix
     */
    friend Matrix operator*(const float scalar, Matrix &obj);
    /**
     * @brief redefines entering  matrix by index
     * @param index the index
     * @return the value in the matrix index
     */
    float& operator[](int index) const;
    /**
     * @brief gets a constant matrix's value by index
     * @param row the row to look for
     * @param col the column to look for
     * @return the vlue
     */
    float& operator()(const int row, const int col);
    /**
     * @brief gets a matrix's value by index
     * @param row the row to look for
     * @param col the column to look for
     * @return the vlue
     */
    const float& operator()(const int row, const int col) const;
    /**
     * @brief redifines adding 2 matrice's
     * @param matrix the matrix to add
     * @return a new matrix
     */
    Matrix operator +(const Matrix& matrix) const;
    /**
     * @brief redifines adding to a matrix
     * @param matrix the matrix added
     * @return the matrix after adding
     */
    Matrix operator +=(const Matrix& matrix);
    /**
     * @brief redefines the out stream
     * @param output the stream
     * @param matrix the matrix to output
     * @return the output stream
     */
    friend ostream & operator<<(ostream &output, Matrix& matrix) ;
    /**
     * @brief redefines the input stream
     * @param input the input stream
     * @param matrix the matrix to input to
     * @return the input stream
     */
    friend istream &operator>>( istream  &input, Matrix &matrix);


private:
    // the array containing the matrix's values
    float *_vector;
    // the struct containing the dimensions
    MatrixDims _dim;
};
#endif //MATRIX_H
