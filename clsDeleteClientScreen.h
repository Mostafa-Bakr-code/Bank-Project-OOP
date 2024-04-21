#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
#include <iomanip>



class clsDeleteClientScreen : clsScreen
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

    static void deleteClient() {

        _drawScreenHeader("          Delete Client");

        cout << "Account Number: ";
        string accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber)) {

            cout << "Account number doesn't exist...\n";
            cout << "Account Number: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient Client = clsBankClient::findClient(accountNumber);

        _printClientCard(Client);

        cout << "\nAre you sure you want to delete this account? y/n\n";

        if (clsInputValidate::readChar() == 'y') {

            if (Client.deleteClient()) {

                cout << "\nDeleted Sucessefully...\n";
            }
            else {
                cout << "\nError Client Was not Deleted\n";
            }

        }
    }

};

