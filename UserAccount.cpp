#include "UserAccount.h"

// constructor
UserAccount::UserAccount()
{

}

void UserAccount::setID(string _id)
{
    ID = _id;
}

bool UserAccount::login(UserAccount& account)
{
    string inputID;
    double inputPin = 0;
    cout << "Enter your ID: ";
    cin >> inputID;

    if (inputAccountData(inputID, account)) 
    {
        cout << "Enter your PIN: ";
        cin >> inputPin;
        if (inputPin == account.pin)
        {
            cout << "Login successful!" << endl;
            inputAccountData(inputID, account);
            return true;
        }
        else 
        {
            cout << "Incorrect PIN. Please try again." << endl;
        }
    }
    else 
    {
        cout << "Account not found. Please check your ID." << endl;
    }

    return false;
}

// function to interact with file
bool UserAccount::inputAccountData(const string& _id, UserAccount& account)
{
    setID(_id);
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

void UserAccount::createAccountFile(const UserAccount& account)
{
    ofstream file(account.ID + ".txt");
    if (!file)
    {
        cout << "account creation failed" << endl;
    }
    else
    {
        cout << "account created sucessfully" << endl;
    }
    cout << "return to menu" << endl;
    file << account.pin << " " << account.balance;
    for (const string& friendlyID : account.friendlyAccounts)
    {
        file << " " << friendlyID;
    }
    file.close();
}

void UserAccount::updateFile(UserAccount& account)
{
    ofstream file;
    file.open(account.ID + ".txt");
    file << account.pin << account.balance;
    string friendlyAccounts;
    while (file << friendlyAccounts)
    {
        account.friendlyAccounts.push_back(friendlyAccounts);
    }
    file.close();
}

// function to generate random ID
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
    cout << "your ID is: " << account.ID << endl;
    double userPin;
    cout << "Set your PIN (6 digits): " << endl;;
    cin >> userPin;
    while (userPin < 100000 || userPin > 1000000)
    {
        cout << "error, please set a 6 digits password: ";
        cout << "Set your PIN (6 digits): " << endl;
        cin >> userPin;
    }
    account.pin = userPin;
    account.balance = 0.0;
    createAccountFile(account);
}

// function to exit the login menu
void exit()
{
    return;
}

//function to display account information
void UserAccount::AccountInformation(UserAccount& account)
{
        cout << "Account ID: " << account.ID << endl;
        cout << "Balance: $" << account.balance << endl;
        cout << "Friendly account: " << endl;
        for (const string& friendlyID : account.friendlyAccounts)
        {
            cout << friendlyID << " ";
        }
        cout << endl;
}

//function to withdraw the money
void UserAccount::withdraw(UserAccount& amount)
{
    const int opt1 = 10, opt2 = 20, opt3 = 50, opt4 = 100;
    int option = 0;
    do
    {
        cout << "input the amount to withdraw: " << endl;
        cout << "1. " << opt1 << endl;
        cout << "2. " << opt2 << endl;
        cout << "3. " << opt3 << endl;
        cout << "4. " << opt4 << endl;
        cout << "5. Other "  << endl;
        cin >> option;
        switch (option)
        {
        case(1):
        {
            if (opt1 > amount.balance)
            {
                cout << "not enough money!";
                break;
            }
            else
            amount.balance -= 10;
        }
        case(2):
        {
            if (opt2 > amount.balance)
            {
                cout << "not enough money!";
                break;
            }
            else
            amount.balance -= 20;
        }
        case(3):
        {
            if (opt3 > amount.balance)
            {
                cout << "not enough money!";
                break;
            }
            else
            amount.balance -= 50;
        }
        case(4):
        {
            if (opt4 > amount.balance)
            {
                cout << "not enough money!";
                break;
            }
            else
            amount.balance -= 100;
        }
        case(5):
        {
            int otherAmount;
            cout << "amount you want to withdraw: ";
            cin >> otherAmount;
            if (otherAmount > amount.balance)
            {
                cout << "not enough money!";
                break;
            }
            else
            {
                amount.balance -= otherAmount;
            }
        }
        }
            updateFile(amount);
    } while (option > 0 && option <= 5);
}

//function to deposit the money
void UserAccount::deposit(UserAccount& )
{
    cout << "Input the amount to deposit: ";
    int depAmount;
    cin >> depAmount;
    while (depAmount < 0)
    {
        cout << "Please input a positive number!" << endl;
        cin >> depAmount;
    }
    balance += depAmount;
    cout << "Success!"
}

//function to tranfer the money to friendly account
void UserAccount::transfer(UserAccount& account)
{
    const int option1 = 1;
    const int option2 = 2;
    int option;
    cout << option1 << "Your friendly accounts:";
    cout << option2 << "other accounts: ";
    string UserAccount = ID;
    string FriendlyAccountID;
    double amount;
    switch (option)
    {
    case (1):
    {
        for (const string& friendlyID : account.friendlyAccounts)
        {
            cout << friendlyID << " ";
        }
        cout << "input the friendly account you want to transfer: ";
        getline(cin, FriendlyAccountID);
        cout << "input the amount you want to transfer: ";
        cin >> amount;
        account.balance -= amount;
        updateFile(account);
        // subtract the balance of user
        inputAccountData(FriendlyAccountID, account);
        account.balance += amount;
        updateFile(account);
    }
    }
}

//function to exit the main menu of ATM
void UserAccount::logOut()
{
    return;
}
