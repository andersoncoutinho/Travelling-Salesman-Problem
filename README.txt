This is a metaheuristic algorithm implemented in C++ for the Travelling Salesman Problem(TSP).

TSP instances are inside the "instances" folder.

The "tsp" file solves a single TSP instance. To use it you need to open the terminal and type the following command line:

./tsp instances/"name of the instance file you want to solve"

The "run.sh" runs each instance file 10 times and prints the results in a txt file named "bm.txt" inside the "benchmark" folder.
To run it you need to open the terminal and type the following command line:

./run.sh

Inside the benchmark folder there's the "bmMean" executable that calculates the mean time and mean cost
of the values in the "bm.txt" file and prints them in a txt file named "bm_final.txt".
To run it you need to open the terminal and type the following command line:

./bm.exe