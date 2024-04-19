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

		_drawScreenHeader("\t     Log In Screen", clsDate::dateToString(clsDate::getCurrentDate()));

		cout << "User Name: ";
		string userNumber = clsInputValidate::readString();
		cout << "Password: ";
		string Password = clsInputValidate::readString();

		while (!clsUserInfo::isUserExist(userNumber, Password)) {

			cout << "\n Wrong username or password\n";
			cout << "User Name: ";
			userNumber = clsInputValidate::readString();
			cout << "Password: ";
			Password = clsInputValidate::readString();
		}

		 activeUser = clsUserInfo::findUser(userNumber, Password);

		clsMainScreen::showMainMenu();

	}

};

