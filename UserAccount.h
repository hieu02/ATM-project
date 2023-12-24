#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

class UserAccount
{
private:
	string ID;
	double pin;
	vector<string> friendlyAccounts;
	double balance;
public:
	// default constructor
	UserAccount();
	//setter,getter
	void setID(string);
	//login
	bool login(UserAccount& );
	// function to interact with file:
	bool inputAccountData(const string& , UserAccount& );
	void createAccountFile(const UserAccount& );
	void updateFile(UserAccount& );
	// function to generate random id
	string generateRandomID();
	//function to create new account
	void createAccount(UserAccount& );
	//function to exit the login menu of the ATM
	void exit();
	//function to display account information
	void AccountInformation(UserAccount& );
	//function to withdraw the money
	void withdraw(UserAccount& );
	//function to deposit the money
	void deposit(UserAccount&);
	//function to tranfer the money to friendly account
	void transfer(UserAccount&);
	//function to exit the main menu of ATM
	void logOut();
};

//class Menu : public UserAccount
//{
//	Menu();
//	void displayLoginMenu();
//	void displayAccountMenu();
//};
