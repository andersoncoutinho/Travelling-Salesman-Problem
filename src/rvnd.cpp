#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "neighbourFunctions.h"

void rvnd(Solution *solution, double **matrizAdj){
    vector<int> neighbourhoods = {1, 2, 3, 4, 5};
    reOptimization bestNeighbour;
    int aux;

    while(!neighbourhoods.empty()){
        int neighbourhood = rand() % neighbourhoods.size();
        switch(neighbourhoods[neighbourhood]) {
            
            case 1:

                opt2(&bestNeighbour, *solution, matrizAdj);
            
                if(bestNeighbour.cost < 0) {
                    
                    reverse(solution->circuit.begin() + bestNeighbour.firstVertice, 
                            solution->circuit.begin() + bestNeighbour.secondVertice+1);

                    solution->cost += bestNeighbour.cost;

                    neighbourhoods = {1, 2, 3, 4, 5};

                } else {
                    neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 2:

                hSwap(&bestNeighbour, *solution, matrizAdj);

                if(bestNeighbour.cost < 0) {

                    aux = solution->circuit[bestNeighbour.firstVertice];
                    solution->circuit[bestNeighbour.firstVertice] = solution->circuit[bestNeighbour.secondVertice];
                    solution->circuit[bestNeighbour.secondVertice] = aux;    

                    solution->cost += bestNeighbour.cost;
                    neighbourhoods = {1, 2, 3, 4, 5};

                } else {
                    neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 3:

                orOpt3(&bestNeighbour, *solution, matrizAdj);

                if(bestNeighbour.cost < 0) {
                            
                    if(bestNeighbour.firstVertice > bestNeighbour.secondVertice) {  
                            
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice,
                                                solution->circuit[bestNeighbour.firstVertice+2]);
                        
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice,
                                                solution->circuit[bestNeighbour.firstVertice+2]);
                        
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice,
                                                solution->circuit[bestNeighbour.firstVertice+2]);
                        
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice+3);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice+3);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice+3);

                    } else {
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice+1, 
                                                    solution->circuit.begin() +  bestNeighbour.firstVertice,
                                                    solution->circuit.begin() +  bestNeighbour.firstVertice+3);
                                                           
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice);
                    }

                    solution->cost += bestNeighbour.cost;
                    neighbourhoods = {1, 2, 3, 4, 5};
                    
                } else {
                   neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 4:

                reInsertion(&bestNeighbour, *solution, matrizAdj);
                
                if(bestNeighbour.cost < 0) {
                    
                    aux = solution->circuit[bestNeighbour.firstVertice];

                    solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice);
        
                    solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice, aux);

                    solution->cost += bestNeighbour.cost;
                    neighbourhoods = {1, 2, 3, 4, 5};
                    
                } else {
                    neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 5:   

                orOpt2(&bestNeighbour, *solution, matrizAdj);
                if(bestNeighbour.cost < 0) {
                         
                    if(bestNeighbour.firstVertice > bestNeighbour.secondVertice) {

                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice,
                                                solution->circuit[bestNeighbour.firstVertice+1]);
                        
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice,
                                                solution->circuit[bestNeighbour.firstVertice+1]);

                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice+2);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice+2);
                        
                        
                    } else {
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondVertice+1, 
                                                    solution->circuit.begin() +  bestNeighbour.firstVertice,
                                                    solution->circuit.begin() +  bestNeighbour.firstVertice+2);
                                                
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstVertice);
                    }

                    solution->cost += bestNeighbour.cost;                                        
                    neighbourhoods = {1, 2, 3, 4, 5};

                } else {
                   neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;
        }
    }
}