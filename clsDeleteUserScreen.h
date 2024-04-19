#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUserInfo.h"
#include "clsInputValidate.h"


class clsDeleteUserScreen : protected clsScreen
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

	static void deleteUserScreen() {

		_drawScreenHeader("\t   Delete User Screen");

		cout << "User Number: ";
		string userNumber = clsInputValidate::readString();

		while (!clsUserInfo::isUserExist(userNumber)) {
			cout << "User doesn't exist...\n";
			cout << "User Number: ";
			userNumber = clsInputValidate::readString();

		}

		clsUserInfo User = clsUserInfo::findUser(userNumber);
		_printUserCard(User);

		cout << "\nAre you sure you want to delete this user? y/n\n";

		if (clsInputValidate::readChar() == 'y') {

			User.deleteUser();
			cout << "\nUser deleted sucessfully..\n";
			_printUserCard(User);
		}

	}

};

