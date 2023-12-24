#include "UserAccount.h"

int main()
{
	UserAccount u;
	int option = 0;
	const int login = 1;
	const int signIn = 2;
	const int exit = 3;

	do 
	{
		cout << "ATM" << endl;
		cout << login << ". Log in" << endl;
		cout << signIn << ". Sign in" << endl;
		cout << exit << ". Exit" << endl;
		cout << "Please pick an option: ";
		cin >> option;
		switch (option) 
		{
		case (login):
			u.login(u);
			break;
		case (signIn):
			u.createAccount(u);
			break;
		case (exit):
			return 0;
		default:
			cout << "Please pick a valid option!!" << endl;
			break;
		}
	} while (option > 0 || option < 3);
}