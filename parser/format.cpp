#include <iostream>

#include "format.h" 

using namespace std;

int convertToLowerCase(vector<string> &lines, vector<string> &new_lines)
{
    string line;
    string temp_line;
    locale loc;

    for (int index = 0; index < lines.size(); index++) {
        line = lines[index];
        temp_line = line;
        for (int index1 = 0; index1 < line.length(); index1++) {
            temp_line[index1] = tolower(line[index1], loc);
        }

        new_lines.push_back(temp_line);
    }

    return 0;
} 

int removeWhitespace(vector<string> &lines, vector<string> &new_lines)
{
    int line_size;
	string line;

    line_size = 0;

	for (int k = 0; k < lines.size(); k++) {
		line = lines[k];
        line_size = lines[k].length();

        for (int j = 0; j < line_size; j++) {
            if (line[j] == ' ') {
                line.erase(line.begin() + j);

                j--;
            }
        }

        new_lines.push_back(line);
	}

    return 0;
}

int formatTextLines(vector<string> &lines_from_input_file, vector<string> &formatted_lines) 
{
    vector<string> interm_lines;

    if ((removeWhitespace(lines_from_input_file, interm_lines)) < 0) {
        //cout <<"Error: in removeWhitespace" <<endl;
        return -1;
    } 

    if ((convertToLowerCase(interm_lines, formatted_lines)) < 0){
        //cout <<"Error: in convertToLowerCase" <<endl;
        return -2;
    }

    return 0;
}