#include "material.h"

void addMaterial(Material *head, std::ifstream file)
{
    Material *act;
    if (head==NULL)
    {
        head = new Material;
        act = head;
    }
    else
    {
        act = head;
        while(act->next != NULL)
        {
            act = act->next;
        }
        act->next = new Material;
        act = act->next;
    }
    file >> act->name;
    file >> act->thermalConductivity;
    file >> act->thermalTransfer;
    file >> act->area;
    file >> act->lenght;
}

void deleteMaterial(Material *head)
{
    while(head == NULL)
    {
        Material *act = head;
        head = head->next;
        delete act;
    }
}

void showMaterials(Material *head)
{
    Material *act = head;
    std::cout << "List of materials:";
    std::cout << "Name, Thetmal Conductivity, Thermal Transfer, Area, Lenght";
    for(int i=1; act != NULL ; i++)
    {
        std::cout << i << ". ";
        std::cout << act->name << '\t';
        std::cout << act->thermalConductivity << '\t';
        std::cout << act->thermalTransfer << '\t';
        std::cout << act->area << '\t';
        std::cout << act->lenght << '\n';
    }
}
Material *chooseMaterial(Material *head, int number)
{
    Material *act = head;
    for(int i=0;(i<number) && (act != NULL);i++)
    {
        act = act->next;
    }
    return act;
}

void loadMaterials(Material *head, std::string filename)
{
    std::ifstream inputFile;
    inputFile.open(&filename[0]);
    if(inputFile.is_open())
    {
        while(!inputFile.eof())
        {
            addMaterial(head,inputFile);
        }
    }
}
void saveMaterials(Material *head, std::string filename)
{
    Material *act = head;
    std::ofstream outputFile;
    outputFile.open(&filename[0]);
    if(outputFile.is_open())
    {
        while(act!=NULL)
        {
            std::cout << act->name << '\t';
            std::cout << act->thermalConductivity << '\t';
            std::cout << act->thermalTransfer << '\t';
            std::cout << act->area << '\t';
            std::cout << act->lenght << '\n';
            act = act->next;
        }
    }
}
