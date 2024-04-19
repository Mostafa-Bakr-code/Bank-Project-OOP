#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
#include <iomanip>


class clsUpdateClientScreen : protected clsScreen
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

    static void updateClient() {

        _drawScreenHeader("          Update client");

        cout << "Account Number: ";
        string accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber)) {

            cout << "Account number doesn't exist...\n";
            cout << "Account Number: ";
            accountNumber = clsInputValidate::readString();

        }
        clsBankClient Client = clsBankClient::findClient(accountNumber);

        
        cout << "\n\nUpdate Client... \n";
        clsUpdateClientScreen::_readClientInfo(Client);


        if (Client.Save() == clsBankClient::enSaveResults::svFailedEmptyObj) {

            cout << "\nOoops!! file coudn't be saved because object is empty...\n";
        }

        else {
            cout << "\nSaved Sucssefully :)\n";
            _printClientCard(Client);
        }

    }


};

