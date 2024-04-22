#pragma once
#include <iostream>
#include "clsScreen.h"

class clsTransferLogsScreen : protected clsScreen
{

private:

	static void _printTransferLine(clsBankClient::stTransferLogs transferLogs)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << transferLogs.time;
		cout << "| " << setw(10) << left << transferLogs.sAccountNumber;
		cout << "| " << setw(10) << left << transferLogs.dAccountNumber;
		cout << "| " << setw(20) << left << transferLogs.amount;
		cout << "| " << setw(20) << left << transferLogs.sBalance;
		cout << "| " << setw(20) << left << transferLogs.dBalance;
		cout << "| " << setw(30) << left << transferLogs.sFullName;

	}

public:

	static void showTransferLogsScreen() {

		vector<clsBankClient::stTransferLogs> vTransfers = clsBankClient::loadTransferLogsToStVector();


		string subTiltle = "           " + to_string(vTransfers.size()) + " Transfers";

		_drawScreenHeader("         Transfer Logs", subTiltle);

		cout << "\n\t\t\t\t\tShowing (" << vTransfers.size() << ") Transfers.";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date";
		cout << "| " << left << setw(10) << "sAcc";
		cout << "| " << left << setw(10) << "dAcc";
		cout << "| " << left << setw(20) << "Amount";
		cout << "| " << left << setw(20) << "sBalance";
		cout << "| " << left << setw(20) << "dBalance";
		cout << "| " << left << setw(30) << "Name";


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransfers.size() == 0)
			cout << "\t\t\t\tNo Transfers records !";
		else

			for (clsBankClient::stTransferLogs transfer : vTransfers)
			{

				_printTransferLine(transfer);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;




	}

};

