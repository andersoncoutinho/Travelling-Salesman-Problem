#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Solution {
    vector<int> circuit;
    double cost;
};

struct InsertionInfo {
    int insertedvertex;
    int removedArc;
    double cost;
};

double calculateCost(vector<int> *solution, double **matrizAdj);
bool compareValues(InsertionInfo v1, InsertionInfo v2);

void construction(Solution *solution, int dimension, double **matrizAdj) {

    Solution *mySolution = solution;
    vector<int> buildingSolution;
    double cost;
         
    buildingSolution = {1, 1};
      
    int initialSubtour = 3;
    
    vector<int> candidateList;
    for(int i = 2; i <= dimension; i++) {
        candidateList.push_back(i);
    }    

    for(int i = 0; i < initialSubtour; i++) {
        int j = rand() % candidateList.size();
        buildingSolution.insert(buildingSolution.begin()+1, candidateList[j]);
        candidateList.erase(candidateList.begin() + j);
    } 

    while(!candidateList.empty()) {
        
        vector<InsertionInfo> insertionCost((buildingSolution.size() - 1) * candidateList.size());
        for(int i = 0, j = 1, l = 0; i < buildingSolution.size() - 1; i++, j++) {
            
           for(int k = 0; k < candidateList.size(); k++) {

                insertionCost[l].cost =  matrizAdj[buildingSolution[i]][candidateList[k]] 
                                        +matrizAdj[buildingSolution[j]][candidateList[k]] 
                                        -matrizAdj[buildingSolution[i]][buildingSolution[j]];
                                    
                insertionCost[l].insertedvertex = k;
                insertionCost[l].removedArc = i;
                l++;
            }   
        }
        
        sort(insertionCost.begin(), insertionCost.end(), compareValues);

        float alfa = (rand() % 100) / (float) 100;   
        int n = (int)(alfa * insertionCost.size());
        int N = n != 0 ? rand() % (n) : 0;
        
        buildingSolution.insert(buildingSolution.begin() + insertionCost[N].removedArc + 1, 
                                                                candidateList[insertionCost[N].insertedvertex]);
        candidateList.erase(candidateList.begin() + insertionCost[N].insertedvertex);
        
    }

    cost = calculateCost(&buildingSolution, matrizAdj); 
    mySolution->circuit = buildingSolution;
    mySolution->cost = cost;  

}

double calculateCost(vector<int> *solution, double **matrizAdj) {
    double cost = 0;

    for(int i = 0, j = 1; i < solution->size()-1; i++, j++) {
        cost += matrizAdj[solution->at(i)][solution->at(j)];
    }

    return cost;
}

bool compareValues(InsertionInfo v1, InsertionInfo v2) {    
    return v1.cost < v2.cost;
}