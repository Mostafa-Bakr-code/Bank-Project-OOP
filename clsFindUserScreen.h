#pragma once

#include "clsUserInfo.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


class clsFindUser : protected clsScreen
{

private:

	static void _printUserCard(clsUserInfo User) {

		cout << "\n\nUser Card\n\n";
		cout << "First Name: " << User.firstName << endl;
		cout << "Last Name: " << User.lastName << endl;
		cout << "Full Name: " << User.getFullName() << endl;
		cout << "Email: " << User.Email << endl;
		cout << "Phone: " << User.Phone << endl;
		cout << "Password: " << User.Password << endl;
		cout << "Permissions: " << User.Permission << endl;
	}

public:

	static void findUserScreen() {

		_drawScreenHeader("\t      Find User");

		cout << "User Number: ";
		string userNumber = clsInputValidate::readString();

		while (!clsUserInfo::isUserExist(userNumber)) {
			cout << "User doesn't exist...\n";
			cout << "User Number: ";
			userNumber = clsInputValidate::readString();

		}

		clsUserInfo User = clsUserInfo::findUser(userNumber);
		_printUserCard(User);
			
		

	}

};

