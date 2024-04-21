#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUserInfo.h"
#include "clsGlobal.h"



using namespace std;

class clsScreen
{
protected:

    static void _drawScreenHeader(string Title, string subTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (subTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tWelcome Back " << activeUser.firstName << ":) ";
        cout << "" << clsDate::dateToString(clsDate::getCurrentDate());
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

};

