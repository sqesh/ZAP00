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
void testSaveMatrix(unsigned height,unsigned width)
{
    Matrix<int> testMatrix5(height,width);
    for(unsigned h=0; h<testMatrix5.height() ; h++)
    {
        for(unsigned w=0; w<testMatrix5.width() ; w++)
        {
            testMatrix5[h][w]=w+1+h*testMatrix5.width();
        }
    }
    //Matrix<int> testMatrix6 = testMatrix5;
    //printMatrix(testMatrix6);
    saveMatrix(testMatrix5,"testMatrix5.txt");
    saveMatrixForMatLab(testMatrix5,"testMatrix5Matlab.txt");
}
void testLoadMatrix(std::string filename)
{
    Matrix<int> testMatrix6 = loadMatrix<int>(filename);
    saveMatrix(testMatrix6,"testMatrix6.txt");
    printMatrix(testMatrix6);
}
int main()
{
//    Matrix<int> testMatrix1;
//    testCreateMatrix(10,10);
//    testDuplicateMatrix(5,5);
//    testSaveMatrix(5,5);
//    testLoadMatrix("testMatrix5.txt");
    int n = 50;
    double thermalConductivity = 250;
    double thermalTransfer = 100;
    double area = 0.0000785;
    double lenght = 0.5;
    double temperatureA = 500;
    double temperatureB = 500;
    double temperatureOutside = 300;

    Matrix<double> testMatrix7 = createMatrixA<double>(n,thermalConductivity,thermalTransfer,area,lenght);
    saveMatrix(testMatrix7,"testMatrixA.txt");
    Matrix<double> testMatrix8 = createMatrixB<double>(n,thermalTransfer,area,lenght,temperatureA,temperatureB,temperatureOutside);
    saveMatrix(testMatrix8,"testMatrixB.txt");
    Matrix<double> testMatrix9 = solveLUDecomposition(testMatrix7,testMatrix8);
    saveMatrix(testMatrix9,"testSolved.txt");
    saveMatrixForMatLab(testMatrix9,"testSolvedMatLab.txt");
}
