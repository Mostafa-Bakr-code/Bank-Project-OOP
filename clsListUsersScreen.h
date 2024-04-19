#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsUserInfo.h"


class clsListUsersScreen : protected clsScreen
{

private:

    static void _printUserRecordLine(clsUserInfo User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.userNumber;
        cout << "| " << setw(20) << left << User.getFullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permission;

    }

public:

	static void listUsers() {

        vector<clsUserInfo> vUsers = clsUserInfo::getUsersRecords();

        string Title = "\t     Users List\n";
        string subTitle = "\t   Showing " + to_string(vUsers.size()) + " users\n";

        _drawScreenHeader(Title, subTitle);

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";

        else {

            for (clsUserInfo user : vUsers) {
                cout << "\n";
                _printUserRecordLine(user);

            }

        }

	}



};

