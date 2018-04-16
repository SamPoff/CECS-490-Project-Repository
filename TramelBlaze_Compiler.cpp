#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

string readFile(void);
void writeFile(string source);

string readSourceText() {
	string source;
	ifstream txt("file.txt");

	if (!(txt.is_open())) {
		cout << "Unable to open file." << endl;
		return 0; //end program if file doesn't open
	}
	
	//allocate string variable size from file
	txt.seekg(0, ios::end);
	source.reserve(txt.tellg());
	txt.seekg(0, ios::beg);
	

	//read file into string variable
	source.assign((istreambuf_iterator<char>(txt)),
		istreambuf_iterator<char>());
	txt.close();
	return source;
}
void writeSourceText(string source) {
	ofstream text("file.txt");
	text << source;
	text.close();
}