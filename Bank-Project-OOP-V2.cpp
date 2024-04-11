#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"


using namespace std;

void printClientRecordBalanceLine(clsBankClient Client) {

    cout << "| " << setw(15) << left << Client.getAccountNumber();
    cout << "| " << setw(40) << left << Client.getFullName();
    cout << "| " << setw(12) << left << Client.accountBalance;
}

void showTotalBalances() {

    double totalBalances = clsBankClient::getTotalBalances();

    vector <clsBankClient> vClients = clsBankClient::getClientsRecord();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
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

int main() {
	
    clsMainScreen::showMainMenu();

	
	

}