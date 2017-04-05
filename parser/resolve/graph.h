#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct node {
	int level;
	string name;
	vector<node> dep;
} nodes;

vector<string> buildGraph(vector<string>&);
