using namespace std;

#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

struct Solution {
    vector<int> circuit;
    double cost;
};

struct InsertionInfo {
    int insertedvertex;
    int removedArc;
    double cost;
};

struct reOptimization {
    double cost;
    int firstvertex;
    int secondvertex;
};

struct IlsInfo {
    int firstvertex;
    int n1;
    int secondvertex;
    int n2;
};

#endif