#include <iostream>

#include "tokenizer.h"

using namespace std;

extern int addSymbol(string, int, int, int);
extern int lookupSymbol(string);
extern void printSymbolTable(vector<symtab>);
extern vector<symtab> getSymbolTable(void);
extern int getModuleCount(vector<symtab>);

vector<symtab> tokenize(vector<string> &formatted_lines) 
{
    string line;
    string name;
    string op;
    string term;
    string dependency;
    string first_module;

    int status;
    int index;
    int i;
    int name_count;
    int line_count;
    int lookup_status;
    int dependent;
    int exists;

    name_count = 1;
    line_count = 0;

    vector<symtab> sym;

    try {
        for (index = 0; index < formatted_lines.size(); index++) {
            line = formatted_lines[index];
            line_count++;
            dependent = 0;
            exists = 0;

            for (int index_string = 0; index_string < line.length(); index_string++) {
            	if (isdigit(line.at(index_string)) || isalpha(line.at(index_string)) || line.at(index_string) == '_') {
            		name += line.at(index_string);
            	} else if (line.at(index_string) == '>') {
            		dependency = line.at(index_string);

            		if ((lookup_status = lookupSymbol(name)) == 0) {
            			addSymbol(name, line_count, dependent, exists);
            			name_count++;
                        dependent = 1;
                        exists = 1;
                        first_module = name;
            		} else {
                        addSymbol(name, line_count, dependent, exists);
                    }

            		name.clear();
            	} else if (line.at(index_string) == ',') {
            		op = line.at(index_string);

                    if ((lookup_status = lookupSymbol(name)) == 0) {
            			addSymbol(name, line_count, dependent, exists);
            			name_count++;
                        dependent = 1;
                        exists =1;
            		} else {
                        addSymbol(name, line_count, dependent, exists);
                    }

            		name.clear();
            	} else if (line.at(index_string) == '.') {
            		term = line.at(index_string);

                    if ((lookup_status = lookupSymbol(name)) == 0) {
            			addSymbol(name, line_count, dependent, exists);
            			name_count++;
                        dependent = 1;
                        exists = 1;
            		} else {
                        addSymbol(name, line_count, dependent, exists);
                    }

            		name.clear();
            	}
            }            
        } 
    } catch (std::out_of_range &exp)  {
        cout << "Its failing here" <<endl;
    } catch (...) {
        cout <<"Some other fuckin exception" <<endl;
    }

    sym = getSymbolTable();

    return sym;
}