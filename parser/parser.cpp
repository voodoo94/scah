#include <iostream>
// For case conversion.
#include <locale>

#include "parser.h"
#include "symbol.h"

using namespace std;

// Global variables.
//extern string symbol_table[20][2];

// Funtion prototypes.
int parser(char*);

// Preparation phase.
extern int readFileToStringVector(char*, vector<string>&);
extern int removeWhitespace(vector<string>&, vector<string>&);
extern int convertToLowerCase(vector<string>, vector<string>&);
extern int formatTextLines(vector<string>&, vector<string>&);

extern int getLevelCount(vector<string>&);
extern int getModuleCount(vector<symtab>);

extern int checkSyntax(vector<string>&);

// Tokenizing.
extern vector<symtab> tokenize(vector<string>&);

// For debugging. Will be taken out once tested.
extern void printVector(vector<string>);

extern void printSymbolTable(vector<symtab>);

/*
 * DOCUMENTATION:
 * This function opens the input .flow file, reads the content line by line 
 * and copies each line to a vector of strings.
 * 
 * Each line in the input file is read and stored in the string 'line'.
 * This is done by using the getline function which fetches a line and 
 * can be iterated to fetch successive lines. 
 * lines_from_input_file.push_back(line) places 'line' in the vector.
 * 
 * Once the whitespaces are removed, the parser then checks for syntax errors.
 */
int parser(char *file_name)
{
    int levels;
    int modules_count;
    int status;
    int return_status;
    string *sym;
    vector<string> lines_from_input_file;
    vector<string> formatted_lines;
    vector<symtab> symbol_table;

    levels= 0;
    modules_count = 0;

    return_status = readFileToStringVector(file_name, lines_from_input_file);

    if (return_status == -1) {
        cout <<"Error: An unknown error occured in readFileToStringVector function." <<endl;

        return -1;
    } else {
        return_status = formatTextLines(lines_from_input_file, formatted_lines);

        if (return_status == -1) {
            cout <<"Error: An unknown error occured while removing whitespaces." <<endl;
            return -2;
        } else if (return_status == -2) {
            cout <<"Error: An unknown error occured while converting the text into lower case." <<endl;

            return -2;
        }

        return_status = checkSyntax(formatted_lines);

        if (return_status == -1) {
            return -3;
        }

        levels = getLevelCount(formatted_lines);

        cout << "Level count : " <<levels <<endl <<endl;

        symbol_table = tokenize(formatted_lines);

        printSymbolTable(symbol_table);

        cout <<"Number of modules : " <<getModuleCount(symbol_table) <<endl;

        if (return_status == -1) {
            cout <<"Error: Aborting." <<endl;
        }

        return 0;
    }
}

int main(int argc, char *argv[]) 
{
    int return_code;

    if (argc != 2) {
        printf("Error: Missing .flow input file\n");

        return -1;
    } else {  
        return_code = parser(argv[1]);

        if (return_code == -1) {
            cout <<"Error Info : Unable to copy file to a string vector. Check syntax?" <<endl;
        } else if (return_code == -2) {
            cout <<"Error Info : Unable to format the input file. Check syntax?" <<endl;
        } else if (return_code == -3) {
            cout <<"Error Info : Each line in the .flow file should end with a '.'. Syntax Error has occured" <<endl;
        }
    }
    return 0;
}