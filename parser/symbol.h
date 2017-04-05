#include <string>
#include <vector>

using namespace std;

typedef struct symtab {
	string module_name;
	vector<int> line_numbers;
	vector<int> dep_type;
}symtab;

int addSymbol(string, int, int, int);
int lookup(string);
void printSymbol(vector<symtab>);
vector<symtab> getSymbolTable(void);






