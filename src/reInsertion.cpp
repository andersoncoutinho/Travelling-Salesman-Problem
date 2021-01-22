#include <iostream>
#include <vector>
#include "structures.h"

void reInsertion(reOptimization *bestNeighbour, Solution &solution, double **matrizAdj) {

    int bestI, bestJ, bestCost = 0;
    int lastSwitchablevertex = solution.circuit.size() - 2;
    double cost;

    for(int i = 1; i < lastSwitchablevertex-1; i++) {
        
        double delta = matrizAdj[solution.circuit[i-1]][solution.circuit[i+1]]
                      -matrizAdj[solution.circuit[i]][solution.circuit[i-1]]
                      -matrizAdj[solution.circuit[i]][solution.circuit[i+1]]
                      ;

        for(int j = i + 2; j <= lastSwitchablevertex; j++) {
            
            cost = delta                 
                        +matrizAdj[solution.circuit[i]][solution.circuit[j]]
                        +matrizAdj[solution.circuit[i]][solution.circuit[j+1]]
                        -matrizAdj[solution.circuit[j]][solution.circuit[j+1]]
                        ;            
            


            if(cost < bestCost) {
                bestI = i;
                bestJ = j;
                bestCost = cost;
            }
        }
    }
    
    for(int i = 5; i <= lastSwitchablevertex; i++) {

        double delta = -matrizAdj[solution.circuit[i]][solution.circuit[i-1]]
                       -matrizAdj[solution.circuit[i]][solution.circuit[i+1]]
                       +matrizAdj[solution.circuit[i-1]][solution.circuit[i+1]];

        for(int j = i - 4; j > 0; j--) {

            
            cost = delta           
                    +matrizAdj[solution.circuit[i]][solution.circuit[j]]
                    +matrizAdj[solution.circuit[i]][solution.circuit[j-1]]                                                      
                    -matrizAdj[solution.circuit[j]][solution.circuit[j-1]]
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