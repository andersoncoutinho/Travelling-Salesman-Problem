#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

struct Solution {
    vector<int> circuit;
    double cost;
};

extern void construction(Solution *solution, int dimension, double **matrizAdj);
extern void rvnd(Solution *solution, double **matrizAdj);
extern void perturb(Solution *solution, int dimension, double **matrizAdj);

void gils(Solution *bestSolution, int maxIterations,int maxILS, double **matrizAdj, int dimension){

    bestSolution->cost = __DBL_MAX__;

    for(int i = 0; i < maxIterations; i++) {

        Solution preSolution;        
        
        construction(&preSolution, dimension, matrizAdj);

        Solution posSolution = preSolution;

        for(int iterILS = 0; iterILS < maxILS; iterILS++) {
        
            rvnd(&posSolution, matrizAdj);
    
            if(posSolution.cost < preSolution.cost) {
                preSolution = posSolution;
                iterILS = -1;
            } else {
                posSolution = preSolution;
                
            }      
            
            perturb(&posSolution, dimension, matrizAdj);

        }
        
        if(preSolution.cost < bestSolution->cost) {
            bestSolution->circuit = preSolution.circuit;
            bestSolution->cost = preSolution.cost;
        }
    }  
}