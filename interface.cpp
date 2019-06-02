#include "interface.h"

void run()
{
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
void interface()
{
    Material *materialHead = NULL;
    Material *currentMaterial = NULL;
    int n = 50;
    double thermalConductivity = 250;
    double thermalTransfer = 100;
    double area = 0.0000785;
    double lenght = 0.5;
    double temperatureA = 500;
    double temperatureB = 500;
    double temperatureOutside = 300;

    std::cout << "Choose material from list(l) or add new one(a)?" <<'\n';
    while(1)
    {
        bool out = 0;
        char input = std::cin.get();
        if(input == 'L' || input == 'l')
        {
            loadMaterials(materialHead,"materials.txt");
            int countOfmaterials =  showMaterials(materialHead);
            std::cout << "Write number of material or add new one(a)" << '\n';
            while(1)
            {
                input = std::cin.get();
                int tempinp = std::atoi(&input);
                if(tempinp > 0 && tempinp < countOfmaterials)
                {
                   currentMaterial = chooseMaterial(materialHead,tempinp);
                   out = 1;
                   break;
                }
                if(input == 'a' || input == 'A') break;
            }
        }
        if(input == 'a' || input == 'A')
        {
            loadMaterials(materialHead,"materials.txt");
            std::cout << "Give material parameter, separate with tab" << '\n';
            std::cout << "Name, Thermal Conductivity, Thermal Transfer, Area, Lenght" << '\n';
            std::string tempString;
            std::cin.ignore();
            std::getline(std::cin,tempString);
            currentMaterial = addMaterial(materialHead,tempString);
            saveMaterials(materialHead,"materials.txt");
            break;
        }
        if(out) break;

    }
    thermalConductivity = currentMaterial->thermalConductivity;
    thermalTransfer = currentMaterial->thermalTransfer;
    area = currentMaterial->area;
    lenght = currentMaterial->lenght;
    std::cout << "Give surroud parameter, separate with tab" << '\n';
    std::cout << "n, temperatureA, temperatureB, temperatureOutside" << '\n';
    std::cin.ignore();
    std::cin >> n;
    std::cin >> temperatureA;
    std::cin >> temperatureB;
    std::cin >> temperatureOutside;

    Matrix<double> testMatrixA = createMatrixA<double>(n,thermalConductivity,thermalTransfer,area,lenght);
    std::string tempname ="";
    tempname = currentMaterial->name + "MatrixA.txt";
    saveMatrix(testMatrixA,tempname);
    Matrix<double> testMatrixB = createMatrixB<double>(n,thermalTransfer,area,lenght,temperatureA,temperatureB,temperatureOutside);
    tempname = currentMaterial->name + "MatrixB.txt";
    saveMatrix(testMatrixB,tempname);
    Matrix<double> testSolvedMatrix = solveLUDecomposition(testMatrixA,testMatrixB);
    tempname = currentMaterial->name + "Solved.txt";
    saveMatrix(testSolvedMatrix,tempname);
    tempname = currentMaterial->name + "SolvedForMatlab.txt";
    saveMatrixForMatLab(testSolvedMatrix,tempname);
    deleteMaterial(materialHead);
    std::cout << "Done" << '\n';

}

void testCreateMatrix(unsigned height, unsigned width)
{
     Matrix<double> testMatrix2(height,width);
     testMatrix2[2][2] = 10;
     std::cout << testMatrix2[2][2]<<std::endl;
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
