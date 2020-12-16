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
                    
                    reverse(solution->circuit.begin() + bestNeighbour.firstvertex, 
                            solution->circuit.begin() + bestNeighbour.secondvertex+1);

                    solution->cost += bestNeighbour.cost;
                    fillNeighbourhoods(neighbourhoods);

                } else {
                    neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 2:

                hSwap(&bestNeighbour, *solution, matrizAdj);

                if(bestNeighbour.cost < 0) {

                    aux = solution->circuit[bestNeighbour.firstvertex];
                    solution->circuit[bestNeighbour.firstvertex] = solution->circuit[bestNeighbour.secondvertex];
                    solution->circuit[bestNeighbour.secondvertex] = aux;    

                    solution->cost += bestNeighbour.cost;
                    fillNeighbourhoods(neighbourhoods);

                } else {
                    neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 3:

                orOpt3(&bestNeighbour, *solution, matrizAdj);

                if(bestNeighbour.cost < 0) {
                            
                    if(bestNeighbour.firstvertex > bestNeighbour.secondvertex) {  
                            
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex,
                                                solution->circuit[bestNeighbour.firstvertex+2]);
                        
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex,
                                                solution->circuit[bestNeighbour.firstvertex+2]);
                        
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex,
                                                solution->circuit[bestNeighbour.firstvertex+2]);
                        
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex+3);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex+3);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex+3);

                    } else {
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex+1, 
                                                    solution->circuit.begin() +  bestNeighbour.firstvertex,
                                                    solution->circuit.begin() +  bestNeighbour.firstvertex+3);
                                                           
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex);
                    }

                    solution->cost += bestNeighbour.cost;
                    fillNeighbourhoods(neighbourhoods);
                    
                } else {
                   neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 4:

                reInsertion(&bestNeighbour, *solution, matrizAdj);
                
                if(bestNeighbour.cost < 0) {
                    
                    aux = solution->circuit[bestNeighbour.firstvertex];

                    solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex);
        
                    solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex, aux);

                    solution->cost += bestNeighbour.cost;
                    fillNeighbourhoods(neighbourhoods);
                    
                } else {
                    neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;

            case 5:   

                orOpt2(&bestNeighbour, *solution, matrizAdj);
                if(bestNeighbour.cost < 0) {
                         
                    if(bestNeighbour.firstvertex > bestNeighbour.secondvertex) {

                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex,
                                                solution->circuit[bestNeighbour.firstvertex+1]);
                        
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex,
                                                solution->circuit[bestNeighbour.firstvertex+1]);

                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex+2);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex+2);
                        
                        
                    } else {
                        solution->circuit.insert(solution->circuit.begin()+bestNeighbour.secondvertex+1, 
                                                    solution->circuit.begin() +  bestNeighbour.firstvertex,
                                                    solution->circuit.begin() +  bestNeighbour.firstvertex+2);
                                                
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex);
                        solution->circuit.erase(solution->circuit.begin() + bestNeighbour.firstvertex);
                    }

                    solution->cost += bestNeighbour.cost;                                        
                    fillNeighbourhoods(neighbourhoods);

                } else {
                   neighbourhoods.erase(neighbourhoods.begin() + neighbourhood);
                }

                break;
        }
    }
}

void fillNeighbourhoods(vector<int> &neighbourhoods) {
    neighbourhoods = {1, 2, 3, 4, 5};
}