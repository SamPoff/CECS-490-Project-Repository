
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <regex>

using namespace std;

string readSourceText() {

	string source;
	ifstream txt("sample.c");

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
	ofstream text("sample.c");
	text << source;
	text.close();
}

int main() {

    string delimiters[7] = { "int", "main", "\t", " ", ";", "<", "=" };

    //string token = read_out.substr( 0, read_out.find( type_int ));

    size_t pos = 0;
    string token;
    while ( ( pos = s.find( delimiter ) ) != std::string::npos) {
    token = s.substr(0, pos);
    cout << token << endl;
    s.erase( 0, pos + delimiter.length() );
    }

    // Read in the
    string read_out = readSourceText();
    //cout << token << endl;

}

