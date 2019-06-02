#include "material.h"

Material *addMaterial(Material *&head, std::string rawMaterial)
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

    std::stringstream strStream(rawMaterial);
    strStream >> act->name;
    strStream >> act->thermalConductivity;
    strStream >> act->thermalTransfer;
    strStream >> act->area;
    strStream >> act->lenght;
    return act;
}

void deleteMaterial(Material *&head)
{
    while(head != NULL)
    {
        Material *act = head;
        head = head->next;
        delete act;
    }
}

int showMaterials(Material *head)
{
    Material *act = head;
    std::cout << "List of materials:" << '\n';
    std::cout << "Name, Thetmal Conductivity, Thermal Transfer, Area, Lenght" << '\n';
    int i=0;
    for( i=1; act != NULL ; i++)
    {
        std::cout << i << ". ";
        std::cout << act->name << '\t';
        std::cout << act->thermalConductivity << '\t';
        std::cout << act->thermalTransfer << '\t';
        std::cout << act->area << '\t';
        std::cout << act->lenght << '\n';
        act = act->next;
    }
    return (i);
}
Material *chooseMaterial(Material *head, int number)
{
    Material *act = head;
    for(int i=0;(i<number-1) && (act != NULL);i++)
    {
        act = act->next;
    }
    return act;
}

void loadMaterials(Material *&head, std::string filename)
{
    std::ifstream inputFile;
    inputFile.open(&filename[0]);
    if(inputFile.is_open())
    {
        while(!inputFile.eof())
        {
            std::string tempString;
            std::getline(inputFile,tempString);
            if(!inputFile.eof())addMaterial(head,tempString);
        }
    }
    inputFile.close();
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
            outputFile << act->name << '\t';
            outputFile << act->thermalConductivity << '\t';
            outputFile << act->thermalTransfer << '\t';
            outputFile << act->area << '\t';
            outputFile << act->lenght << '\n';
            act = act->next;
        }
    }
    outputFile.close();
}
