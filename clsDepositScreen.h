#pragma once


#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsDepositScreen : protected clsScreen
{

private:

    static void _printClientCard(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirst Name     : " << Client.firstName;
        cout << "\nLast Name      : " << Client.lastName;
        cout << "\nFull Name      : " << Client.getFullName();
        cout << "\nEmail          : " << Client.Email;
        cout << "\nPhone          : " << Client.Phone;
        cout << "\nAccount Number : " << Client.getAccountNumber();
        cout << "\nPassword       : " << Client.getPinCode();
        cout << "\nBalance        : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

public:

	static void showDepositScreen() {

        _drawScreenHeader("          Deposit Screen");

        cout << "Account Number: ";
        string accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber)) {

            cout << "Account number doesn't exist...\n";
            cout << "Account Number: ";
            accountNumber = clsInputValidate::readString();

        }
        clsBankClient Client = clsBankClient::findClient(accountNumber);

        _printClientCard(Client);

        cout << "Entre amount of money you want to deposit? ";
        double depositAmount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to deposite " << depositAmount << " to account " << accountNumber << " y/n\n";

        if (clsInputValidate::readChar() == 'y') {

            if (Client.Deposit(depositAmount)) {

                cout << "\nDeposited Sucessefully...\n";
                cout << "New Account Balance is " << Client.accountBalance << endl;
            }

            else {
                cout << " Operation Failed...\n";
                cout << "Deposit amount must be positive value...";
            }
        }

        else {
            cout << "Operation Canceled ...\n";
        }
	}

};

