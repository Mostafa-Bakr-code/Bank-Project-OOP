#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsFindClientScreen : protected clsScreen
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

    static void findClient() {

        _drawScreenHeader("          Find client");

        cout << "Account Number: ";
        string accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber)) {

            cout << "Account number doesn't exist...\n";
            cout << "Account Number: ";
            accountNumber = clsInputValidate::readString();

        }
        clsBankClient Client = clsBankClient::findClient(accountNumber);

        _printClientCard(Client);
   

    }


};

