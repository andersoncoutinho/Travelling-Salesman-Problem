#include <iostream>
#include <vector>
#include "structures.h"

void opt2(reOptimization *bestNeighbour, Solution &solution, double **matrizAdj) {

    int bestI, bestJ, bestCost = 0;
    int solutionSize = solution.circuit.size();
    double cost;

    for(int i = 1; i < solutionSize - 4; i++) {
        
        double delta = -matrizAdj[solution.circuit[i]][solution.circuit[i-1]];

        for(int j = i + 3; j < solutionSize-1; j++) {
            
            cost = delta
                    +matrizAdj[solution.circuit[i]][solution.circuit[j+1]]
                    +matrizAdj[solution.circuit[j]][solution.circuit[i-1]]                                                
                    -matrizAdj[solution.circuit[j]][solution.circuit[j+1]]
                    ;
            
            if(cost < bestCost) {
                bestI = i;
                bestJ = j;
                bestCost = cost;
            }
        }
    }
    bestNeighbour->firstvertex = bestI;
    bestNeighbour->secondvertex = bestJ;
    bestNeighbour->cost = bestCost;
}