#include <iostream>
#include <vector>

using namespace std;

struct Solution{
    vector<int> circuit;
    double cost;
};

struct reOptimization {
    double cost;
    int firstVertice;
    int secondVertice;
};

void orOpt3(reOptimization *bestNeighbour, Solution &solution, double **matrizAdj) {

    int bestI, bestJ, bestCost = 0;

    int lastSwitchableVertice = solution.circuit.size()-2;
    

    double cost;

    for(int i = 1; i < lastSwitchableVertice - 3; i++) {
        
        double delta = matrizAdj[solution.circuit[i-1]][solution.circuit[i+3]]
                      -matrizAdj[solution.circuit[i]][solution.circuit[i-1]]
                      -matrizAdj[solution.circuit[i+2]][solution.circuit[i+3]]
                      ;

        for(int j = i + 3; j <= lastSwitchableVertice; j++) {
            
            cost = delta
                    +matrizAdj[solution.circuit[i]][solution.circuit[j]]
                    +matrizAdj[solution.circuit[i+2]][solution.circuit[j+1]]
                    -matrizAdj[solution.circuit[j]][solution.circuit[j+1]]
                    ;
            
            if(cost < bestCost) {
                bestI = i;
                bestJ = j;
                bestCost = cost;
            }   

        }

    }
    for(int i = 3; i < lastSwitchableVertice-1; i++) {

        double delta =  matrizAdj[solution.circuit[i-1]][solution.circuit[i+3]]
                       -matrizAdj[solution.circuit[i]][solution.circuit[i-1]]
                       -matrizAdj[solution.circuit[i+3]][solution.circuit[i+2]]
                       ;


        for(int j = i - 1; j > 0; j--) {
            
            cost = delta
                    +matrizAdj[solution.circuit[i]][solution.circuit[j-1]]
                    +matrizAdj[solution.circuit[i+2]][solution.circuit[j]]                                                        
                    -matrizAdj[solution.circuit[j]][solution.circuit[j-1]]
                    ;

            if(cost < bestCost) {
                bestI = i;
                bestJ = j;
                bestCost = cost;
            }
        }
    }
    bestNeighbour->firstVertice = bestI;
    bestNeighbour->secondVertice = bestJ;
    bestNeighbour->cost = bestCost;
}