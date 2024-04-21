#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>



class clsAddNewClientScreen : protected clsScreen 
{
private:

    static void _readClientInfo(clsBankClient& Client) {

        cout << "First Name: ";
        Client.firstName = clsInputValidate::readString();
        cout << "Last Name: ";
        Client.lastName = clsInputValidate::readString();
        cout << "Email: ";
        Client.Email = clsInputValidate::readString();
        cout << "Phone: ";
        Client.Phone = clsInputValidate::readString();
        cout << "Pin-Code: ";
        Client.pinCode = clsInputValidate::readString();
        cout << "Account Balance: ";
        Client.accountBalance = clsInputValidate::ReadFloatNumber();

    }

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


    static void addNewClient() {

        _drawScreenHeader("          Add New Client");

        cout << "Account Number: ";
        string accountNumber = clsInputValidate::readString();

        while (clsBankClient::isClientExist(accountNumber)) {

            cout << "Account number already exist...\n";
            cout << "Account Number: ";
            accountNumber = clsInputValidate::readString();
        }

        cout << "Add New Client... \n";

        clsBankClient Client = clsBankClient::getNewClientObject(accountNumber);

       _readClientInfo(Client);

        if (Client.Save() == clsBankClient::enSaveResults::svSucceeded) {

            cout << "\nSaved Sucssefully :)\n";
        }
        else {
            cout << "\nOoops!! file coudn't be saved because Account number already exists...\n";
        }

        _printClientCard(Client);
    }

};

