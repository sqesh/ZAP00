#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <fstream>
#include <iostream>

struct Material
{
    std::string name;
    double thermalConductivity = 250;
    double thermalTransfer = 100;
    double area = 0.0000785;
    double lenght = 0.5;
    Material *next = NULL;
};

void addMaterial(Material *head, std::ifstream file);
void deleteMaterial(Material *head);
void showMaterials(Material *head);
Material *chooseMaterial(Material *head, int number);
void loadMaterials(Material *head, std::string filename);
void saveMaterials(Material *head, std::string filename);

#endif // MATERIAL_H
