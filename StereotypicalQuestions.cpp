#include "StereotypicalQuestions.h"
#include <iostream>
using namespace std;



StereotypicalQuestions::StereotypicalQuestions()
{
}

void StereotypicalQuestions::FizzBuzz(){
	//Write out Fizz for multiples of 3, Buzz for multiples of 5, FizzBuzz for multiples of both
	int num = 0;
	int i = 0;
	cout << "Enter a number: " << endl;
	cin >> num;
	while (i != num) {
		if (num % 3 == 0 && num % 5 == 0) {
			cout << "FizzBuzz" << endl;
			i++;
		}
		else if (num % 5 == 0) {
			cout << "Buzz" << endl;
			i++;
		}
		else if (num % 3 == 0) {
			cout << "Fizz" << endl;
			i++;
		}
		else {
			i++;
		}
	}
	

}


StereotypicalQuestions::~StereotypicalQuestions()
{
}
