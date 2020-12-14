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

void hSwap(reOptimization *bestNeighbour, Solution &solution, double **matrizAdj) {    
    
    int bestI, bestJ, bestCost = 0;
    
    
    int lastSwitchableVertice = solution.circuit.size()-2;
    
    double cost;

    for(int i = 1; i < lastSwitchableVertice; i++) {

        double delta = -(matrizAdj[solution.circuit[i]][solution.circuit[i-1]]
                         +matrizAdj[solution.circuit[i]][solution.circuit[i+1]])
                       ;

        for(int j = i + 1; j <= lastSwitchableVertice; j++) {          

            if(j == i + 1) {

                cost = delta
                        +matrizAdj[solution.circuit[i]][solution.circuit[j+1]]                                        
                        +matrizAdj[solution.circuit[j]][solution.circuit[i-1]] 
                        +matrizAdj[solution.circuit[i]][solution.circuit[i+1]]                                       
                        -matrizAdj[solution.circuit[j]][solution.circuit[j+1]]                                        
                        ;


            } else {
            
                cost = delta
                        +matrizAdj[solution.circuit[i]][solution.circuit[j-1]]                                        
                        +matrizAdj[solution.circuit[i]][solution.circuit[j+1]]
                        -matrizAdj[solution.circuit[j]][solution.circuit[j-1]]
                        -matrizAdj[solution.circuit[j]][solution.circuit[j+1]]
                        +matrizAdj[solution.circuit[j]][solution.circuit[i-1]]
                        +matrizAdj[solution.circuit[j]][solution.circuit[i+1]]
                        ;

            }

            
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