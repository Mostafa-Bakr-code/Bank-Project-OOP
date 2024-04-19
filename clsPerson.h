#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:

	string _firstName;
	string _lastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string firstName, string lastName, string Email, string Phone) {

		_firstName = firstName;
		_lastName = lastName;
		_Email = Email;
		_Phone = Phone;
	}

	void setFirstName(string firstName) {

		_firstName = firstName;
	}

	string getFirstName() {

		return _firstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string firstName;

	void setLastName(string lastName) {

		_lastName = lastName;
	}

	string getLastName() {

		return _lastName;
	}

	__declspec(property(get = getLastName, put = setLastName)) string lastName;

	void setEmail(string Email) {

		_Email = Email;
	}

	string getEmail() {

		return _Email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhone(string Phone) {

		_Phone = Phone;
	}

	string getPhone() {

		return _Phone;
	}

	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	string getFullName() {

		return _firstName + " " + _lastName;
	}

};

