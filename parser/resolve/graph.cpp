#include "graph.h"

using namespace std;

extern string symbol_table[20];

vector<string> buildGraph(vector<string> &lines) 
{
	string line;
	int level = -1;
	vector<nodes> 

	for (int index = 0; index < lines.size(); index++) {
		line = lines[index];

		if ((isLevel(line)) == 0) {
			level++;
		} else {
			// We build the nodes here.
			// nodes will intitally be in an unsorted array.

		}
	}
}