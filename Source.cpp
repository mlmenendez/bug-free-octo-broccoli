#include <iostream>
#include <stdlib.h>
#include "AmazonQuestions.h"
#include "AppleQuestions.h"
#include "FacebookQuestions.h"
#include "GoogleQuestions.h"
#include "MicrosoftQuestions.h"
#include "StereotypicalQuestions.h"

using namespace std;

int main() {
	bool exit = false;
	while (exit == false) {
		int selection = 0;
		cout << "Who's quesstions would you like to see?" << endl
			<< "Google's = 1 " << endl << "Apple's = 2 " << endl
			<< "Amazon's = 3 " << endl << "Facebook's = 4 " << endl
			<< "Microsoft's = 5 " << endl << "Stereotypical = 6 " << endl
			<< "And to exit, enter '0'" << endl;
		cin >> selection;
		switch (selection) {
		case'1': {
			GoogleQuestions();
		case'2':
			AppleQuestions();
		case'3':
			AmazonQuestions();
		case'4':
			FacebookQuestions();
		case'5':
			MicrosoftQuestions();
		case'6':
			StereotypicalQuestions();
		case'0':
			exit = true;
		}
		system("cls");
	}
	
	return 0;
}