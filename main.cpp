#include <iostream>
#include "matrix.h"
#include "functions.h"
#include "ludecomposition.h"
using namespace std;
void testCreateMatrix(unsigned height, unsigned width)
{
     Matrix<double> testMatrix2(height,width);
     testMatrix2[2][2] = 10;
     cout << testMatrix2[2][2]<<endl;
}
void testDuplicateMatrix(unsigned height,unsigned width)
{
    Matrix<int> testMatrix3(height,width);
    for(unsigned h=0; h<height ; h++)
    {
        for(unsigned w=0; w<width ; w++)
        {
            testMatrix3[h][w]=3;
        }
    }
    Matrix<int> testMatrix4(testMatrix3);
    for(unsigned h=0; h<height ; h++)
    {
        for(unsigned w=0; w<width ; w++)
        {
            testMatrix4[h][w]=4;
        }
    }
    printMatrix(testMatrix3);
    printMatrix(testMatrix4);

}
int main()
{
    Matrix<int> testMatrix1;
    testCreateMatrix(10,10);
    testDuplicateMatrix(5,5);
}
