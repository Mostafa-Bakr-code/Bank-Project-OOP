#pragma once
#include <iostream>
#include <vector>
using namespace std;


class clsString
{
private:

	string _value;

public:


	clsString() {
		_value = "";
	};

	clsString(string value) {
		_value = value;
	}

	void setValue(string value) {
		_value = value;
	}

	string getValue() {
		return _value;
	}

	//____________________________________________________

	 static short countWords(string mystring) {

		string delimiter = " ";
		short pos = 0;
		string word;
		short wordcounter = 0;

		while ((pos = mystring.find(delimiter)) != string::npos) {

			word = mystring.substr(0, pos);
			if (word != "") {
				wordcounter++;
			}

			mystring.erase(0, pos + delimiter.length());
		}

		if (mystring != "") {
			wordcounter++;
		}

		return wordcounter;
	}

	 short countWords() {
		return countWords(_value);
	}

	 static short length(string mystring) {

		 return mystring.length();
	 }

	 short length() {

		 return length(_value);
	 }

	static void printFirstWordLetterInString(string mystring) {

		 cout << mystring[0] << endl;

		 for (int i = 0; i < mystring.length(); i++) {

			 if (mystring[i] == ' ') {
				 cout << mystring[i + 1] << endl;
			 }
		 }
	 }

	void printFirstWordLetterInString() {

		return printFirstWordLetterInString(_value);
	}

	static string capitalizeFirstLetterInWord(string mystring) {

		bool isfirstletter = true;

		for (int i = 0; i < mystring.length(); i++) {

			if (isfirstletter && mystring[i] != ' ') {
				mystring[i] = toupper(mystring[i]);
			}
			isfirstletter = mystring[i] == ' ' ? true : false;
		}
		return mystring;
	}

	void capitalizeFirstLetterInWord() {

		_value = capitalizeFirstLetterInWord(_value);
	}

	static string lowerCaseFirstLetterInWord(string mystring) {

		bool isfirstletter = true;

		for (int i = 0; i < mystring.length(); i++) {

			if (isfirstletter && mystring[i] != ' ') {
				mystring[i] = tolower(mystring[i]);
			}
			isfirstletter = mystring[i] == ' ' ? true : false;
		}
		return mystring;
	}

	void lowerCaseFirstLetterInWord() {

		_value = lowerCaseFirstLetterInWord(_value);
	 }

	static string capitalizeString(string mystring) {

		for (int i = 0; i < mystring.length(); i++) {

			mystring[i] = toupper(mystring[i]);
		}
		return mystring;
	}

	void capitalizeString() {
		_value = capitalizeString(_value);
	}

	static string lowerCaseString(string mystring) {

		for (int i = 0; i < mystring.length(); i++) {

			mystring[i] = tolower(mystring[i]);
		}
		return mystring;
	}

	void lowerCaseString() {

		_value = lowerCaseString(_value);
	}

	static char invertcharcase(char mychar) {

		return islower(mychar) ? toupper(mychar) : tolower(mychar);

	}

	static string invertAllLettersCase(string mystring) {

		for (int i = 0; i < mystring.length(); i++) {

			mystring[i] = invertcharcase(mystring[i]);
		}
		return mystring;
	}

	void invertAllLettersCase() {

		_value = invertAllLettersCase(_value);
	}

	static short countUpperCaseLetters(string mystring) {

		short capitallettesrcounter = 0;

		for (int i = 0; i < mystring.length(); i++) {

			if (isupper(mystring[i])) {
				capitallettesrcounter++;
			}
		}
		return capitallettesrcounter;
	}

	short countUpperCaseLetters() {

		return countUpperCaseLetters(_value);
	}

	static short countLowerCaseLetters(string mystring) {

		short smalllettesrcounter = 0;

		for (int i = 0; i < mystring.length(); i++) {

			if (islower(mystring[i])) {
				smalllettesrcounter++;
			}
		}
		return smalllettesrcounter;
	}

	short countLowerCaseLetters() {

		return countLowerCaseLetters(_value);
	}

	static short countLetters(string mystring) {

		short allletterscounter = 0;

		for (int i = 0; i < mystring.length(); i++) {

			if (mystring[i] != ' ') {
				allletterscounter++;
			}
		}
		return allletterscounter;
	}

	short countLetters() {

		return countLetters(_value);
	}

	static short countSpecificLetter(string mystring, char letter, bool matchCase = true) {

		short lettercounter = 0;

		if (matchCase == true) {
			for (int i = 0; i < mystring.length(); i++) {

				if (mystring[i] == letter) {
					lettercounter++;
				}
			}

			return lettercounter;
		}

		else {
			for (int i = 0; i < mystring.length(); i++) {

				if (mystring[i] == tolower(letter) || mystring[i] == toupper(letter)) {
					lettercounter++;
				}
			}
			return lettercounter;
		}

	}

	short countSpecificLetter(char letter, bool matchCase = true) {
		
		return countSpecificLetter(_value, letter, matchCase);
	 }

	static short numberOfVowels(string mystring) {

		short vowelcounter = 0;

		for (int i = 0; i < mystring.length(); i++) {

			if (isvowel(mystring[i])) {
				vowelcounter++;
			}
		}
		return vowelcounter;
	}

	static bool isvowel(char mychar) {

		mychar = tolower(mychar);

		return (mychar == 'a' || mychar == 'i' || mychar == 'o' || mychar == 'u' || mychar == 'e');

	}

	short numberOfVowels() {

		return numberOfVowels(_value);
	}

	static vector <string > splitString(string mystring, string delimeter) {

		vector <string> vwordsinstring;
		short pos = 0;
		string word;

		while ((pos = mystring.find(delimeter)) != string::npos) {

			word = mystring.substr(0, pos);
			if (word != "") {
				vwordsinstring.push_back(word);
			}

			mystring.erase(0, pos + delimeter.length());
		}

		if (mystring != "") {

			vwordsinstring.push_back(mystring);
		}
		return vwordsinstring;
	}

	vector <string > splitString(string delimeter) {

		return splitString(_value, delimeter);
	}

	static string joinString(vector<string> vstring, string delimeter) {

		string mystring;

		for (string& s : vstring) {

			mystring += s + delimeter;
		}

		return mystring.substr(0, mystring.length() - delimeter.length());
	}

	static string joinString(string myarray[], short length, string delimeter) {

		string mystring;

		for (int i = 0; i < length; i++) {

			mystring += myarray[i] + delimeter;
		}

		return mystring.substr(0, mystring.length() - delimeter.length());
	}

	static string trimLeft(string mystring) {


		for (int i = 0; i < mystring.length(); i++) {

			if (mystring[i] != ' ') {

				return mystring.substr(i, mystring.length() - i);
			}
		}

	}

	void trimLeft() {

		_value = trimLeft(_value);
	}

	static string trimRight(string mystring) {


		for (int i = mystring.length() - 1; i >= 0; i--) {

			if (mystring[i] != ' ') {

				return mystring.substr(0, i + 1);
			}
		}

	}

	void trimRight() {

		_value = trimRight(_value);

	}

	static string trimString(string mystring) {

		return trimLeft(trimRight(mystring));
	}

	void trimString() {

		_value = trimString(_value);
	}

	static string reverseLetters(string mystring) {

		string myreversedstring;

		for (int i = mystring.length() - 1; i >= 0; i--) {

			myreversedstring += mystring[i];

		}

		return myreversedstring;
	}

	string reverseLetters() {

		return reverseLetters(_value);
	}

	static string reverseWords(string mystring) {

		vector<string> vstring = splitString(mystring, " ");
		string s2 = "";

		vector<string>::iterator word = vstring.end();

		while (word != vstring.begin()) {

			--word;
			s2 += *word + " ";
		}

		return s2.substr(0, s2.length() - 1);
	}

	void reverseWords() {

		_value = reverseWords(_value);
	}

	static string replaceWords(string mystring, string replace, string replacewith) {

		short pos;
		string s2 = "";

		while ((pos = mystring.find(replace)) != std::string::npos) {

			s2 += mystring.substr(0, pos) + replacewith;
			mystring.erase(0, pos + replace.length());
		}

		if (mystring.find(replace) == mystring.npos) {
			s2 += mystring;
		}

		return s2;
	}

	void replaceWords(string replace, string replacewith) {

		_value = replaceWords(_value, replace, replacewith);
	}

	static string removePunctuations(string mystring) {

		string s2 = "";

		for (int i = 0; i < mystring.length(); i++) {

			if (!ispunct(mystring[i])) {

				s2 += mystring[i];
			}

		}
		return s2;
	}

	void removePunctuations() {

		_value = removePunctuations(_value);
	}

	__declspec(property(get = getValue, put = setValue)) string Value;
};



