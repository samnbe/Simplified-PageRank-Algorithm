#pragma once
#include <map>
#include <vector>
#include <iomanip>
using namespace std;


class AdjacencyList {
	map<string, vector<string>> web_con;
	map<string, vector<string>> con_list;
public:
	AdjacencyList();
	~AdjacencyList();
	bool CheckInList(string webpage);
	bool CheckInM(string webpage); 
	void AddWebpage(string from, string to);
	void AddConAsKey(string to);
	void AddConAsKeyM(string to); 
	void AddNewWebpage(string from, string con);
	void AddNewWebpageM(string from, string con);
	void AddCon(string from, string con); 
	void AddConM(string from, string con);
	void PowIt(int power_iterations);
	void Print(map<string, float> r);
};


//make sure to test for only 1 weboage pointing to itself (everything is 1)
