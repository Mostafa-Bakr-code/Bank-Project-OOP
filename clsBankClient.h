#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsUtil.h"



class clsBankClient : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpDateMode = 1, AddClientMode = 2 };
	enMode _Mode ;
	string _accountNumber;
	string _pinCode;
	float _accountBalance;
	bool _markForDelete = false;

	//___________________________________________________________________________
	//Files
	
	static clsBankClient _convertLinetoClientObject(string Line, string Seperator = "#//#") {

		vector<string> vClientRecord;

		vClientRecord = clsString::splitString(Line, Seperator);

		return clsBankClient(enMode::UpDateMode, vClientRecord[0], vClientRecord[1], vClientRecord[2], vClientRecord[3],
			vClientRecord[4], clsUtil::DecryptText(vClientRecord[5]), stod(vClientRecord[6]));

	}

	static vector<clsBankClient> _loadDataFromFileToObjVector() {

		vector<clsBankClient> vClientsRecord;
		fstream myFile;
		myFile.open("Clients.txt", ios::in);

		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				vClientsRecord.push_back(_convertLinetoClientObject(line));
			}
			myFile.close();
		}
		return vClientsRecord;
	}

	static string _converClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {

		string clientRecordLine = "";

		clientRecordLine = Client.firstName + Seperator;
		clientRecordLine += Client.lastName + Seperator;
		clientRecordLine += Client.Email + Seperator;
		clientRecordLine += Client.Phone + Seperator;
		clientRecordLine += Client.getAccountNumber() + Seperator;
		clientRecordLine += clsUtil::EncryptText(Client.pinCode) + Seperator;
		clientRecordLine += to_string(Client.accountBalance);

		return clientRecordLine;
	}

	static void _loadDataFromObjVectorToFile(vector <clsBankClient> vClientsRecord) {

		fstream myFile;
		myFile.open("Clients.txt", ios::out);

		if (myFile.is_open()) {

			for (clsBankClient record : vClientsRecord) {
				if (!record._markForDelete) {
					myFile << _converClientObjectToLine(record) << endl;
				}

			}
			myFile.close();
		}
	}


	//___________________________________________________________________________

	static clsBankClient _getEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);

	}

	void _upDateSave() {

		vector<clsBankClient> vClients = _loadDataFromFileToObjVector();

		for (clsBankClient &Client : vClients) {

			if (Client.getAccountNumber() == this->getAccountNumber()) {

				Client = *this;
				break;
			}
		}
		
		_loadDataFromObjVectorToFile(vClients);
	}

	void _addClientSave(){
	
		vector<clsBankClient> vClients = _loadDataFromFileToObjVector();

		vClients.push_back(*this);

		_loadDataFromObjVectorToFile(vClients);
	
	}

	void _loadTransferLogsToFile(clsBankClient destinationClient, double transferAmount) {

		string seperator = "#//#";

		fstream myFile;
		myFile.open("transferLogs.txt", ios::out | ios::app);

		if (myFile.is_open()) {

			myFile << clsDate::dateToString(clsDate::getCurrentDate()) + " - " + clsDate::getCurrentTimeOnly() + seperator;
			myFile << _accountNumber + seperator;
			myFile << destinationClient.getAccountNumber() + seperator;
			myFile << to_string(transferAmount) + seperator;
			myFile << to_string(_accountBalance) + seperator;
			myFile << to_string(destinationClient.accountBalance) + seperator;
			myFile << firstName + " " + lastName << endl;

			myFile.close();
		}
	}

	struct stTransferLogs;

	static stTransferLogs _convertLineToStTransferLogs(string line, string seperator = "#//#") {

		vector<string> transferRecord = clsString::splitString(line, seperator);

		stTransferLogs transferLog;

		transferLog.time = transferRecord[0];
		transferLog.sAccountNumber = transferRecord[1];
		transferLog.dAccountNumber = transferRecord[2];
		transferLog.amount = stod(transferRecord[3]);
		transferLog.sBalance = stod(transferRecord[4]);
		transferLog.dBalance = stod(transferRecord[5]);
		transferLog.sFullName = transferRecord[6];

		return transferLog;

	}

public:

	clsBankClient(enMode Mode,string firstName,string lastName,string Email, string Phone ,string accountNumber, string pinCode,
		float accountBalance, bool markForDelete = false):clsPerson(firstName, lastName, Email, Phone) {

		_Mode = Mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_accountBalance = accountBalance;
		
	}

	string getAccountNumber() {
		return _accountNumber;
	}

	void setAccountBalance(float accountBalance) {
		_accountBalance = accountBalance;
	}

	float getAccountBalance() {
		
		return _accountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float accountBalance;

	void setPinCode(string pinCode) {
		_pinCode = pinCode;
	}

	string getPinCode() {
		return _pinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string pinCode;

	//________________________________________________________________________

	static clsBankClient findClient(string accountNumber) {

		vector<clsBankClient> vClients = _loadDataFromFileToObjVector();

		for (clsBankClient clientRecord : vClients) {

			if (clientRecord.getAccountNumber() == accountNumber) {

				return clientRecord;
				break;
			}

		}

		return _getEmptyClientObject();
	}

	static clsBankClient findClient(string accountNumber, string pinCode) {

		vector<clsBankClient> vClients = _loadDataFromFileToObjVector();

		for (clsBankClient clientRecord : vClients) {

			if (clientRecord.getAccountNumber() == accountNumber && clientRecord.pinCode == pinCode) {

				return clientRecord;
				break;
			}

		}

		return _getEmptyClientObject();
	}

	static bool isClientExist(string accountNumber) {

		clsBankClient Client = clsBankClient::findClient(accountNumber);

		return (Client._Mode != enMode::EmptyMode);
	}

	static vector<clsBankClient> getClientsRecord() {

		return _loadDataFromFileToObjVector();
	}

	static clsBankClient getNewClientObject(string accountNumber) {

		return clsBankClient(enMode::AddClientMode,"","","","",accountNumber,"",0);

	}

	enum enSaveResults{svFailedEmptyObj = 0, svSucceeded = 1};
	
	 enSaveResults Save() {

		switch (_Mode) {
			
		case enMode::EmptyMode:

			return enSaveResults::svFailedEmptyObj;

		case enMode::UpDateMode:

			_upDateSave();
			return enSaveResults::svSucceeded;


		case enMode::AddClientMode:

			_addClientSave();
			this->_Mode = enMode::UpDateMode;
			return enSaveResults::svSucceeded;
		}

	}

	 bool deleteClient() {

		 vector<clsBankClient> vClients = _loadDataFromFileToObjVector();

		 for (clsBankClient& Client: vClients) {

			 if (Client.getAccountNumber() == this->getAccountNumber()) {

				Client._markForDelete = true;
				break;
			 }
		 }

		 _loadDataFromObjVectorToFile(vClients);

		 *this = _getEmptyClientObject();

		 return true;

	 }

	 bool Deposit(double depositAmount) {

		 if (depositAmount < 0) {
			 return false;
		 }

		 else {
			 _accountBalance += depositAmount;
			 Save();
		 }

	 }

	 bool Withdraw(double withdrawAmount) {

		 if (withdrawAmount > _accountBalance) {

			 return false;
		 }

		 else {
			 _accountBalance -= withdrawAmount;
			 Save();
		 }

	 }

	 static double getTotalBalances() {

		 vector<clsBankClient> vClientsRecords = getClientsRecord();
		 double totalBalances = 0;

		 for (clsBankClient clientRecord : vClientsRecords) {

			 totalBalances += clientRecord.accountBalance;
		 }

		 return totalBalances;
	 }


	  bool transfer(clsBankClient &destinationClient,double transferAmount) {

		 if (transferAmount > accountBalance) {
			 return false;
		 }

		 else {

			 Withdraw(transferAmount);
			 destinationClient.Deposit(transferAmount);
			 _loadTransferLogsToFile(destinationClient, transferAmount);
			 return true;
		 }

	 }

	  //___________________________________________________________________
	  // logs

	  struct stTransferLogs {

		  string time;
		  string sAccountNumber;
		  string dAccountNumber;
		  double amount;
		  double sBalance;
		  double dBalance;
		  string sFullName;

	  };


	  static vector<stTransferLogs> loadTransferLogsToStVector() {

		  vector <stTransferLogs> vTransferRecord;
		  fstream myFile;
		  myFile.open("transferLogs.txt", ios::in);

		  if (myFile.is_open()) {
			  string line;
			  while (getline(myFile, line)) {

				  vTransferRecord.push_back(_convertLineToStTransferLogs(line));

			  }
			  myFile.close();
		  }

		  return vTransferRecord;
	  }


};

