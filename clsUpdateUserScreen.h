
#pragma once

#include "clsUserInfo.h"
#include "clsScreen.h"
#include "clsInputValidate.h"




class clsUpdateUserScreen : private clsScreen
{

private:

	static void _readUserInfo(clsUserInfo& User) {

		cout << "First Name: ";
		User.firstName = clsInputValidate::readString();

		cout << "Last Name: ";
		User.lastName = clsInputValidate::readString();

		cout << "Email: ";
		User.Email = clsInputValidate::readString();

		cout << "Phone: ";
		User.Phone = clsInputValidate::readString();

		cout << "Password: ";
		User.Password = clsInputValidate::readString();

		cout << "Entre Permissions: ";
		User.Permission = _readPermissions();

	}

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

	static int _readPermissions() {

		cout << "Do you want to give access to all menu? y/n ";

		if (clsInputValidate::readChar() == 'y') {

			return -1;
		}

		else {
			int permission = 0;

			cout << "Do you want to give access to list clients? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pListClients;

			}

			cout << "Do you want to give access to add clients? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pAddNewClient;

			}

			cout << "Do you want to give access to update clients? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pUpdateClients;

			}

			cout << "Do you want to give access to find clients? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pFindClient;

			}

			cout << "Do you want to give access to delete clients? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pDeleteClient;

			}

			cout << "Do you want to give access to Transaction menu? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pTransactions;

			}

			cout << "Do you want to give access to Manage users menu? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pManageUsers;

			}

			cout << "Do you want to give access to logins registerd? y/n ";

			if (clsInputValidate::readChar() == 'y') {

				permission += clsUserInfo::enMainMenuPermissions::pLogInRegisters;

			}

			return permission;
		}

	}

public:

	static void updateUserScreen() {

		_drawScreenHeader("\t      Update User");

		cout << "User Number: ";
		string userNumber = clsInputValidate::readString();

		while (!clsUserInfo::isUserExist(userNumber)) {
			cout << "User doesn't exist...\n";
			cout << "User Number: ";
			userNumber = clsInputValidate::readString();

		}

		clsUserInfo User = clsUserInfo::findUser(userNumber);
		_printUserCard(User);

		cout << "\n Update user info ...\n";
		_readUserInfo(User);
		if (User.Save() == clsUserInfo::enSaveResults::svFailedEmptyObj) {
		
			cout << "\nOoops!! file coudn't be saved because object is empty...\n";
		}

		else {
			cout << "\nSaved Sucssefully :)\n";
			_printUserCard(User);
		}


	}

};

