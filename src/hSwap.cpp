#include <iostream>
#include <vector>

using namespace std;

struct Solution{
    vector<int> circuit;
    double cost;
};

struct reOptimization {
    double cost;
    int firstvertex;
    int secondvertex;
};

void hSwap(reOptimization *bestNeighbour, Solution &solution, double **matrizAdj) {    
    
    int bestI, bestJ, bestCost = 0;
    
    
    int lastSwitchablevertex = solution.circuit.size()-2;
    
    double cost;

    for(int i = 1; i < lastSwitchablevertex; i++) {

        double delta = -(matrizAdj[solution.circuit[i]][solution.circuit[i-1]]
                         +matrizAdj[solution.circuit[i]][solution.circuit[i+1]])
                       ;

        for(int j = i + 1; j <= lastSwitchablevertex; j++) {          

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
    bestNeighbour->firstvertex = bestI;
    bestNeighbour->secondvertex = bestJ;
    bestNeighbour->cost = bestCost;
}