#pragma once
#include"iostream"
#include<string>
using namespace std;
#define CLEAR system("cls");
#define PAUSE system("pause");
struct registration
{
	string FullName;
	string mail;
	string Password;
};
void addnewregistration();
void init();
void Logging_in();