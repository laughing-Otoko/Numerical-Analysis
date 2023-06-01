#ifndef GRAM_SCHMIDT_PROCESS_H
#define GRAM_SCHMIDT_PROCESS_H
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

class Matrix
{
 private:
    unsigned _rows;
    unsigned _cols;
    vector<vector<double>> _matrix;
 
 public:
    Matrix(unsigned rows, unsigned cols, double init) : _rows(rows), _cols(cols)
    {
        _matrix.resize(rows);
        
        for (unsigned i = 0; i < _matrix.size(); i++)
        {
            _matrix[i].resize(cols, init);
        }
    }

    Matrix operator+(Matrix &otherMatrix)
    {
        Matrix sum(_rows, _cols, 0.0);
        
        for (unsigned i = 0; i < _rows; i++)
            for (unsigned j = 0; j < _cols; j ++)
            {
                sum._matrix[i][j] = this->_matrix[i][j] + otherMatrix._matrix[i][j];
            }
        
        return sum;
    }

    Matrix operator-(Matrix &otherMatrix)
    {
        Matrix diff(_rows, _cols, 0.0);
        
        for (unsigned i = 0; i < _rows; i++)
            for (unsigned j = 0; j < _cols; j ++)
            {
                diff._matrix[i][j] = this->_matrix[i][j] - otherMatrix._matrix[i][j];
            }
        
        return diff;
    }

    Matrix operator*(Matrix &otherMatrix)
    {
        Matrix product(_rows, otherMatrix._cols, 0.0);
        double temp;
        assert(_cols == otherMatrix._rows);        

        for (unsigned i = 0; i < _rows; i++)
            for (unsigned j = 0; j < otherMatrix._cols; j++)
            {
                temp = 0.0;
                for (unsigned k = 0; k < _cols; k++){
                    temp += _matrix[i][k] * otherMatrix._matrix[k][j];
                }
                product._matrix[i][j] = temp;
            }
        
        return product;
    }

    Matrix scalar_multiplication(double scalar)
    {
        Matrix res(_rows, _cols, 0.0);
        
        for (unsigned i = 0; i < _rows; i++)
            for (unsigned j = 0; j < _cols; j++)
            {
                res._matrix[i][j] = this->_matrix[i][j] * scalar;   
            }
        
       return res;
    }

    Matrix transpose()
    {
        Matrix tr(_cols, _rows, 0.0);
        for (unsigned i = 0; i < _cols; i++)
            for (unsigned j = 0; j < _rows; j++)
            {
                tr._matrix[i][j] = this->_matrix[j][i];
            }
        return tr;
    }

    void print() const
    {
        cout << "Matrix: " << endl;
        for (unsigned i = 0; i < _rows; i++)
        {
            for (unsigned j = 0; j < _cols; j++)
            {
              cout << "[" << _matrix[i][j] << "]";
            }
            cout << endl;
        }
    }

    double dotProduct(Matrix &otherMatrix)
    {
        if ((_rows != 1 && _cols !=1) || (otherMatrix._rows != 1 && otherMatrix._cols != 1)){
            throw invalid_argument("Both matrices must be vectors to calculate the dot product");
        }
        
        if (_rows * _cols != otherMatrix._rows * otherMatrix._cols){
            throw invalid_argument("Both matrices must have the same dimensions to calculate the dot product");
        }

        double dotProd = 0.0;
        for (unsigned i = 0; i < _rows; i++){
            for (unsigned j = 0; j < _cols; j++)
            dotProd += _matrix[i][j] * otherMatrix._matrix[i][j];

        }
        
        return dotProd;
    }

    // Matrix gramSchmidtProcess()
    // {
    //     //This function will produce the orthogonal vector, not the orthonormal vector
    //     //That said the orthogonal vector will not be normalized
    //     if (_rows != 1 && _cols !=1){
    //         throw invalid_argument("Both matrices must be vectors to calculate the dot product");
    //     }

    //     Matrix res(_rows, _cols, 0.0);

    //      for (unsigned i = 0; i < _cols; i++){
    //         res._matrix[0][i] = _matrix[0][i];
    //      }

    //       for (unsigned i = 0; i < _rows; i++){
    //         Matrix temp(i, _cols, 0.0);

    //         for (unsigned j = 0; j < i; j++){
    //             double dotProd = 0.0;
    //             for (unsigned k = 0; k < _cols; k++){
    //                 dotProd += _matrix[i][k] * res._matrix[j][k];
    //                 temp._matrix[j][k] = dotProd * res._matrix[j][k];
    //             }
    //         }

    //     }
    // }

};
#endif
