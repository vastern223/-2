#include "Header.h"
#include<list>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

list<registration>registrations;
const string filename = "registrations.txt";

void init()
{

	ifstream fin;
	fin.open(filename);
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		int currentString = 0;
		string data1;
		registration new1registration;
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data1);
			if (currentString == 1)
			{
				new1registration.FullName = data1;
			}

			else if (currentString == 2)
			{
				new1registration.mail = data1;
			}
			else if (currentString == 3)
			{
				new1registration.Password = data1;
				currentString = 0;
				registrations.push_back(new1registration);
				new1registration = registration();
			}
		}
	}
	fin.close();
	PAUSE
	CLEAR
}

void addnewregistration()
{
	registration newregistration;
	cout <<"enter name for new registration ->";
	cin.ignore();
	getline(cin, newregistration.FullName);
	cout <<"enter mail for new registration->";
	getline(cin,newregistration.mail);
	fstream fin;
	fin.open(filename);
	if (!fin)
	{
		cout << "Error: aplication not connected to database file :)" << endl;
	}
	else {
		string data3;
		while (!fin.eof())
		{
			data3 = "";
			fin >> data3;
			if (newregistration.mail == data3)
			{
				cout << "Such email already exists, try entering another email"<<endl;
				return;
			}
		}
	}
	fin.close();
	cout <<"Enter Password for new registration->";
	getline(cin, newregistration.Password);
	registrations.push_back(newregistration);
	ofstream fout;
	fout.open(filename, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == false)
	{
		cout << "Error: aplication not connected to database file :)" << endl;
	}
	else
	{
		fout << newregistration.FullName<< " ";
		fout << newregistration.mail<<" ";
		fout << newregistration.Password<< endl;
	}
	
	fout.close();
	cout << "A new contact has been created\n";
	PAUSE
	CLEAR
}
void Logging_in()
{
	string name;
	string mail1;
	string Password1;
	cout << "enter name->";
	cin.ignore();
	getline(cin,name);
	cout << "enter mail->";
	getline(cin,mail1);
	cout << "enter Password->";
	getline(cin,Password1);
	ifstream fin;
	fin.open(filename);
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "file not open" << endl;
	}
	else
	{
		string data;
		
		while (!fin.eof())
		{
			data = "";
			
			getline(fin,data);
			
			if (data == name+" "+mail1+" "+Password1)
			{
				cout << "hello :" << name << endl;
			}
			else{
				cout << "Data entered incorrectly" << endl;
			}
		}
	}
	fin.close();
	PAUSE
    CLEAR
}


	
	
	
