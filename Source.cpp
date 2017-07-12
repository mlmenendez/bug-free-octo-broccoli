#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "MartianDatabase.h"

using namespace std;
void readIn(string, vector<Martian> &);


int main() {
	string filename;
	string input = "";
	vector<Martian> database;
	MartianDatabase *etp;
	cout << "Enter file: " << endl;
	cin >> filename;
	etp = new MartianDatabase(filename);
	while (input != "exit") {
		cout << "What would you like to do? " << endl
			<< "Type add for adding a new Martian " << endl
			<< "Type empty to see if the database is empty " << endl
			<< "Type full to see if the database is full " << endl
			<< "Type print to print out the entire database " << endl
			<< "Type delete to delete the entry from the database " << endl
			<< "Type exit to exit " << endl;
		cin >> input;
		etp->options(input);
	}

	return 0;
}


