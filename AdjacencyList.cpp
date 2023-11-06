#include <iostream> 
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
	//create empty maps 
	web_con = map <string, vector<string>>();
	con_list = map <string, vector<string>>();
}
	

AdjacencyList::~AdjacencyList() {
	//empty the maps 
	web_con.clear();
	con_list.clear();
}

bool AdjacencyList::CheckInList(string webpage) {
	//check if key in map already
	if (web_con.find(webpage) == web_con.end()) {
		//not found in map
		return false;
	}
	else {
		//found in map
		return true;
	}
}

bool AdjacencyList::CheckInM(string webpage) {
	//check if key in map already
	if (con_list.find(webpage) == con_list.end()) { 
		//not found in map
		return false;
	}
	else {
		//found in map
		return true;
	}
}

void AdjacencyList::AddNewWebpage(string from, string con) {
	vector<string> temp; 
	temp.push_back(con);  
	web_con[from] = temp;  
}

void AdjacencyList::AddNewWebpageM(string from, string con) {
	vector<string> temp;
	temp.push_back(from);
	con_list[con] = temp; 
}

void AdjacencyList::AddCon(string from, string con) {
	//search in vector if con already in vector 
	if (find(web_con[from].begin(), web_con[from].end(), con) == web_con[from].end()) { 
		web_con[from].push_back(con); 
	}
}

void AdjacencyList::AddConM(string from, string con) {
	//search in vector if con already in vector 
	if (find(con_list[con].begin(), con_list[con].end(), from) == con_list[con].end()) {
		con_list[con].push_back(from); 
	}
}

void AdjacencyList::AddConAsKey(string to) {
	web_con[to] = vector<string>();
}

void AdjacencyList::AddConAsKeyM(string from) {
	con_list[from] = vector<string>();
}

void AdjacencyList::AddWebpage(string from, string to) {
	//if not already added to graph, add "from" to graph
	if (!CheckInList(from)) {
		//not in map -> add
		AddNewWebpage(from, to);
	}
	else {
		//add con to vector for key in map 
		AddCon(from, to);
	}
	//if not already added to graph, add "to" to graph 
	if (!CheckInList(to)) {
		//not in map -> add
		AddConAsKey(to);
	}


	//make M matrix for PI
	if (!CheckInM(to)) { 
		//not in map -> add
		AddNewWebpageM(from, to);
	}
	else {
		//add con to vector for key in map 
		AddConM(from, to);
	}
	//if not already added to graph, add "to" to graph 
	if (!CheckInM(from)) { 
		//not in map -> add
		AddConAsKeyM(from); 
	}
}

void AdjacencyList::Print(map<string, float> r) {
	for (auto element : r) {
		cout << element.first << " " << fixed << setprecision(2) << element.second << endl;
	}
}

void AdjacencyList::PowIt(int power_iterations) {
	float intial = 1.00 / web_con.size();
	map<string, float> r;
	map<string, float> temp; 

	//intialize r matrix to 1/# of webpages inputted 
	for (auto ele : web_con) {
		r[ele.first] = intial;
	}

	//calculate solution by replacing the r map with the new matrix 
	for (int u = 0; u < power_iterations - 1; u++) {
		for (auto mem : web_con) {
			float total = 0;
			for (int i = 0; i < con_list[mem.first].size(); i++) {
				total += (1.00 / (web_con[con_list[mem.first][i]].size())) * r[con_list[mem.first][i]]; 
			}
			temp[mem.first] = total; 
			
		}

		for (auto vect : temp) {
			r[vect.first] = vect.second;
		}

	}

	Print(r);
}

vector<float> AdjacencyList::Testing(int power_iterations) {  
	float intial = 1.00 / web_con.size();
	map<string, float> r;
	map<string, float> temp;

	for (auto ele : web_con) {
		r[ele.first] = intial;
	}

	for (int u = 0; u < power_iterations - 1; u++) {
		for (auto mem : web_con) {
			float total = 0;
			for (int i = 0; i < con_list[mem.first].size(); i++) {
				total += (1.00 / (web_con[con_list[mem.first][i]].size())) * r[con_list[mem.first][i]];
			}
			temp[mem.first] = total;

		}

		for (auto vect : temp) {
			r[vect.first] = vect.second;
		}

	}

	vector<float> v;

	for (auto e : r) {
		v.push_back(e.second);
	}
	
}

