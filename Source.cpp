/**
* File: Source.cpp
* Author: Christopher Richards
* Date: 04/03/2022
* 
*/

#include "Investment.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Initialize variables.
	double principal = -999.99;
	double monthlyContribution = -999.99;
	double rate = -9.99;
	int years = 99;
	
	// Application description.
	cout << "This application calculates total investment after a number of years of compounding-interest." << endl;
	cout << "It will first display the summary and specified report of an investment with no monthly deposits and an" << endl;
	cout << "investment with a monthly deposit amount specified by you." << endl << endl;

	// Get initial investment amount. Ignore non-digit characters.
	cout << "Enter initial investment amount: ";
	while (!isdigit(cin.peek())) {
		cin.ignore();
	}
	cin >> principal;

	// Get monthly contribution amount. Ignore non-digit characters.
	cout << "Enter the monthly deposit you'd like to contribute: ";
	while (!isdigit(cin.peek())) {
		cin.ignore();
	}
	cin >> monthlyContribution;

	// Get percentage rate. Ignore non-digit characters.
	cout << "Enter the annual interest rate in percent: ";
	while (!isdigit(cin.peek())) {
		cin.ignore();
	}
	cin >> rate;

	// Get number of years for investment. Ignore non-digit characters.
	cout << "Enter total number of years to keep this investment: ";
	while (!isdigit(cin.peek())) {
		cin.ignore();
	}
	cin >> years;
	
	cin.ignore();

	// Initialize two investmet objects. One with contribution and one without.
	Investment investmentWithContribution = Investment(principal, monthlyContribution, rate, years);
	Investment investmentWithoutContribution = Investment(principal, 0, rate, years);

	// Print information about investment without contribution.
	investmentWithoutContribution.PrintSummary();
	investmentWithoutContribution.PrintYearlyEarningReport(Investment::ReportType::FULL);

	// Print information about investment with contriblution.
	investmentWithContribution.PrintSummary();
	investmentWithContribution.PrintYearlyEarningReport(Investment::ReportType::FULL);
	
	Wait("Press <ENTER> to exit...");

	return (0);
}