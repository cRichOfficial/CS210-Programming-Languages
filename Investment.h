/**
* File: Investment.h
* Author: Christopher Richards
* Date: 04/03/2022
*
*/

#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>

std::string CenterText(std::string t_text, int t_colWidth); // Helper function declaration for center text.
void Wait(std::string t_displayText);

class Investment
{
public:
	Investment(); // Default constructor.
	Investment(double t_principal, double t_monthlyContribution, double t_rate, int t_years); // Constructor.
	
	enum class ReportType { HEAD = 0, TAIL = 1, HEAD_TAIL = 2, FULL = 3 }; // Enum for reporting type. This ensures we pick on of these 4.
	
	// Getter and Setter method declarations.
	void SetPrincipal(double t_principal);
	double GetPrincipal(); 
	void SetMonthlyContribution(double t_monthlyContribution);
	double GetMonthlyContribution();
	void SetRate(double t_rate);
	double GetRate();
	void SetYears(int t_years);
	int GetYears();
	// End of Getter and Setter methods declarations.
	
	double GetFutureValue(); // Returns the total investment value at the end of the term (m_years).
	void PrintYearlyEarningReport(ReportType t_reportType); // Prints an investment Balance report by year.
	void PrintSummary(); // Prints an initial summary of the investment (beginning principal, monthlyContribution, rate and total years).

private:
	// Private member data.
	double m_principal;
	double m_monthlyContribution;
	double m_rate;
	int const m_COMPOUNDING_PERIODS = 12; // Number of compounding periods is constant. 12 = monthly
	int m_years;
	// End private member data.
	
	// Private member data for report formatting.
	const int m_REPORT_COL_1_WIDTH = 10;
	const int m_REPORT_COL_2_WIDTH = 40;
	const int m_REPORT_COL_3_WIDTH = 40;
	const int m_REPORT_TOTAL_COLS_WIDTH = m_REPORT_COL_1_WIDTH + m_REPORT_COL_2_WIDTH + m_REPORT_COL_3_WIDTH;
	const int m_REPORT_NUM_HEAD = 5;
	const int m_REPORT_NUM_TAIL = 5;
	const int m_REPORT_PAGE_SIZE = 10;
	// End private member data for report formatting.

	double CalculatePrincipalPlusInterest(int t_year); // Calculates the total investment with compounding interest for specified number of years (contribution not included).
	double CalculatePrincipalPlusInterest(); // Calculates the total investment with compounding interest for specified number of years (contribution not included). Uses m_years if argument left blank.
	double CalculatePrincipalInterestOnly(int t_year); // Calculates the interest on principal accrued for the specified year (1 = first year, 10 = 10th year).
	double CalculatePrincipalInterestOnly(); // Calculates the interest accrued on principal for the specified year (1 = first year, 10 = 10th year). Uses m_years if argument left blank.
	double CalculateContributionPlusInterest(int t_year); // Calculates the total investment with compounding interest for specified number of years (principal not included, monthly contribution is included).
	double CalculateContributionPlusInterest(); // Calculates the total investment with compounding interest for specified number of years (principal not included, monthly contribution is included). Uses m_years if argument left blank.
	double CalculateContributionInterestOnly(int t_year); // Calculates the interest accrued on contributions for the specified year (1 = first year, 10 = 10th year).
	double CalculateContributionInterestOnly(); // Calculates the interest accrued on contributions for the specified year (1 = first year, 10 = 10th year). Uses m_years if left blank.
	double CalculateInterestForYear(int t_year); // Calculates total interest (principal + contributions) for the specified year (1 = first year, 10 = 10th year).
	double CalculateInterestForYear(); // Calculates total interest (principal + contributions) for the specified year (1 = first year, 10 = 10th year). Uses m_years if left blank.
	void PrintReportHeader(); // Prints reporting header.
	void PrintReportBody(int t_start, int t_end); // Prints contents of report.
	void PrintReportTruncLine(); // Prints a truncating line for HEAD, TAIL and HEAD_TAIL reports.
	void PrintReportClear(); // Clears the screen.

};

#endif