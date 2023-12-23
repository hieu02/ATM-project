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
	//login
	bool logIn(UserAccount& account);
	// function to interact with file:
	bool inputAccountData(UserAccount& account);
	void createAccountFile(const UserAccount& account);
	void updateFile(UserAccount& account);
	// function to generate random id
	string generateRandomID();
	//function to create new account
	void createAccount(UserAccount& account);
	//function to exit the login menu of the ATM
	void exit();
	//function to display account information
	void AccountInformation(UserAccount& account);
	//function to withdraw the money
	void withdraw(UserAccount& amount);
	//function to deposit the money
	void deposit();
	//function to tranfer the money to friendly account
	void transfer();
	//function to exit the main menu of ATM
	void logOut();
};

//class Menu : public UserAccount
//{
//	Menu();
//	void displayLoginMenu();
//	void displayAccountMenu();
//};