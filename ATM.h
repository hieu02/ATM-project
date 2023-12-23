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
	int pin;
	vector<string> friendlyAccounts;
	double balance;
public:
	// default constructor
	UserAccount();
	//setter, getter
	void getID();
	void setPin();

	//login

	// function to interact with file:
	bool inputAccountData(UserAccount& User_Account);
	void createAccountFile(const UserAccount& account);
	void createAccount(string id, int pin, double amount);
	// function to generate random id
	string generateRandomID();
	//function to create new account
	void createAccount(string id, int pin, double amount);
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

class Menu : public UserAccount
{
public:
	//function to display the login and create account menu
	void displayMenu();
	//function to display the account menu
	void displayMainMenu();
};