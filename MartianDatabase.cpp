#include "MartianDatabase.h"

//Construct empty Database using filename
MartianDatabase::MartianDatabase(string filename) {
	readIn(filename);
	int size = 0;
	while (size < m_pointers.size() - 1) {
		m_sorted_l_name.push_back(m_pointers[size]);
		m_sorted_f_name.push_back(m_pointers[size]);
		m_sorted_ID.push_back(m_pointers[size]);
		size++;
		addedNewMartian = true;
	}
}
//add item m to the database
void MartianDatabase::addMartian(Martian *m) {
	m_pointers.push_back(m);
	m_sorted_f_name.push_back(m);
	m_sorted_l_name.push_back(m);
	m_sorted_ID.push_back(m);
	addedNewMartian = true;

}
//delete M and return true if it works
//search the ID then delete that specific entry
bool MartianDatabase::deleteMartian(int ID) {
	int size = 0;
	while (size < m_sorted_ID.size()) {
		if (m_sorted_ID[size]->id == ID) {
			m_sorted_ID.erase(m_sorted_ID.begin() + size);
			addedNewMartian = true;
		}
		size++;
	}
	size = 0;
	while (size <m_sorted_f_name.size()) {
		if (m_sorted_f_name[size]->id == ID) {
			m_sorted_f_name.erase(m_sorted_f_name.begin() + size);
			addedNewMartian = true;
		}
		size++;
	}
		size = 0;
	while (size <m_sorted_l_name.size()) {
		if (m_sorted_l_name[size]->id == ID) {
			m_sorted_l_name.erase(m_sorted_l_name.begin() + size);
			addedNewMartian = true;
		}
		size++;
	}
	size = m_pointers.size() - 1;
	while (size < m_pointers.size()) {
		if (m_pointers[size]->id == ID) {
			m_pointers.erase(m_pointers.begin() + size);
			addedNewMartian = true;
		}
		size++;
	}
	return true;

}
//return true if empty
bool MartianDatabase::isEmpty() {
	if (m_pointers.size()==0){
		cout << "Empty Database" << endl;
		return true;
	}
	
	else {
		cout << "Database is not empty" << endl;
		return false;
	}
}
//return true if database is full (100 martians)
bool MartianDatabase::isFull() {
	cout << "Database is not full" << endl;
	return false;
}
//cout m.f_name m.l_name m.id in order they are in the db, sorted by f_name, sorted by l_name, sorted by ID
void MartianDatabase::printMartians() {
	if (addedNewMartian == true) {
		sortMartians(m_sorted_f_name,m_sorted_l_name,m_sorted_ID);
	}
	int size = 0;
	cout << endl << "Martian Database, unordered: " << endl << endl << endl;
	while (size < m_pointers.size()) {
		cout << m_pointers[size]->f_name << " " << m_pointers[size]->l_name << " " << m_pointers[size]->id << endl;
		size++;
	}
	size = 0;
	cout << endl << "Martain Database, sorted by First Name: " << endl << endl << endl;
	while (size < m_sorted_f_name.size()) {
		cout << m_sorted_f_name[size]->f_name << " " << m_sorted_f_name[size]->l_name << " " << m_sorted_f_name[size]->id << endl;
		size++;
	}
	size = 0;
	cout << endl << "Martain Database, sorted by Last Name: " << endl << endl << endl;
	while (size < m_sorted_l_name.size()) {
		cout << m_sorted_l_name[size]->l_name << " " << m_sorted_l_name[size]->f_name << " " << m_sorted_l_name[size]->id << endl;
		size++;
	}
	size = 0;
	cout << endl <<"Martain Database, sorted by ID: " << endl << endl << endl;
	while (size < m_sorted_ID.size()) {
		cout << m_sorted_ID[size]->id << " " << m_sorted_ID[size]->f_name << " " << m_sorted_ID[size]->l_name << endl;
		size++;
	}
	cout << endl;

}
MartianDatabase::~MartianDatabase() {
	int size = m_pointers.size() - 1;
	while (size != 0) {
		Martian* mp;
		mp = m_pointers[size];
		delete mp;
		size--;
	}
	size = m_sorted_f_name.size() - 1;
	while (size != 0) {
		Martian* mp;
		mp = m_sorted_f_name[size];
		delete mp;
		size--;
	}
	size = m_sorted_l_name.size() - 1;
	while (size != 0) {
		Martian*mp;
		mp = m_sorted_l_name[size];
		delete mp;
		size--;
	}
	size = m_sorted_ID.size() - 1;
	while (size != 0) {
		Martian*mp;
		mp = m_sorted_ID[size];
		delete mp;
		size--;
	}
}

void MartianDatabase::sortMartians(vector<Martian*> &m_sorted_f_name, vector<Martian*> &m_sorted_l_name, vector<Martian*> &m_sorted_ID) {
	
	sort(m_sorted_f_name.begin(), m_sorted_f_name.end(), MartianFNameCompare);
	sort(m_sorted_l_name.begin(), m_sorted_l_name.end(), MartianLNameCompare);
	sort(m_sorted_ID.begin(), m_sorted_ID.end(), MartianIDCompare);
	addedNewMartian = false;
	return;
	
}
bool MartianDatabase::MartianFNameCompare(Martian* a, Martian* b) {
	if (a->f_name < b->f_name) {
		return true;
	}
	else {
		return false;
	}
}
bool MartianDatabase::MartianLNameCompare(Martian* a, Martian*b) {
	if (a->l_name < b->l_name) {
		return true;
	}
	else {
		return false;
	}
}
bool MartianDatabase::MartianIDCompare(Martian* a, Martian*b) {
	if (a->id < a->id) {
		return true;
	}
	else {
		return false;
	}
}
//take input and decide what to call
void MartianDatabase::options(string input) {
	if (input == "add") {
		string f_name;
		string l_name;
		int id;
		cout << "Enter Martian first name " << endl;
		cin >> f_name;
		cout << "Enter Martian last name " << endl;
		cin >> l_name;
		cout << "Enter Martian ID " << endl;
		cin >> id;
		Martian* m = new Martian;
		m->f_name = f_name;
		m->l_name = l_name;
		m->id = id;
		addMartian(m);
	}
	else if (input == "empty") {
		isEmpty();
	}
	else if (input == "full") {
		isFull();
	}
	else if (input == "print") {
		printMartians();
	}
	else if (input == "delete") {
		cout << "Enter ID to be deleted" << endl;
		int ID;
		cin >> ID;
		deleteMartian(ID);
	}
	else {
		return;
	}

}
void MartianDatabase::readIn(string filename) {
	fstream infile(filename);
	if (!infile) {
		cout << "Database opening failed..." << endl;
		exit(1);
	}
	int size = 0;
	int numMartians = 0;
	string lname;
	string fname;
	int IDnum;

	while (infile >> lname && infile >> fname && infile >> IDnum) {
		Martian * marvin = new Martian;
		marvin->f_name = fname;
		marvin->l_name = lname;
		marvin->id = IDnum;
		m_pointers.push_back(marvin);
	}
	//while (infile.eof() != true) {
	//	string in;
	//	int string_it = 0;
	//	int martian_field = 0;
	//	int field_entry = 0;
	//	Martian* marvin = new Martian;
	//	getline(infile, in);
	//	if (martian_field == 0) {
	//		while (in[string_it] != ' ') {
	//			marvin->f_name[field_entry] = in[string_it];
	//			string_it++;
	//			field_entry++;
	//		}
	//		while (in[string_it] == ' ') {
	//			string_it++;
	//		}
	//		martian_field++;
	//		field_entry = 0;
	//	}
	//		if (martian_field == 1) {
	//			while (in[string_it] != ' ') {
	//				marvin->l_name[field_entry] = in[string_it];
	//				field_entry++;
	//				string_it++;
	//		}
	//			while (in[string_it] == ' ') {
	//				string_it++;
	//			}
	//			martian_field++;
	//			field_entry = 0;
	//	}
	//		if (martian_field == 2) {
	//			while (in[string_it] != ' ') {
	//				marvin->id[field_entry] = in[string_it];
	//				field_entry++;
	//				string_it++;
	//			}
	//		}
	//		m_pointers.push_back(marvin->self);
	//		numMartians++;
	//}
}
