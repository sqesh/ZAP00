#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include "matrix.h"

template <typename Type>
void saveMatrix(Matrix<Type> input, std::string filename)
{
    std::ofstream outputFile;
    outputFile.open(&filename[0]);
    if(outputFile.is_open())
    {
        for(unsigned height=0; height<input.height(); height++)
        {
            for(int width=0; width<input.width(); width++)
            {
                outputFile << input[height][width];
                if(width<(input.width()-1))outputFile << '\t';
            }
            if(height<(input.height()-1))
            {
                outputFile << '\n';
            }
        }
        outputFile.close();
    }
}

template <typename Type>
void saveMatrixForMatLab(Matrix<Type> input, std::string filename)
{
    std::ofstream outputFile;
    outputFile.open(&filename[0]);
    if(outputFile.is_open())
    {
        outputFile << '[';
        for(unsigned height=0; height<input.height(); height++)
        {
            for(int width=0; width<input.width(); width++)
            {
                outputFile << input[height][width];
                if(width<(input.width()-1))outputFile << ' ';
            }
            if(height<(input.height()-1))
            {
                outputFile << ';';
            }
        }
        outputFile << ']';
        outputFile.close();
    }
}

template <typename Type>
Matrix<Type> loadMatrix(std::string filename)
{
    std::ifstream inputFile;
    inputFile.open(&filename[0]);
    if(inputFile.is_open())
    {
        unsigned height=0, width=1;
        for(height=0; !inputFile.eof(); height++)
        {
            char znak(0);
            while(znak != '\n' && !inputFile.eof())
            {
                inputFile.get(znak);
                if(znak == '\t'&&height==1)width++;
            }
        }
        Matrix<Type> output(height,width);
        for(unsigned height=0; height<output.height(); height++)
        {
            for(int width=0; width<output.width(); width++)
            {
                inputFile >> output[height][width];
            }
        }
        inputFile.close();
        return output;
    }
}

template <typename Type>
void printMatrix(Matrix<Type> input)
{
    for(unsigned height=0; height<input.height() ; height++)
    {
        for(unsigned width=0; width<input.width() ; width++)
        {
            std::cout << input[height][width] << '\t';
        }
        std::cout <<'\n';
    }
}

template <typename Type>
Matrix<Type> createMatrixA(unsigned n, double thermalConductivity, double thermalTransfer, double area, double lenght)
{
    Matrix<Type> output(n,n);
    double dx = lenght / n;
    double temp1 = (thermalConductivity * area) /dx;
    double temp2 = 2*thermalTransfer*sqrt(3.14*area)*dx;
    for(unsigned height=0; height<output.height() ; height++)
    {
        for(unsigned width=0; width<output.width() ; width++)
        {
            if((height==0 && width==0) || (height==output.height()-1 && width== output.width()-1)) output[height][width] = 1;
            else if((width == height-1 || width == height+1)&&(height!=0 && height!=output.height()-1)) output[height][width] = -temp1;
            else if(width==height) output[height][width] = (2*temp1) + temp2;
            else  output[height][width] = 0;
        }
    }
}

template <typename Type>
Matrix<Type> createMatrixB(unsigned n, double thermalTransfer, double area, double lenght, double temperatureLeftSide, double temperatureRightSIde, double temperatureOutside)
{
    Matrix<Type> output(n,n);
    double dx = lenght / n;
    double temp2 = 2*thermalTransfer*sqrt(3.14*area)*dx;
    for(unsigned height ; height < output.height(); height++)
    {
        if(height==0) output[height][0] = temperatureLeftSide;
        else if(height==output.height()-1) output[height][0] = temperatureRightSIde;
        else output[height][0] = temp2*temperatureOutside;
    }
}


#endif // FUNCTIONS_H
