#include "readData.h"
#include <iostream>
#include <vector>
#include <chrono>
#include "functions.h"

#define MAX_INTERACTIONS 50
#define MAX_ILS ((dimension >= 150) ? (dimension/2) : (dimension))

double ** matrizAdj;
int dimension;

int main(int argc, char** argv) {
    
    readData(argc, argv, &dimension, &matrizAdj);
    
    srand(time(NULL));

    auto begin = chrono::system_clock::now();

    Solution solution;
    gils(&solution, MAX_INTERACTIONS, MAX_ILS, matrizAdj, dimension);    

    auto end = chrono::system_clock::now();
    chrono::duration<double> algTime = end - begin;

    printSolution(solution, algTime);
     
    return 0;
}

void printSolution(Solution solution, chrono::duration<double> algTime) {
  int i;
  
  cout << "Solution = {";

  for(i = 0; i < solution.circuit.size()-1; i++) {
    cout << solution.circuit[i] << ", ";
  }

  cout << solution.circuit[i] << "}" << endl;
  
  cout << "Cost: " << solution.cost << endl;

  cout << "Time: " << algTime.count() << endl;

}