#include<iostream>
#include<string>
#include "Header.h"

using namespace std;

int main()
{
	void init();

	int action = 0;
	do
	{
		cout << "\tMENU" << endl;
		cout << "1-Sign up" << endl;
		cout << "2-Log in" << endl;
		cout << "3-Exit" << endl;
		cout << endl;
		cout << "select action ->";
		cin >> action;

		switch (action)
		{
		case 1: {
				CLEAR
			cout << "Account Registration" << endl;
			addnewregistration();
		}break;
		case 2: {
			PAUSE
				CLEAR
			cout << "Logging in" << endl;
			Logging_in();

		}break;
		case 3: {
				CLEAR
			cout << "Goodbye" << endl;
		}break;
		default:
		{
			CLEAR

			cout << "Invalid input, enter a value from 1 to 3" << endl;
		}
		}
	} while (action != 3);


	return 0;
}