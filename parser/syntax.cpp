#include "syntax.h"

using namespace std;

int checkSyntax(vector<string> &lines)
{
	int length_line = 0;
	string line;

	// Simple check. See if each line ends with a '.'. Only then it is valid.
	for (int i = 0; i < lines.size(); i++) {
		line = lines.at(i);
		length_line = line.length();

		if (line.at(length_line - 1) != '.') {
			return -1;
		}
	}

	return 0;
}