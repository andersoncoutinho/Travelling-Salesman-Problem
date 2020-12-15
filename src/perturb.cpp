#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Solution {
    vector<int> circuit;
    double cost;
};

struct IlsInfo {
    int firstVertice;
    int n1;
    int secondVertice;
    int n2;
};

extern double calculateCost(vector<int> *solution, double **matrizAdj);

void perturb(Solution *solution, int dimension, double **matrizAdj) {
	
	double cost;
	int positions[4];
	
	for(int i = 0; i < 4; i++) {
		positions[i] = rand() % (dimension-4)+1;
	}

	sort(positions, positions+4);

	for(int i = 0; i < 3; i++) {
		if(positions[i+1] <= positions[i]) {
			positions[i+1] = positions[i]+1;
		}
	}

	if(positions[1] - positions[0] > dimension/10) {
		positions[1] = positions[0] + dimension/10;
	}

	if(positions[3] - positions[2] > dimension/10) {
		positions[3] = positions[2] + dimension/10;
	}
	

	int firstRange = positions[1] - positions[0] + 1;
	int secondRange = positions[3] - positions[2] + 1; 	
	
	
	if(positions[2] == positions[1]+1) {
		cost = matrizAdj[solution->circuit[positions[0]]][solution->circuit[positions[3]]]
				+matrizAdj[solution->circuit[positions[1]]][solution->circuit[positions[3]+1]]
				+matrizAdj[solution->circuit[positions[2]]][solution->circuit[positions[0]-1]]
				-matrizAdj[solution->circuit[positions[0]]][solution->circuit[positions[0]-1]]
				-matrizAdj[solution->circuit[positions[1]]][solution->circuit[positions[2]]]
				-matrizAdj[solution->circuit[positions[3]]][solution->circuit[positions[3]+1]]
				;
	} else {
		cost = matrizAdj[solution->circuit[positions[0]]][solution->circuit[positions[2]-1]]
				+matrizAdj[solution->circuit[positions[1]]][solution->circuit[positions[3]+1]]
				+matrizAdj[solution->circuit[positions[2]]][solution->circuit[positions[0]-1]]
				+matrizAdj[solution->circuit[positions[3]]][solution->circuit[positions[1]+1]]
				-matrizAdj[solution->circuit[positions[0]]][solution->circuit[positions[0]-1]]
				-matrizAdj[solution->circuit[positions[1]]][solution->circuit[positions[1]+1]]
				-matrizAdj[solution->circuit[positions[2]]][solution->circuit[positions[2]-1]]
				-matrizAdj[solution->circuit[positions[3]]][solution->circuit[positions[3]+1]]			
				;
	}	

	for(int i = 0; i < firstRange; i++) {
		solution->circuit.insert(solution->circuit.begin() + positions[2], solution->circuit[positions[0]]);
		solution->circuit.erase(solution->circuit.begin() + positions[0]);
	}
	
	for(int i = 0; i < secondRange; i++) {
		solution->circuit.insert(solution->circuit.begin() + positions[0], solution->circuit[positions[3]]);
		solution->circuit.erase(solution->circuit.begin() + positions[3]+1);
	}
	
	solution->cost += cost;	
}