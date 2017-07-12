#include "FacebookQuestions.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


FacebookQuestions::FacebookQuestions()
{
}

void FacebookQuestions::Question_1()
{
	//TODO: Raise a double to a given  int power, including negative powers
	double x;
	int y;
	double result = 0;
	cout << "Enter base number: " << endl;
	cin >> x;
	cout << "Enter power value: " << endl;
	cin >> y;

	//result = pow(x, y); 
	//this is the easiest way or if needed to do by hand....
	//....with whole numbers:
	//if using fractional powers, the algorithm will need to be changed

	if (y > 0) {
		result = x;
		for (int i = 0; i < y; i++) {
			result = result * x;
		}
	}
	else if (y == 0) {
		result = 1;
	}
	else {
		result = 1/x;
		for (int i = 0; i > y; i--) {
			result = result * (1 / x);
		}
	}
	cout << "Result is: " << result << endl;
	return;
}

void FacebookQuestions::Question_2(){
	//You are given an array of integers and are asked to delete an integer from the array. Condense the array so no empty spaces
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
	for (int i = 0; i < start.size();  i++) {
		if (start[i] == del) {
			i++;
		}
		end[i] = start[i];
	}


	return;
}


void FacebookQuestions::Question_3(){
	//Impliment a balance of paraenthesis where it will return a string with only the balanced paraenthesis
	cout << "This exercises has already been done. See: Data Structures tree. Specifically the Stack portion. I may upload"
		<< " the miniture parser assignment I did if I can find the source on my old hard drive." << endl;
	return;
}

void FacebookQuestions::Question_4(){
	//Print a linked list in reverse in constant time
	cout << "To do this, see the Data Structures Branch, specifically the Linked List implementaion. " <<
		"There is a linked list with a tail pointer on each node as well as a last node pointer. I have actually needed to "
		<< "preform this exercise for a test and just made it part of my staple when I manually implement it" << endl;

}

FacebookQuestions::~FacebookQuestions()
{
}
