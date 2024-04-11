#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDate.h"
#include <iomanip>
#include "clsFindClientScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsTransactions.h"



using namespace std;

class clsMainScreen : private clsScreen
{

private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _readMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static  void _goBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        showMainMenu();
    }

    static void _showAllClientsScreen()
    {
       
        clsClientListScreen::showClientList();

    }

    static void _showAddNewClientsScreen()
    {
        clsAddNewClientScreen::addNewClient();

    }

    static void _showDeleteClientScreen()
    {
        clsDeleteClientScreen::deleteClient();

    }

    static void _showUpdateClientScreen()
    {
        clsUpdateClientScreen::updateClient();

    }

    static void _showFindClientScreen()
    {
       
        clsFindClientScreen::findClient();

    }

    static void _showTransactionsMenu()
    {
       
        clsTransactions::showTransactionsMenu();

    }

    static void _showManageUsersMenu()
    {
        cout << "\nUsers Menue Will be here...\n";

    }

    static void _showEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }

    static void _performMainMenuOptions(enMainMenueOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _showAllClientsScreen();
            _goBackToMainMenu();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _showAddNewClientsScreen();
            _goBackToMainMenu();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _showDeleteClientScreen();
            _goBackToMainMenu();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _showUpdateClientScreen();
            _goBackToMainMenu();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _showFindClientScreen();
            _goBackToMainMenu();
            break;

        case enMainMenueOptions::eShowTransactionsMenu:
            system("cls");
            _showTransactionsMenu();
            _goBackToMainMenu();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _showManageUsersMenu();
            _goBackToMainMenu();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _showEndScreen();
            //Login();

            break;
        }

    }



public:


    static void showMainMenu()
    {

        system("cls");
        _drawScreenHeader("\t\tMain Screen", clsDate::dateToString(clsDate::getCurrentDate()));

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Clients List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performMainMenuOptions((enMainMenueOptions)_readMainMenuOption());
    }




};

