#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>




class clsClientListScreen : protected clsScreen
{

private:

    static void _printClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.pinCode;
        cout << "| " << setw(12) << left << Client.accountBalance;

    }


public:

    static void showClientList() {


        vector<clsBankClient> vClientsRecord = clsBankClient::getClientsRecord();


        string subTiltle = "           " + to_string(vClientsRecord.size()) + " Clients";

        _drawScreenHeader("          Clients List", subTiltle);

        cout << "\n\t\t\t\t\tClient List (" << vClientsRecord.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClientsRecord.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClientsRecord)
            {

                _printClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

