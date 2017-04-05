#include <iostream>

#include "symbol.h"

using namespace std;

//vector<string> symbol_table;

vector<symtab> symbol_table;

vector<symtab> getSymbolTable(void)
{
	return symbol_table;
}

// TODO: Change the code so that values get added to the map. 
int addSymbol(string name, int line_number, int dep_stat, int exists) 
{
	// Copy the module name on to the symbol table.
	if (name[0] == 'l' && name[1] == 'e' && name[2] == 'v' && name[3] == 'e' && name[4] == 'l') {
		// Skip because you dont need to store this label.
		;
	} else {
		if (exists == 0) {
			symtab symbol;
			vector<int> line_numbers;
			vector<int> dep_status;

			line_numbers.push_back(line_number);
			dep_status.push_back(dep_stat);

			symbol.module_name = name;
			symbol.line_numbers = line_numbers;
			symbol.dep_type = dep_status;

			symbol_table.push_back(symbol);
		} else {
			for (int index = 0; index < symbol_table.size(); index++) {
				if ((symbol_table.at(index).module_name.compare(name)) == 0) {
					symbol_table.at(index).line_numbers.push_back(line_number);
					symbol_table.at(index).line_numbers.push_back(dep_stat);

					break;
				}
			}
		}
	}

	return 0;
}

// TODO: Change code to adapt it to lookup a map insteat of a 2D-array.
int lookupSymbol(string name)
{
	int symbol_status;

	symbol_status = 0;

	for (int index = 0; index < symbol_table.size(); index++) {
		if ((symbol_table.at(index).module_name.compare(name)) == 0) {
			// Match found. Set the status to 1.
			symbol_status = 1;
		}
	} 

	if (symbol_status == 0) {
		// The symbol is not present in the table. Add it.
		return 0;
	} else {
		// The symbol is present already. No need to add.
		return 1;
	}
} 

void printSymbolTable(vector<symtab> symbol_table)
{
	for (int index = 0; index < symbol_table.size(); index++) {
		// Check if the column is empty. Print only when it has content.
		for (int i = 0; i < symbol_table.at(index).line_numbers.size(); i++) {
			cout <<symbol_table.at(index).module_name <<" : : ";
			cout <<symbol_table.at(index).line_numbers.at(i) <<" : : ";
			cout <<symbol_table.at(index).dep_type.at(i) <<endl;
		}
	}
}