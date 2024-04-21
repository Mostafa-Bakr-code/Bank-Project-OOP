#pragma once
#include <iostream>

#include <vector>
#include <cctype>
#include <ctime>
#include <chrono>
#include <thread>
#include "clsString.h"

#pragma warning(disable : 4996)
using namespace std;



class clsDate
{
private:
	short _day = 1;
	short _month = 1;
	short _year = 1990;

public:

	//___________________________________________________________________
	// Constructors
	
	// Default constructor gets the current date
	clsDate() {
		
		time_t t = time(0);
		tm* now = localtime(&t);

		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	
	};

	clsDate(string dateString) {

		
		vector<string> vstring = clsString::splitString(dateString, "/");

		_day = stoi(vstring[0]);
		_month = stoi(vstring[1]);
		_year = stoi(vstring[2]);

	}

	clsDate(short day, short month, short year) {
		_day = day;
		_month = month;
		_year = year;

	}

	clsDate(short dayOrderInYear, short year){
		
		short remainingDays = dayOrderInYear;
		short monthdays = 0;
		_year = year;
		_month = 1;

		while (true) {

			monthdays = numOfDaysInMonth(_year, _month);

			if (remainingDays > monthdays) {
				remainingDays -= monthdays;
				_month++;
			}

			else {
				_day = remainingDays;
				break;
			}
		}
	}

	//____________________________________________________________________
	// Set & Get Private members (day,month,year)

	void setDay(short day) {
		_day = day;
	}

	short getDay() {
		return _day;
	}

	__declspec(property(get = getDay, put = setDay)) short day;

	void setMonth(short month) {
		_month = month;
	}

	short getMonth() {
		return _month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short month;

	void setYear(short year) {
		_year = year;
	}

	short getYear() {
		return _year;
	}

	__declspec(property(get = getYear, put = setYear)) short year;

	//_____________________________________________________________

	static bool isLeapYear(short year) {

		return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
	}

	bool isLeapYear() {

		return isLeapYear(_year);
	}

	//_____________________________________________________________

	static short numOfDaysInYear(short year) {

		return isLeapYear(year) ? 366 : 365;
	}

	short numOfDaysInYear() {

		return numOfDaysInYear(_year);
	}

	static short numOfHoursInYear(short year) {

		return numOfDaysInYear(year) * 24;
	}

	short numOfHoursInYear() {

		return numOfHoursInYear(_year);
	}

	static short numOfMinutesInYear(short year) {

		return numOfHoursInYear(year) * 60;
	}

	short numOfMinutesInYear() {

		return numOfMinutesInYear(_year);
	}

	static int numOfSecondsInYear(short year) {

		return numOfMinutesInYear(year) * 60;
	}

	int numOfSecondsInYear() {

		return numOfSecondsInYear(_year);

	}

	//_____________________________________________________________

	static short numOfDaysInMonth(short year, short month) {

		short myArray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : myArray[month - 1];

	}

	short numOfDaysInMonth() {

		return numOfDaysInMonth(_year, _month);
	}

	static short numOfHoursInMonth(short year, short month) {

		return numOfDaysInMonth(year, month) * 24;
	}

	short numOfHoursInMonth() {

		return numOfHoursInMonth(_year, _month);
	}

	static short numOfMinutesInMonth(short year, short month) {

		return numOfHoursInMonth(year, month) * 60;
	}

	short numOfMinutesInMonth() {

		return numOfMinutesInMonth(_year, _month);
	}

	static short numOfSecondsInMonth(short year, short month) {

		return numOfMinutesInMonth(year, month) * 60;
	}

	short numOfSecondsInMonth() {

		return numOfSecondsInMonth(_year, _month);
	}

	//______________________________________________________________

	static short dayOfWeekOrder(short year, short month, short day) {

		short a = (14 - month) / 12;

		short y = year - a;

		short m = month + 12 * a - 2;

		short d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

		return d; // sunday 0 monday 1 tue 2 wed 3 thu 4 fri 5 sat 6
	}

	short dayOfWeekOrder() {

		return dayOfWeekOrder(_year, _month, _day);
	}

	static string dayOfWeekName(short dayOfWeekOrder) {

		string daysOFWeekArr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return daysOFWeekArr[dayOfWeekOrder];
	}

	static string dayOfWeekName(short year, short month, short day) {

		string daysOFWeekArr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return daysOFWeekArr[dayOfWeekOrder(year, month, day)];
	}

	string dayOfWeekName() {

		return dayOfWeekName((_year, _month, _day));
	}

	static string nameOfMonth(short month) {

		string monthsNamesArr[] = { "", "Jan", "Feb", "Mar", "Apr", "May" ,"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return monthsNamesArr[month];
	}

	string nameOfMonth() {

		return nameOfMonth(_month);
	}

	//______________________________________________________________
	// Calenders

	static void printMonthCalender(short year, short month) {

		int current = dayOfWeekOrder(year, month, 1);
		int numofdays = numOfDaysInMonth(year, month);

		cout << "\n ----------------" << nameOfMonth(month) << "---------------\n\n";
		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n";

		int i;

		for (i = 0; i < current; i++) {
			printf("     ");
		}

		for (int j = 1; j <= numofdays; j++) {

			printf("%5d", j);

			if (++i == 7) {
				i = 0;
				cout << endl;
			}
		}

		cout << "\n ----------------------------------\n";

	}

	void printMonthCalender() {

		return printMonthCalender(_year, _month);
	}

	static void printYearCalender(short year) {

		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", year);
		printf("  _________________________________\n");

		for (short month = 1; month <= 12; month++) {

			printMonthCalender(year, month);
		}
	}

	void printYearCalender() {

		printYearCalender(_year);
	}

	//______________________________________________________________


	static short daysFromBeginingOfYear(short day, short month, short year) {

		int sum = 0;

		// form year beginning up to current month
		for (int i = 1; i < month; i++) {

			sum += numOfDaysInMonth(year, i);
		}

		// from current month start up to current day
		sum += day;


		return sum;
	}

	short daysFromBeginingOfYear() {

		return daysFromBeginingOfYear(_day, _month, _year);
	}

	static clsDate dateFromDayOrderinYear(short dayorderinyear, short year) {

		clsDate date;
		short remainingDays = dayorderinyear;
		short monthdays = 0;
		date.year = year;
		date.month = 1;

		while (true) {

			monthdays = numOfDaysInMonth(date.month, year);

			if (remainingDays > monthdays) {
				remainingDays -= monthdays;
				date.month++;
			}

			else {
				date.day = remainingDays;
				break;
			}
		}

		return date;

	}

	//_____________________________________________________________________________________

	static bool isdate1beforedate2(clsDate Date1, clsDate Date2) {
		return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
	 }

	bool isdate1beforedate2(clsDate date2) {

		 return isdate1beforedate2(*this, date2);
	 }

	static bool isdate1equaldate2(clsDate Date1, clsDate Date2) {

		return  (Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false;

	 }

	bool isdate1equaldate2(clsDate date2) {

		 return isdate1equaldate2(*this, date2);
	 }

	static bool isdate1Afterdate2(clsDate date1, clsDate date2) {

		 return (!isdate1beforedate2(date1, date2) && !isdate1equaldate2(date1, date2));

	 }

	bool isdate1Afterdate2(clsDate date2) {

		 return isdate1Afterdate2(*this, date2);
	 }

	static bool islastdayinmonth(clsDate date) {

		 return date.day == numOfDaysInMonth(date.year, date.month);
	 }

	bool islastdayinmonth() {

		return islastdayinmonth(*this);
	}

	static bool islastmonthinyear(clsDate date) {

		 return date.month == 12;
	 }

	bool islastmonthinyear() {

		 return islastmonthinyear(*this);
	 }

	//____________________________________________________________

	 static clsDate increasedatebyoneday(clsDate &date) {


		 if (islastdayinmonth(date) && islastmonthinyear(date)) {
			 date.day = 1;
			 date.month = 1;
			 date.year++;
		 }

		 else if (islastdayinmonth(date)) {

			 date.day = 1;
			 date.month++;
		 }

		 else {

			 date.day++;

		 }

		 return date;
	 }

	 void increasedatebyoneday() {

		*this = increasedatebyoneday(*this);
	 }

	 static clsDate decreasedatebyoneday(clsDate &date) {


		 if (date.day == 1 && date.month == 1) {
			 date.day = 31;
			 date.month = 12;
			 date.year--;
		 }

		 else if (date.day == 1) {

			 date.day = numOfDaysInMonth(date.year, date.month - 1);
			 date.month--;
		 }

		 else {

			 date.day--;

		 }

		 return date;
	 }

	 void decreasedatebyoneday() {

		 *this = decreasedatebyoneday(*this);
	 }

	 static short diffbetween2dates(clsDate date1, clsDate date2) {

		 short firstdate = daysFromBeginingOfYear(date1.day, date1.month, date1.year);
		 short seconddate = daysFromBeginingOfYear(date2.day, date2.month, date2.year);
		 short differencedays = 0;
		 if (isdate1beforedate2(date1, date2)) {

			 while (true) {

				 if (date1.year == date2.year) {

					 differencedays = seconddate - firstdate;
					 return differencedays;
				 }

				 differencedays += numOfDaysInYear(date2.year);

				 date2.year--;

				 if (date1.year == date2.year)
				 {
					 differencedays += seconddate - firstdate;

					 return differencedays;
				 }
			 }
		 }
	 }

	 short diffbetween2dates(clsDate date2) {

		 return diffbetween2dates(*this, date2);
	 }

	 static void swapDates(clsDate &date1, clsDate &date2) {

		 clsDate temp;

		 //temp.day = date1.day;
		 //temp.month = date1.month;
		 //temp.year = date1.year;
		 // one line of code
		 temp = date1;

		 //date1.day = date2.day;
		 //date1.month = date2.month;
		 //date1.year = date2.year;
		 date1 = date2;

		 //date2.day = temp.day;
		 //date2.month = temp.month;
		 //date2.year = temp.year;
		 date2 = temp;
	 }

	 void swapDates(clsDate date2) {

		 return swapDates(*this, date2);
	 }

	 //_____________________________________________________________


	 static clsDate increasedatebyxdays(clsDate& date, short xDays) {

		 for (int i = 0; i < xDays; i++) {

			 date = increasedatebyoneday(date);

		 }

		 return date;
	 }

	 void increasedatebyxdays(short xDays) {

		  increasedatebyxdays(*this, xDays);
	 }

	 static clsDate increasedateby1week(clsDate &date) {

		 for (int i = 0; i < 7; i++) {

			 date = increasedatebyoneday(date);

		 }

		 return date;
	 }

	 void increasedateby1week() {

		  increasedateby1week(*this);
	 }

	 static clsDate increasedatebyXweeks(clsDate &date, short xWeeks) {

		 for (int i = 0; i < xWeeks; i++) {

			 date = increasedateby1week(date);

		 }

		 return date;
	 }

	 void increasedatebyXweeks(short xWeeks) {

		 increasedatebyXweeks(*this, xWeeks);
	 }

	 static clsDate increasedateby1month(clsDate &date) {

		 int monthdays = numOfDaysInMonth(date.year, date.month);

		 date = increasedatebyxdays(date, monthdays);

		 return date;
	 }

	 void increasedateby1month() {

		 increasedateby1month(*this);
	 }

	 static clsDate increasedatebyXmonth(clsDate &date, short xMonths) {

		 for (int i = 0; i < xMonths; i++) {

			 date = increasedateby1month(date);
		 }
		 return date;
	 }

	 void increasedatebyXmonth(short xMonths) {

		 increasedatebyXmonth(*this, xMonths);
	 }

	 static clsDate increasedateby1year(clsDate &date) {

		 date.year++;
		 return date;
	 }

	 void increasedateby1year() {

		 increasedateby1year(*this);
	 }

	 static clsDate increasedatebyXyears(clsDate &date, int xYears) {

		 for (int i = 0; i < xYears; i++) {

			 date = increasedateby1year(date);
		 }
		 return date;
	 }

	  void increasedatebyXyears(int xYears) {

		  increasedatebyXyears(*this, xYears);
	 }

	 static clsDate increasedatebydecade(clsDate& date) {

		 date.year += 10;
		 return date;
	 }

	 void increasedatebydecade() {

		 increasedatebydecade(*this);
	 }

	 static clsDate increasedatebyXdecades(clsDate& date, short xDecades) {

		 date.year += xDecades * 10;
		 return date;
	 }

	 void increasedatebyXdecades(short xDecades) {

		 increasedatebyXdecades(*this, xDecades);
	 }

	 static clsDate increasedateby1century(clsDate& date) {

		 date.year += 100;
		 return date;
	 }

	 void increasedateby1century() {

		 increasedateby1century(*this);
	 }

	 static clsDate increasedateby1millinium(clsDate& date) {

		 for (int i = 0; i < 10; i++) {
			 date = increasedateby1century(date);
		 }
		 return date;
	 }

	 void increasedateby1millinium() {
		 increasedateby1millinium(*this);
	 }

	//______________________________________________________________

	 static clsDate decreasedatebyxdays(clsDate& date, short xDays) {

		 for (int i = 0; i < xDays; i++) {

			 date = decreasedatebyoneday(date);

		 }

		 return date;
	 }

	 void decreasedatebyxdays(short xDays) {

		 decreasedatebyxdays(*this, xDays);
	 }

	 static clsDate decreasedateby1week(clsDate& date) {

		 for (int i = 0; i < 7; i++) {

			 date = decreasedatebyoneday(date);

		 }

		 return date;
	 }

	 void decreasedateby1week() {

		 decreasedateby1week(*this);
	 }

	 static clsDate decreasedatebyXweeks(clsDate& date, short xWeeks) {

		 for (int i = 0; i < xWeeks; i++) {

			 date = decreasedateby1week(date);

		 }

		 return date;
	 }

	 void decreasedatebyXweeks(short xWeeks) {

		 decreasedatebyXweeks(*this, xWeeks);
	 }

	 static clsDate decreasedateby1month(clsDate& date) {

		 int monthdays = numOfDaysInMonth(date.year, date.month);

		 date = decreasedatebyxdays(date, monthdays);

		 return date;
	 }

	 void decreasedateby1month() {

		 decreasedateby1month(*this);
	 }

	 static clsDate decreasedatebyXmonth(clsDate& date, short xMonths) {

		 for (int i = 0; i < xMonths; i++) {

			 date = decreasedateby1month(date);
		 }
		 return date;
	 }

	 void decreasedatebyXmonth(short xMonths) {

		 decreasedatebyXmonth(*this, xMonths);
	 }

	 static clsDate decreasedateby1year(clsDate& date) {

		 date.year++;
		 return date;
	 }

	 void decreasedateby1year() {

		 decreasedateby1year(*this);
	 }

	 static clsDate decreasedatebyXyears(clsDate& date, int xYears) {

		 for (int i = 0; i < xYears; i++) {

			 date = decreasedateby1year(date);
		 }
		 return date;
	 }

	 void decreasedatebyXyears(int xYears) {

		 decreasedatebyXyears(*this, xYears);
	 }

	 static clsDate decreasedatebydecade(clsDate& date) {

		 date.year += 10;
		 return date;
	 }

	 void decreasedatebydecade() {

		 decreasedatebydecade(*this);
	 }

	 static clsDate decreasedatebyXdecades(clsDate& date, short xDecades) {

		 date.year += xDecades * 10;
		 return date;
	 }

	 void decreasedatebyXdecades(short xDecades) {

		 decreasedatebyXdecades(*this, xDecades);
	 }

	 static clsDate decreasedateby1century(clsDate& date) {

		 date.year += 100;
		 return date;
	 }

	 void decreasedateby1century() {

		 decreasedateby1century(*this);
	 }

	 static clsDate decreasedateby1millinium(clsDate& date) {

		 for (int i = 0; i < 10; i++) {
			 date = decreasedateby1century(date);
		 }
		 return date;
	 }

	 void decreasedateby1millinium() {
		 decreasedateby1millinium(*this);
	 }

	//_____________________________________________________________

	 static bool isEndOfWeekDay(clsDate date) {

		 return dayOfWeekOrder(date.year,date.month,date.year) == 6;

	 }

	 bool isEndOfWeekDay() {

		 return isEndOfWeekDay(*this);
	 }

	static bool isWeekEnd(clsDate date) {

		 int dayorder = dayOfWeekOrder(date.year,date.month,date.year);

		 return (dayorder == 5 || dayorder == 6);
	 }

	bool isWeekEnd() {

		return isWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate date) {

		 return !isWeekEnd(date);
	 }

	bool isBusinessDay() {

		return isBusinessDay(*this);
	}

	 static short daystillendofweek(clsDate date) {

		 return 6 - dayOfWeekOrder(date.year,date.month,date.day);

	 }

	 short daystillendofweek() {

		 return daystillendofweek(*this);
	 }

	 static short daystillendofmonth(clsDate date) {

		 
		 clsDate endOfMonthDate;
		 endOfMonthDate.day = numOfDaysInMonth(date.year, date.month);
		 endOfMonthDate.month = date.month;
		 endOfMonthDate.year = date.year;

		 return diffbetween2dates(date, endOfMonthDate);

	 }

	 short daystillendofmonth() {

		 return daystillendofmonth(*this);
	 }

	 static short daystillendofyear(clsDate date) {

		 clsDate endOfYearDate;
		 endOfYearDate.day = 31;
		 endOfYearDate.month = 12;
		 endOfYearDate.year = date.year;

		 return diffbetween2dates(date, endOfYearDate);

	 }

	 short daystillendofyear() {

		 return daystillendofyear(*this);
	 }

	 static short actualVacDays(clsDate vacstarts, clsDate vacEnds) {

		 int vacDays = 0;

		 while (isdate1beforedate2(vacstarts, vacEnds)) {

			 if (!isWeekEnd(vacstarts)) {

				 vacDays++;
			 }

			 increasedatebyoneday(vacstarts);
		 }
		 return vacDays;
	 }

	 short actualVacDays(clsDate vacEnds) {

		 return actualVacDays(*this, vacEnds);
	 }

	 static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	 {

		 short Days = 0;
		 while (isdate1beforedate2(DateFrom, DateTo))
		 {
			 if (isBusinessDay(DateFrom))
				 Days++;

			 DateFrom = increasedatebyoneday(DateFrom);
		 }

		 return Days;

	 }

	 //___________________________________________________________

	 enum encomparedates { After = 1, Equal = 0, Before = -1 };

	 static encomparedates comparedates(clsDate date1, clsDate date2) {

		 if (isdate1Afterdate2(date1, date2)) {
			 return encomparedates::After;
		 }

		 if (isdate1beforedate2(date1, date2)) {
			 return encomparedates::Before;
		 }

		 return encomparedates::Equal;
	 }

	 encomparedates comparedates(clsDate date2) {

		 return comparedates(*this, date2);
	 }


	//____________________________________________________________

	static string dateToString(clsDate date) {

		return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	}
	
	string dateToString() {

		return dateToString(*this);
	}

	void print() {

		cout << dateToString() << endl;
	}

	static clsDate getCurrentDate() {

		time_t t = time(0);
		tm* now = localtime(&t);

		short day, month, year;

		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;

		return clsDate(day, month, year);
	}


	static string getCurrentTime() {
		auto now = chrono::system_clock::now();
		time_t time_now = chrono::system_clock::to_time_t(now);
		string timeString = ctime(&time_now);
		return timeString;
	}


	static string getCurrentTimeOnly() {
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::string timeString = std::ctime(&now);

		// Extract time part (HH:MM:SS) from the ctime string
		size_t pos = timeString.find_first_of(":");
		if (pos != std::string::npos) {
			timeString = timeString.substr(pos - 2, 8); // Extract the time part (HH:MM:SS)
		}

		return timeString;
	}

	static bool isValidDate(clsDate date) {

		return (date.day <= numOfDaysInMonth(date.year, date.month) && date.day >= 1) && (date.month >= 1 && date.month <= 12);

	}

	bool isValidDate() {

		return isValidDate(*this);
	}

};

