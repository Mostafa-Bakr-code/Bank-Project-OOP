#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsUserInfo.h"
#include "clsDate.h"
#include <iomanip>


class clsLogInScreen : protected clsScreen
{

public:

    static void showLogInScreen() {
        const int MAX_ATTEMPTS = 3;
        int attempts = 0;

        _drawScreenHeader("\t     Log In Screen");

        while (attempts < MAX_ATTEMPTS) {


            cout << "User Name: ";
            string userNumber = clsInputValidate::readString();
            cout << "Password: ";
            string Password = clsInputValidate::readString();

            if (clsUserInfo::isUserExist(userNumber, Password)) {
                activeUser = clsUserInfo::findUser(userNumber, Password);
                clsMainScreen::showMainMenu();
                return;
            }
            else {
                cout << "\nWrong username or password\n";
                cout << "Attempt " << attempts + 1 << " of 3 trials\n";
                attempts++;
            }
        }

        system("cls");
        cout << "System locked. Please contact your admin." << endl;
        exit(0);
    }

};

