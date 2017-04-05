#include "prep.h"

using namespace std;

int readFileToStringVector(char *file_name, vector<string> &lines_from_input_file)
{
	string line;
    ifstream input;

    input.open(file_name, ifstream::in);

    if (input.is_open()) {
        while (getline(input, line)) {
            lines_from_input_file.push_back(line);
        }

        return 0;
    } else {
      	return -1;
    }
}