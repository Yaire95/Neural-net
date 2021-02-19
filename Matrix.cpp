/** @file Matrix.cpp
* @author  Yair Escott <yair.95@gmail.com>
*
* @brief implementing Matrix
*/

// ------------------------------ includes ------------------------------

#include "Matrix.h"
#include <iostream>
using namespace std;
// -------------------------- const definitions -------------------------

#define CONSTRUCTORBADARGS "Error: bad arguments in constructor"
#define INDEXBADARGSQUARE "Error: the index is out of range"
#define INDEXBADARGS "Error: one of the index's is a negative number"
#define INPUTFAIL "Error: the input is flawed"
#define INPUTNOTSUFICE "Error: not enough numbers have been entered"
#define ADDITIONNOTCOMPATIBLE "Error: the matrices are not compatible for addition"
#define MULTIPLICATIONNOTCOMPATIBLE "Error: the matrices are not compatible for multiplication"


// ------------------------------ functions -----------------------------

/**
* @brief a constructor
* @param rows the number of rows
* @param cols number of columns
* @return the matrix
*/
Matrix::Matrix(int rows, int cols)
{
    if(rows > 0 && cols > 0)
    {
        _vector = new float[rows * cols] ();
        _dim.rows = rows;
        _dim.cols = cols;
    }
    else
    {
        cerr << CONSTRUCTORBADARGS << endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Constructs matrix from another Matrix m
 * @param m the matrix to copy
 */
Matrix::Matrix(const Matrix &m)
{
    _vector = new float[m.getRows() * m.getCols()] ();
    _dim.cols = m.getCols();
    _dim.rows = m.getRows();
    for(int i = 0; i < m.getRows() * m.getCols() ; i++)
    {
        this->operator[](i) = m[i];
    }
}

/**
 * @brief destructs the matrix
 */
Matrix:: ~Matrix()
{
    delete [] _vector;
}

/**
 * @brief turns the matrix into a vector
 * @return itself
 */
Matrix Matrix::vectorize()
{
    this->_dim.rows = this->_dim.rows * this->_dim.cols;
    this->_dim.cols = 1;
    return *this;
}

/**
 * @brief Prints matrix elements, no return value, prints space after each element
 */
void Matrix::plainPrint() const
{
    for (int i = 0; i < this->getRows(); i++)
    {
        for(int j = 0; j < this->getCols(); j++)
        {
            cout << this->operator[](i * this->getCols() + j) << " ";
        }
        cout << "\n";
    }
}

/**
 * @brief overloads the '=' operator
 * @param obj the matrix to copy
 * @return the matrix with the new values
 */
Matrix& Matrix::operator =(const Matrix &obj)
{
    if(this == &obj)
    {
        return *this;
    }
    else
    {
        _dim.rows = obj._dim.rows;
        _dim.cols = obj._dim.cols;
        _vector = new float[getRows() * getCols()]();
        for (int i = 0; i < obj.getCols()* obj.getRows(); i++)
        {
            _vector[i] = obj._vector[i];
        }
    }
    return *this;
}

/**
 * @brief defines multiplication of 2 matrice's
 * @param obj the matrix to multiply by
 * @return a new matrix
 */
Matrix Matrix::operator *(const Matrix &obj) const
{
    if(this->getCols() != obj.getRows())
    {
        cerr << MULTIPLICATIONNOTCOMPATIBLE << endl;
        exit(EXIT_FAILURE);
    }
    Matrix newOne = Matrix(getRows(), obj.getCols());
    for(int i = 0; i < this->getRows(); i++)
    {
        for(int j = 0; j < obj.getCols(); j++)
        {
            newOne(i, j) = 0;
            for(int k = 0; k < this->getCols(); k++)
            {
                newOne(i, j) += (this->operator()(i, k) * obj(k, j));
            }
        }
    }
    return newOne;
}

/**
 * @brief defines multiplying a matrix with a number
 * @param scalar the number
 * @return the new matrix
 */
Matrix Matrix::operator *(const float scalar)
{
    Matrix newOne = Matrix(getRows(), getCols());
    for(int k = 0; k < getCols() * getRows(); k++)
    {
        newOne._vector[k] = _vector[k] * scalar;
    }
    return newOne;
}

/**
 * @brief defines multiplying a number with a matrix
 * @param scalar the number
 * @param obj the matrix
 * @return a new matrix
 */
Matrix operator *(const float scalar, Matrix &obj)
{
    return obj*scalar;
}

/**
 * @brief redefines entering  matrix by index
 * @param index the index
 * @return the value in the matrix index
 */
float& Matrix::operator[](int index) const
{
    if(index < 0 || index >= (this->getCols() * this->getRows()))
    {
        cerr << INDEXBADARGSQUARE << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        return this->_vector[index];
    }
}

/**
 * @brief gets a constant matrix's value by index
 * @param row the row to look for
 * @param col the column to look for
 * @return the vlue
 */
const float &Matrix::operator()(const int row, const int col) const
{
    if(row < 0 || col < 0 || row >= this->getRows() || col >= this->getCols())
    {
        cerr << INDEXBADARGS << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        return this->_vector[row * this->getCols() + col];
    }
}

/**
 * @brief gets a matrix's value by index
 * @param row the row to look for
 * @param col the column to look for
 * @return the vlue
 */
float& Matrix::operator()(const int row, const int col)
{
    if(row < 0 || col < 0 || row >= this->getRows() || col >= this->getCols())
    {
        cerr << INDEXBADARGS << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        return this->_vector[row * this->getCols() + col];
    }
}

/**
 * @brief redifines adding 2 matrice's
 * @param matrix the matrix to add
 * @return a new matrix
 */
Matrix Matrix::operator +(const Matrix& matrix) const
{
    if(this->getRows() != matrix.getRows() || this->getCols() != matrix.getCols())
    {
        cerr << ADDITIONNOTCOMPATIBLE << endl;
        exit(EXIT_FAILURE);
    }
    auto* newOne = new Matrix(this->getRows(), this->getCols());
    for(int i = 0; i < getRows(); i++)
    {
        for(int j = 0; j < getCols(); j++)
        {
            newOne->operator()(i, j) = this->operator()(i, j) + matrix(i, j);
        }
    }
    return *newOne;
}

/**
 * @brief redifines adding to a matrix
 * @param matrix the matrix added
 * @return the matrix after adding
 */
Matrix Matrix::operator +=(const Matrix& matrix)
{
    if(this->getRows() != matrix.getRows() || this->getCols() != matrix.getCols())
    {
        cerr << ADDITIONNOTCOMPATIBLE << endl;
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < getRows(); i++)
    {
        for(int j = 0; j < getCols(); j++)
        {
            this->operator()(i, j) += matrix(i, j);
        }
    }
    return *this;
}

/**
 * @brief redefines the out stream
 * @param output the stream
 * @param matrix the matrix to output
 * @return the output stream
 */
ostream& operator<<(ostream &output, Matrix& matrix)
{
    for(int i = 0; i < matrix.getRows(); i++)
    {
        for(int j = 0; j < matrix.getCols(); j++)
        {
            if(matrix(i, j) <= 0.1)
            {
                output << "  ";
            }
            else
            {
                output << "**";
            }
        }
        output << "\n";
    }
    return output;
}

/**
 * @brief redefines the input stream
 * @param input the input stream
 * @param matrix the matrix to input to
 * @return the input stream
 */
istream &operator>>(istream  &input, Matrix &matrix)
{
    for(int i = 0; i < matrix.getCols() * matrix.getRows(); i++)
    {
        if(!input.good())
        {
            cerr << INPUTFAIL << endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            input.read((char*)&(matrix[i]), sizeof(float));
        }
    }
    if(input.peek() != EOF)
    {
        cerr << INPUTNOTSUFICE << endl;
        exit(EXIT_FAILURE);
    }
    return input;
}