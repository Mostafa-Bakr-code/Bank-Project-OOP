#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDate.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsListUsersScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsAddUserScreen.h"






class clsManageUsersScreen : clsScreen
{

private:

    enum enUsersOptions{ListUsers = 1, AddUser = 2, DeleteUser = 3, UpdateUSer = 4, FindUser = 5, MainMenu = 6};

    static enUsersOptions _readManageUserOption() {

        cout << "Select Option [1 - 6]?\n";
        return  enUsersOptions(clsInputValidate::ReadShortNumberBetween(1, 6));

    }

    static void _listUsers() {
        
        clsListUsersScreen::listUsers();
       
    }

    static void _addUser() {

        clsAddUserScreen::addUserScreen();
        
    }

    static void _updateUser() {

        clsUpdateUserScreen::updateUserScreen();
        
    }

    static void _findUser() {
        
        clsFindUser::findUserScreen();
       
    }

    static void _deleteUser() {
        
        clsDeleteUserScreen::deleteUserScreen();
       
    }

    static  void _goBackToManageUsersMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menu...\n";

        system("pause>0");
        showManageUsersScreen();
    }

    static void performManageUsersOptions(enUsersOptions userOption) {

        switch (userOption) {

        case enUsersOptions::AddUser: 

            system("cls");
            _addUser();
            _goBackToManageUsersMenu();
            break;

        case enUsersOptions::ListUsers:

            system("cls");
            _listUsers();
            _goBackToManageUsersMenu();
            break;

        case enUsersOptions::UpdateUSer:

            system("cls");
            _updateUser();
            _goBackToManageUsersMenu();
            break;

        case enUsersOptions::FindUser:

            system("cls");
            _findUser();
            _goBackToManageUsersMenu();
            break;

        case enUsersOptions::DeleteUser:

            system("cls");
            _deleteUser();
            _goBackToManageUsersMenu();
            break;

        case enUsersOptions::MainMenu:
            break;
        }
    }

public:

	static void showManageUsersScreen() {

        system("cls");

		string Tiltle = "\tManage Users Screen";
       
		_drawScreenHeader(Tiltle);

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\tManage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update Users's Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        performManageUsersOptions(_readManageUserOption());
	}


};

