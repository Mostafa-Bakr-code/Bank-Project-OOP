#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"



class clsTotalBalancesScreen : protected clsScreen {

private:

    static void printClientRecordBalanceLine(clsBankClient Client) {

        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(40) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.accountBalance;
    }

public:

   static void showTotalBalances() {



        double totalBalances = clsBankClient::getTotalBalances();

        vector <clsBankClient> vClients = clsBankClient::getClientsRecord();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _drawScreenHeader(Title, SubTitle);

        cout << "\n\t\t\t\tTotal Balances List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                printClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << totalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(totalBalances) << ")";
    }



};


