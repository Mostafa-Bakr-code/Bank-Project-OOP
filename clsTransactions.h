
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransfersScreen.h"
#include "clsTransferLogsScreen.h"
#include <iomanip>



class clsTransactions : protected clsScreen
{
private:

	enum enTransactions { Deposit = 1, Withdraw = 2, totalBalances = 3, Transfers = 4, TransferLogs = 5 ,mainMenu = 6 };

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

    static void _showDepositScreen() {

        clsDepositScreen::showDepositScreen();

    }

    static void _showWithdrawScreen() {

        clsWithdrawScreen::showWithdrawScreen();
    }

    static void _showTotalBalanceScreen() {

        clsTotalBalancesScreen::showTotalBalances();
    }


    static void   _showTransfersScreen() {

        clsTransfersScreen::showTransferScreen();
    }

    static void   _showTransfersLogScreen() {

        clsTransferLogsScreen::showTransferLogsScreen();
    }

    static void _performTransactionOptions(enTransactions transactionOption) {

        switch (transactionOption) {

        case enTransactions::Deposit:

            system("cls");
            _showDepositScreen();
            _goBackToTransactionMenu();
            break;

        case enTransactions::Withdraw:

            system("cls");
            _showWithdrawScreen();
            _goBackToTransactionMenu();
            break;

        case enTransactions::totalBalances:

            system("cls");
            _showTotalBalanceScreen();
            _goBackToTransactionMenu();
            break;

        case enTransactions::Transfers:

            system("cls");
            _showTransfersScreen();
            _goBackToTransactionMenu();
            break;

        case enTransactions::TransferLogs:

            system("cls");
            _showTransfersLogScreen();
            _goBackToTransactionMenu();
            break;

        case enTransactions::mainMenu:

            break;
        }
    }

    static short _readTransactionMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _goBackToTransactionMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menu...\n";

        system("pause>0");
        showTransactionsMenu();
    }


public:

	 static void showTransactionsMenu() {

        system("cls");
        _drawScreenHeader("\tTransactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransaction Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfers.\n";
        cout << setw(37) << left << "" << "\t[5] Transfers Logs.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";

        cout << setw(37) << left << "" << "===========================================\n";

        _performTransactionOptions((enTransactions)_readTransactionMenuOption());
        
	}

};

