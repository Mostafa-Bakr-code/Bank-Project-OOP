#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsScreen.h"
#include "clsUserInfo.h"

class clsLogInRegisters : protected clsScreen
{

private:


	static void _printRegesterdLine(clsUserInfo::stUserRegisterd userRegisterd)
	{

		cout << setw(8) << left << "" << "| " << setw(35) << left << userRegisterd.time;
		cout << "| " << setw(20) << left << userRegisterd.fullName;
		cout << "| " << setw(20) << left << userRegisterd.password;
		cout << "| " << setw(10) << left << userRegisterd.permission;

	}


public:

	static void showLogInRegisters() {

		vector<clsUserInfo::stUserRegisterd> vRegisters = clsUserInfo::_loadRegistersToStVector();


		string subTiltle = "           " + to_string(vRegisters.size()) + " logins";

		_drawScreenHeader("          LogIn Registers", subTiltle);

		cout << "\n\t\t\t\t\tUsers Logins (" << vRegisters.size() << ") logins.";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vRegisters.size() == 0)
			cout << "\t\t\t\tNo registerd records !";
		else

			for (clsUserInfo::stUserRegisterd user : vRegisters)
			{

				_printRegesterdLine(user);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};

