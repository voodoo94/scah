#include <iostream>

#include "utilities.h"

using namespace std;

int getLevelCount(vector<string> &formatted_lines)
{
    string line;
    int level_count;

    level_count = 0;

    for (int index = 0; index < formatted_lines.size(); index++) {
        line = formatted_lines[index];

        // Check if first 5 characters are 'l', 'e', 'v', 'e', 'l'.
        // followed by a space.
        if (line[0] == 'l') {
            if (line[1] == 'e') {
                if (line[2] == 'v') {
                    if (line[3] == 'e') {
                        if (line[4] == 'l') {
                            if (isdigit(line[5])) {
                                level_count++;
                            } else {
                                continue;
                            }
                        } else {
                            continue;
                        }
                    } else {
                        continue;
                    }
                } else {
                    continue;
                }
            } else {
                continue;
            }
        } else {
            continue;
        }
    }

    return level_count;
}

int getModuleCount(vector<symtab> symbolTable) 
{
    return symbolTable.size();
}

void printVector(vector<string> lines_from_input_file) 
{
    int i;

    for (i = 0; i < lines_from_input_file.size(); i++) {
        cout <<lines_from_input_file[i] <<endl;
    }
}