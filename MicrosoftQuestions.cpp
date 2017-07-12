#include "MicrosoftQuestions.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;


MicrosoftQuestions::MicrosoftQuestions()
{
}

void MicrosoftQuestions::Question_1()
{
	//In a given sorted array of integers, remove all the duplicates
	vector<int> start;
	vector<int> end;
	int temp = 0;
	while (temp != -1) {
		cout << "Enter positive numbers for the inital set" << endl;
		cin >> temp;
		start.push_back(temp);
	}
	int del = 0;
	cout << "What do you want to delete? " << endl;
	cin >> del;
	for (int i = 0; i < start.size(); i++) {
		if (start[i] == del) {
			i++;
		}
		end[i] = start[i];
	}
}


void MicrosoftQuestions::Question_2()
{
	//Given a sentence, reverse the word of the words (Hello world -> world Hello)
	//geez this would be so simple in python: array.reverse() ->whaam baam
	vector<string> result;
	string input, temp;
	cout << "Enter a sentence: " << endl;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			result.push_back(temp);
			temp.clear();
		}
		else {
			temp.push_back(input[i]);
		}
	}
	for (int i = result.size(); i > 0; i--) {
		cout << result[i] << endl;
	}

}

void MicrosoftQuestions::Question_3()
{
	//take 2 strings and return true if they are anagrams
	cout << "This has already been implimented via recursion on one of my school assignments. It will be uploaded if " <<
		"found otherwise I will reimplement it" << endl;
}

MicrosoftQuestions::~MicrosoftQuestions()
{
}
