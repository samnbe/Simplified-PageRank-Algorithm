#include <iostream>
#include <vector>
#include <map>
#include "AdjacencyList.h"
//#include "AdjacencyList.cpp"

using namespace std;

int main(){
	int no_of_lines, power_iterations;
	string from, to;
	cin >> no_of_lines;
	cin >> power_iterations;

	//create a graph object 
	AdjacencyList graph; 

	for (int i = 0; i < no_of_lines; i++) {
		cin >> from;
		cin >> to;
		graph.AddWebpage(from, to);
	}

	graph.PowIt(power_iterations);
}
