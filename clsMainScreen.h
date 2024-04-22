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
#include "clsManageUsersScreen.h"
#include "clsGlobal.h"
#include "clsLogInRegisters.h"


using namespace std;

class clsMainScreen : private clsScreen
{

private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
        eManageUsers = 7, eLoginRegister = 8, eExit = 9
    };

    static short _readMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 8? ");
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
        clsManageUsersScreen::showManageUsersScreen();

    }

    static void _showLogInRegisters() {

        clsLogInRegisters::showLogInRegisters();
    }

    static void _logOut()
    {
        activeUser = clsUserInfo::findUser("", "");

    }

    static void _performMainMenuOptions(enMainMenueOptions MainMenuOption)
    {
        clsUserInfo::enMainMenuPermissions myPermission;

        switch (MainMenuOption)
        {

        case enMainMenueOptions::eListClients:
        {
            
            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pListClients)) {

                system("cls");
                _showAllClientsScreen();
                _goBackToMainMenu();
            }

            else {

                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");
            }

            break;
        }

        case enMainMenueOptions::eAddNewClient:

            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pAddNewClient)) {
               
                system("cls");
                _showAddNewClientsScreen();
                _goBackToMainMenu();

            }
                
            else {
                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");
            }

            break;

        case enMainMenueOptions::eDeleteClient:

            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pDeleteClient)) {

                system("cls");
                _showDeleteClientScreen();
                _goBackToMainMenu();

            }

            else {

                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");

            }

            break;

        case enMainMenueOptions::eUpdateClient:

            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pUpdateClients)) {

                system("cls");
                _showUpdateClientScreen();
                _goBackToMainMenu();

            }

            else {

                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");

            }

            break;

        case enMainMenueOptions::eFindClient:

            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pDeleteClient)) {

                system("cls");
                _showTransactionsMenu();
                _goBackToMainMenu();
            }

            else {

                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");

            }

            break;

        case enMainMenueOptions::eShowTransactionsMenu:

            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pTransactions)) {

                system("cls");
                _showTransactionsMenu();
                _goBackToMainMenu();
                
            }

            else {

                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");
            }

            break;

        case enMainMenueOptions::eManageUsers:

            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pManageUsers)) {

                system("cls");
                _showManageUsersMenu();
                _goBackToMainMenu();
               
            }

            else {

                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");
            }

            break;


        case enMainMenueOptions::eLoginRegister:

            if (activeUser.hasAccessPermission(clsUserInfo::enMainMenuPermissions::pLogInRegisters)) {

                system("cls");
                _showLogInRegisters();
                _goBackToMainMenu();

            }

            else {

                system("cls");
                cout << "\nAccess denied\n";
                _goBackToMainMenu();
                system("cls");
            }

            break;

        case enMainMenueOptions::eExit:

            system("cls");
            _logOut();
            break;
        }

    }



public:


    static void showMainMenu()
    {

        system("cls");
        _drawScreenHeader("\t\tMain Screen");

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
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performMainMenuOptions((enMainMenueOptions)_readMainMenuOption());
    }




};

