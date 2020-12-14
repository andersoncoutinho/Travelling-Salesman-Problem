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
	double precusto = solution->cost;
	vector<int> current = solution->circuit;
	double cost;
	int positions[4];

	for(int i = 0; i < 4; i++) {
		positions[i] = rand() % (dimension-4)+1;
	}

	sort(positions, positions+4);

	for(int i = 0; i < 3; i++) {
		if(positions[i+1] <= positions[i]) {
			positions[i+1] == positions[i]+1;
		}
	}

	if(positions[1] - positions[0] > dimension/10 - 1) {
		positions[1] = positions[0] + dimension/10 -1;
	}

	if(positions[3] - positions[2] > dimension/10 -1) {
		positions[3] = positions[2] + dimension/10 - 1;
	}

	int firstRange = positions[1] - positions[0] + 1;
	int secondRange = positions[3] - positions[2] + 1; 	

	for(int i = 0; i < firstRange; i++) {
		current.insert(current.begin() + positions[2], current[positions[0]]);
		current.erase(current.begin() + positions[0]);
	}

	
	for(int i = 0; i < secondRange; i++) {
		current.insert(current.begin() + positions[0], current[positions[2]]);
		current.erase(current.begin() + positions[2]+1);
	}
	
	
	solution->circuit = current;
	solution->cost = calculateCost(&current, matrizAdj);

}