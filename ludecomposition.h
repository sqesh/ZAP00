#ifndef LUDECOMPOSITION_H
#define LUDECOMPOSITION_H
#include "matrix.h"
template <typename Type>
struct SplittenMatrix
{
    Matrix<Type> lower;
    Matrix<Type> upper;
};

template <typename Type>
SplittenMatrix<Type> splitMatrixDiagonally(Matrix<Type> const& input)
{
    if(input.height() == input.width())
    {
        SplittenMatrix<Type> splittenMatrix;
        Matrix<Type> lowerMatrix;
        Matrix<Type> upperMatrix;
        for (unsigned i = 0; i < input.height(); i++)
        {
            for (unsigned j = 0; j < input.height(); j++)
            {
                if (j < i) lowerMatrix[j][i] = 0;
                else
                {
                    lowerMatrix[j][i] = input[j][i];
                    for (unsigned k = 0; k < i; k++)
                    {
                        lowerMatrix[j][i] = lowerMatrix[j][i] - lowerMatrix[j][k] * upperMatrix[k][i];
                    }
                }
            }
            for (unsigned j = 0; j < input.height(); j++)
            {
                if (j < i)
                    upperMatrix[i][j] = 0;
                else if (j == i)
                    upperMatrix[i][j] = 1;
                else
                {
                    upperMatrix[i][j] = input[i][j] / lowerMatrix[i][i];
                    for (unsigned k = 0; k < i; k++)
                    {
                        upperMatrix[i][j] = upperMatrix[i][j] - ((lowerMatrix[i][k] * upperMatrix[k][j]) / lowerMatrix[i][i]);
                    }
                }
            }
        }
        splittenMatrix.lower = lowerMatrix;
        splittenMatrix.upper = upperMatrix;
        return splittenMatrix;
    }
}


#endif // LUDECOMPOSITION_H
