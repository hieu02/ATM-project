#include "ATM.h"

// function to read the data from the file and input them
bool UserAccount::inputAccountData(UserAccount& account)
{
    ifstream file(account.ID + ".txt");
    if (!file)
    {
        cout << "Error: Account not found." << endl;
        return false;
    }

    file >> account.pin >> account.balance;
    string friendlyAccounts;
    while (file >> friendlyAccounts)
    {
        account.friendlyAccounts.push_back(friendlyAccounts);
    }

    file.close();
    return true;
}
// function to create a new file with the user's input
void UserAccount::createAccountFile(const UserAccount& account)
{
    ofstream file(account.ID + ".txt");
    file << account.pin << " " << account.balance;
    for (const string& friendlyID : account.friendlyAccounts)
    {
        file << " " << friendlyID;
    }
    file.close();
}
//function to generate random ID
string UserAccount::generateRandomID()
{
    // generate the character to random
    const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // set maximum length of the ID
    const int idLength = 10;
    string randomID;
    srand(time(0));

    for (int i = 0; i < idLength; ++i)
    {
        // set random ID
        randomID += charset[rand() % charset.length()];
    }

    return randomID;
}
//function to create new account:
void UserAccount::createAccount(UserAccount& account)
{
    account.ID = generateRandomID();
    int userPin;
    cout << "Set your PIN (6 digits): ";
    cin >> userPin;
        if (userPin < 100000 || userPin > 1000000)
        {
            cout << "error, please set a 6 digits password: ";
            cout << "Set your PIN (6 digits): " << endl;
            cin >> userPin;
        }
    account.pin = userPin;
    account.balance = 0.0;
    createAccountFile(account);
}
void exit()
{

}
//function to display account information
void UserAccount::AccountInformation(UserAccount& account)
{
        cout << "Account ID: " << account.ID << endl;
        cout << "Balance: $" << account.balance << endl;
        cout << "friendly account: " << endl;
        for (const string& friendlyID : account.friendlyAccounts)
        {
            cout << friendlyID << " ";
        }
        cout << endl;
}
//function to withdraw the money
void UserAccount::withdraw(UserAccount& amount)
{

}
//function to deposit the money
void UserAccount::deposit()
{

}
//function to tranfer the money to friendly account
void UserAccount::transfer()
{

}
//function to exit the main menu of ATM
void UserAccount::logOut()
{

}
