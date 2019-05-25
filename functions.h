#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <string>
#include <iostream>
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



#endif // FUNCTIONS_H
