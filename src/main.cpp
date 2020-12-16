#include "readData.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

#define MAX_INTERACTIONS 50
#define MAX_ILS (dimension >= 150) ? (dimension/2) : (dimension)

using namespace std;

struct Solution {
    vector<int> circuit;
    double cost;
};

double ** matrizAdj; // matriz de adjacencia
int dimension; // quantidade total de vertexs

void printData();
void printSolution(Solution solution, chrono::duration<double> algTime);
void gils(Solution *solution, int maxIterations,int maxILS, double **matrizAdj, int dimension);

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

void printData() {
  cout << "dimension: " << dimension << endl;
  for (size_t i = 1; i <= dimension; i++) {
    for (size_t j = 1; j <= dimension; j++) {
      cout << matrizAdj[i][j] << " ";
    }
    cout << endl;
  }
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