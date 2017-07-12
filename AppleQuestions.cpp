#include "AppleQuestions.h"
#include <iostream>
#include <string>

using namespace std;



AppleQuestions::AppleQuestions()
{
}

void AppleQuestions::Question_1(){
	//Find the number of '1' in an integer
	int num = 0;
	int target = 0;
	unsigned short result = 0;
	string temp;
	cout << "Enter an integer: " << endl;
	cin >> num;
	cout << "What are you trying to find? " << endl;
	cin >> target;
	temp = to_string(num);
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == target) {
			result++;
		}
		
	}
	cout << "Number found was: " << result << endl;

}


void AppleQuestions::Question_2()
{
}

void AppleQuestions::Question_3()
{
}

void AppleQuestions::Question_4()
{
}

AppleQuestions::~AppleQuestions()
{
}
