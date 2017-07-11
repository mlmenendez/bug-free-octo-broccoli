#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Martian {
	string f_name;
	string l_name;
	int id;
};
class MartianDatabase {
public:
	void options(string);
	MartianDatabase(string);
	void addMartian(Martian*);
	bool isEmpty();
	bool isFull();
	void printMartians();
	bool deleteMartian(int);
	void sortMartians(vector<Martian*> &, vector<Martian*> &, vector<Martian*> &);
	static bool MartianLNameCompare(Martian*, Martian*);
	static bool MartianIDCompare(Martian*, Martian*);
	static bool MartianFNameCompare(Martian*, Martian*);
	void readIn(string);
	~MartianDatabase();
private:
	vector<Martian*> m_pointers;
	vector<Martian*> m_sorted_l_name;
	vector<Martian*> m_sorted_f_name;
	vector<Martian*> m_sorted_ID;
	bool addedNewMartian = false;
};
