#include <chrono>
#include "structures.h"

using namespace std;

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void printSolution(Solution solution, chrono::duration<double> algTime);
void gils(Solution *solution, int maxIterations,int maxILS, double **matrizAdj, int dimension);
void construction(Solution *solution, int dimension, double **matrizAdj);
void rvnd(Solution *solution, double **matrizAdj);
void perturb(Solution *solution, int dimension, double **matrizAdj);
double calculateCost(vector<int> *solution, double **matrizAdj);
bool compareValues(InsertionInfo v1, InsertionInfo v2);

#endif