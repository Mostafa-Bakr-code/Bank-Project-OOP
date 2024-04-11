#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
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

    static void showWithdrawScreen() {

        _drawScreenHeader("          Withdraw Screen");

        cout << "Account Number: ";
        string accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber)) {

            cout << "Account number doesn't exist...\n";
            cout << "Account Number: ";
            accountNumber = clsInputValidate::readString();

        }
        clsBankClient Client = clsBankClient::findClient(accountNumber);

        _printClientCard(Client);

        cout << "Entre amount of money you want to withdraw? ";
        double withdrawAmount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to withdraw " << withdrawAmount << " from account " << accountNumber << " y/n\n";

        if (clsInputValidate::readChar() == 'y') {

            if (Client.Withdraw(withdrawAmount)) {

                cout << "\nWithdrew Sucessefully...\n";
                cout << "New Account Balance is " << Client.accountBalance << endl;
            }

            else {
                cout << "Not enough balance ...\n";
                cout << "amount withdraw is " << withdrawAmount << endl;
                cout << " your balance is " << Client.accountBalance << endl;
            }
        }

        else {
            cout << "Operation Canceled ...\n";
        }
    }

};

