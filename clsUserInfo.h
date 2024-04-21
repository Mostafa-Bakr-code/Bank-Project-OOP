#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"




class clsUserInfo : public clsPerson
{

private:



	enum enMode { EmptyMode = 0, UpDateMode = 1, AddUserMode = 2 };

	enMode _Mode;
	int _Permission;
	string _Password;
	string _userNumber;
	bool _markForDelete = false;

	//___________________________________________________________________________________
    // Files

	static clsUserInfo _convertLinetoUserObject(string Line, string Seperator = "#//#") {

		vector<string> vUserRecord;

		vUserRecord = clsString::splitString(Line, Seperator);

		return clsUserInfo(enMode::UpDateMode, vUserRecord[0], vUserRecord[1], vUserRecord[2], vUserRecord[3], vUserRecord[4],
			vUserRecord[5], stoi(vUserRecord[6]));


	}

	static vector<clsUserInfo> _loadDataFromFileToObjVector() {

		vector<clsUserInfo> vUsersRecord;
		fstream myFile;
		myFile.open("Users.txt", ios::in);

		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {

				vUsersRecord.push_back(_convertLinetoUserObject(line));

			}
			myFile.close();
		}
		return vUsersRecord;
	}

	static string _converUserObjectToLine(clsUserInfo User, string Seperator = "#//#") {

		string userRecordLine = "";

		userRecordLine = User.firstName + Seperator;
		userRecordLine += User.lastName + Seperator;
		userRecordLine += User.Email + Seperator;
		userRecordLine += User.Phone + Seperator;
		userRecordLine += User.userNumber + Seperator;
		userRecordLine += User.Password + Seperator;
		userRecordLine += to_string(User.Permission);

		return userRecordLine;
	}

	static void _loadDataFromObjVectorToFile(vector <clsUserInfo> vUsersRecord) {

		fstream myFile;
		myFile.open("Users.txt", ios::out);

		if (myFile.is_open()) {

			for (clsUserInfo record : vUsersRecord) {
				if (!record._markForDelete) {
					myFile << _converUserObjectToLine(record) << endl;
				}

			}
			myFile.close();
		}
	}

	//___________________________________________________________________________________

	static clsUserInfo _getEmptyUserObject() {

		return clsUserInfo(enMode::EmptyMode, "", "", "", "", "","", -1);
	}

	void _updateUserSave() {

		vector <clsUserInfo> vUsers = _loadDataFromFileToObjVector();

		for (clsUserInfo &user : vUsers) {

			if (user.userNumber == userNumber) {

				user = *this;
				break;
			}
		}

		_loadDataFromObjVectorToFile(vUsers);
	}

	void _addNewUserSave() {

		vector <clsUserInfo> vUsers = _loadDataFromFileToObjVector();

		vUsers.push_back(*this);

		_loadDataFromObjVectorToFile(vUsers);
	}

public:

	enum enMainMenuPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64
	};
	
	clsUserInfo(enMode Mode ,string firstName, string lastName, string Email, string Phone,string userNumber ,string Password, int userPermission) : clsPerson(firstName,lastName,Email,Phone) {

		_Password = Password;
		_Mode = Mode;
		_Permission = userPermission;
		_userNumber = userNumber;
	}
	
	void setPassword(string Password) {

		_Password = Password;
	}

	string getPassword() {

		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string Password;

	void setUserNumber(string userNumber) {

		_userNumber = userNumber;
	}

	string getUserNumber() {

		return _userNumber;
	}

	__declspec(property(get = getUserNumber, put = setUserNumber)) string userNumber;


	void setPermission(int permission) {

		_Permission = permission;

	 }

	int getPermission() {

		return _Permission;
	}

	__declspec(property(get = getPermission, put = setPermission)) int Permission;

	static bool isUserExist(string userNumber) {

		clsUserInfo user = findUser(userNumber);
		return user._Mode != enMode::EmptyMode;
	}

	static bool isUserExist(string userNumber, string Password) {

		clsUserInfo user = findUser(userNumber, Password);
		return user._Mode != enMode::EmptyMode;
	}

	static clsUserInfo findUser(string userNumber) {

		
		vector<clsUserInfo> vUsers = _loadDataFromFileToObjVector();
		

		for (clsUserInfo userRecord : vUsers) {

			if (userRecord.userNumber == userNumber) {

				return userRecord;
				break;
			}

		}

		return _getEmptyUserObject();
	}

	static clsUserInfo findUser(string userNumber, string Password) {


		vector<clsUserInfo> vUsers = _loadDataFromFileToObjVector();


		for (clsUserInfo userRecord : vUsers) {

			if (userRecord.userNumber == userNumber && userRecord.Password == Password) {

				return userRecord;
				break;
			}

		}

		return _getEmptyUserObject();
	}

	enum enSaveResults { svFailedEmptyObj = 0, svSucceeded = 1};


	  enSaveResults Save() {
		
		switch (_Mode) {

		case enMode::EmptyMode:

			return enSaveResults::svFailedEmptyObj;

		case enMode::UpDateMode:

			_updateUserSave();
			return enSaveResults::svSucceeded;

		case enMode::AddUserMode:

			_addNewUserSave();
			this->_Mode = enMode::UpDateMode;
			return enSaveResults::svSucceeded;

		}

	}

	  static vector<clsUserInfo> getUsersRecords() {

		  return _loadDataFromFileToObjVector();

	  }

	  void deleteUser() {

		  vector<clsUserInfo> vUsers = _loadDataFromFileToObjVector();

		  for (clsUserInfo &user : vUsers) {

			  if (user.userNumber == (*this).userNumber) {

				 user._markForDelete = true;
				 break;
			 }

		  }

		  _loadDataFromObjVectorToFile(vUsers);
		  *this = _getEmptyUserObject();

	  }

	  static clsUserInfo getEmptyUserObjectforNewUser(string userNumber) {

		  return clsUserInfo(enMode::AddUserMode, "", "", "", "", userNumber, "", -1);
	  }

	  bool hasAccessPermission(enMainMenuPermissions myPermission) {

		  if ((*this).Permission == -1) {
			  return true;
		  }

		  else {

			  if (myPermission == ((*this).Permission & myPermission)) {

				  return true;
			  }
		  }

		  return false;

	  }




};

