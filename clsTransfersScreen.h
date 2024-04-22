#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransfersScreen : protected clsScreen
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

	static string readAccountNumber() {

		cout << "Account Number: ";
		string accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExist(accountNumber)) {

			cout << "Account number doesnt exist, please entre another one:\n";
			cout << "Account Number: ";
			accountNumber = clsInputValidate::readString();
		}

		return accountNumber;
	}

public:

	static void showTransferScreen() {

		_drawScreenHeader("\t   Transfers");

		//_______________________________________________________________________

		cout << "Transfer From...\n";
		string fromAccNumber = readAccountNumber();

		clsBankClient fromClient = clsBankClient::findClient(fromAccNumber);
		cout << "\nTransfer from account " << fromClient.getAccountNumber();
		_printClientCard(fromClient);

		//_______________________________________________________________________

		cout << "\nTransfer To...\n";
		string toAccNumber = readAccountNumber();

		while (toAccNumber == fromAccNumber) {

			cout << "Error !! can't transfer to same account!!\n";
			cout << "Transfer To...\n";
			toAccNumber = readAccountNumber();
		}

		clsBankClient toClient = clsBankClient::findClient(toAccNumber);
		cout << "\nTransfer to account " << toClient.getAccountNumber();
		_printClientCard(toClient);

		//_______________________________________________________________________

		cout << "\nTransfer amount: ";

		double transferAmount;

		while ((transferAmount = clsInputValidate::ReadDblNumber()) < 0) {

			cout << "\nError!! transfer amount must be a positive number...\n";
			cout << "\nTransfer amount: ";
		}
		
		cout << "\nAre you sure you want to deposit " << transferAmount << " from account " << fromAccNumber << " to " << toAccNumber << " ? y/n : ";

	//	//__________________________________________________________________________

		if (clsInputValidate::readChar() == 'y') {

			if (fromClient.transfer(toClient, transferAmount)) {

					cout << "Transfer succeeded";
			}

			else {
				cout << "Transfer Failed!! Not enough balance";
			}
		}

		else {

			cout << "Transfer Canceled";
		}
	}


};
