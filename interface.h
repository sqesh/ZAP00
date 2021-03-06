#ifndef INTERFACE_H
#define INTERFACE_H

#include "matrix.h"
#include "functions.h"
#include "ludecomposition.h"
#include "material.h"


void run();
void interface(int argc, char *argv[]);
void testCreateMatrix(unsigned height, unsigned width);
void testDuplicateMatrix(unsigned height,unsigned width);
void testSaveMatrix(unsigned height,unsigned width);
void testLoadMatrix(std::string filename);



#endif // INTERFACE_H
