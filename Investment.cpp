/**
* File: Investment.cpp
* Author: Christopher Richards
* Date: 04/03/2022
*
*/

#include "Investment.h"

// Function helps center text to the specified column width.
std::string CenterText(std::string t_text, int t_colWidth) {
	int paddingSize = 0;
	std::string fill;
	paddingSize = (t_colWidth - t_text.length()) / 2;
	fill = std::string(paddingSize, ' ');
	return fill + t_text + fill;
}

// Helper function to wait for user input before continuing.
void Wait(std::string t_displayText) {
	// Display specified text.
	std::cout << t_displayText << std::endl;
	// This loop is necessary to prevent screens from being skipped if user presses a key before <ENTER>.
	while (std::cin.peek() != '\n'){
		std::cin.ignore();
	}
	std::cin.get();
	std::cin.clear();
}

// Default constructor. Initializes everything to 0.0;
Investment::Investment() {
	this->m_principal = 0.0;
	this->m_monthlyContribution = 0.0;
	this->m_rate = 0.0;
	this->m_years = 0;
}

// Constructor. Initializes the private member funcions.
Investment::Investment(double t_principal, double t_monthlyContribution, double t_rate, int t_years) {
	this->m_principal = t_principal;
	this->m_monthlyContribution = t_monthlyContribution;
	this->m_rate = t_rate;
	this->m_years = t_years;
}

//****************************************************************************
// Start Getter and Setter functions

void Investment::SetPrincipal(double t_principal = 0.0) {
	this->m_principal = t_principal;
}

double Investment::GetPrincipal() {
	return this->m_principal;
}

void Investment::SetMonthlyContribution(double t_monthlyContribution) {
	this->m_monthlyContribution = t_monthlyContribution;
}

double Investment::GetMonthlyContribution() {
	return this->m_monthlyContribution;
}

void Investment::SetRate(double t_rate) {
	this->m_rate = t_rate;
}

double Investment::GetRate() {
	return this->m_rate;
}

void Investment::SetYears(int t_years) {
	this->m_years = t_years;
}

int Investment::GetYears() {
	return this->m_years;
}

// End Getter and Setter functions
//****************************************************************************

// Function to return total investment value (principal + contributions).
double Investment::GetFutureValue() {
	return (this->CalculatePrincipalPlusInterest() + this->CalculateContributionPlusInterest());
}

// Function that returns principal + compounding interest for specified number of years.
double Investment::CalculatePrincipalPlusInterest(int t_year) {
	return (this->m_principal * std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * t_year));
}

// Function that returns principal + compounding interest for specified number of years. Uses m_years if argument left blank.
double Investment::CalculatePrincipalPlusInterest() {
	return (this->m_principal * std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * this->m_years));
}

// Function tat returns contributions + interest for specified number of years.
double Investment::CalculateContributionPlusInterest(int t_year) {
	return ((this->m_monthlyContribution * (std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * t_year) - 1) / ((this->m_rate / 100) / this->m_COMPOUNDING_PERIODS)));
}

// Function tat returns contributions + interest for specified number of years. Uses m_years if argument left blank.
double Investment::CalculateContributionPlusInterest() {
	return ((this->m_monthlyContribution * (std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * this->m_years) - 1) / ((this->m_rate / 100) / this->m_COMPOUNDING_PERIODS)));
}

// Function that returns the interest accrued on principal only for specified years.
double Investment::CalculatePrincipalInterestOnly(int t_year) {
	return (this->m_principal * (std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * t_year) - 1));
}

// Function that returns the interest accrued on principal only for specified years. Uses m_years if argument left blank.
double Investment::CalculatePrincipalInterestOnly() {
	return (this->m_principal * (std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * this->m_years) - 1));
}

// FUnction that returns the interest accrued on monthly contributions for specified years.
double Investment::CalculateContributionInterestOnly(int t_year) {
	return ((this->m_monthlyContribution * (std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * t_year) - 1)) / ((this->m_rate / 100) / this->m_COMPOUNDING_PERIODS) - (this->m_monthlyContribution * this->m_COMPOUNDING_PERIODS * t_year));
}

// FUnction that returns the interest accrued on monthly contributions for specified years. Uses m_years if argument left blank.
double Investment::CalculateContributionInterestOnly() {
	return ((this->m_monthlyContribution * (std::pow(1 + (this->m_rate / 100) / this->m_COMPOUNDING_PERIODS, this->m_COMPOUNDING_PERIODS * this->m_years) - 1)) / ((this->m_rate / 100) / this->m_COMPOUNDING_PERIODS) - (this->m_monthlyContribution * this->m_COMPOUNDING_PERIODS * this->m_years));
}

// Calculates interest for a specific year for the investment.
double Investment::CalculateInterestForYear(int t_year) {
	if (t_year == 0) {
		return 0.0;
	}

	// Initialize interest variables.
	double principalInterestForYear = -999.99;
	double contributionInterestForYear = -999.99;

	// Subtract the value of specified year principal + interest from previous year (specified year's starting balance).
	principalInterestForYear = (this->CalculatePrincipalPlusInterest(t_year) - this->CalculatePrincipalPlusInterest(t_year - 1));
	// Subtract the value of specified year monthly contributions + interest from previous year (specified year's starting balance).
	contributionInterestForYear = (this->CalculateContributionInterestOnly(t_year) - this->CalculateContributionInterestOnly(t_year - 1));

	// Add the two values to get the total interest paid and return it.
	return (principalInterestForYear + contributionInterestForYear);
}

// Calculates interest for a specific year for the investment. Uses m_years if argument left blank.
double Investment::CalculateInterestForYear() {
	if (this->m_years == 0) {
		return 0.0;
	}

	// Initialize interest variables.
	double principalInterestForYear = -999.99;
	double contributionInterestForYear = -999.99;

	// Subtract the value of specified year principal + interest from previous year (specified year's starting balance).
	principalInterestForYear = (this->CalculatePrincipalPlusInterest(this->m_years) - this->CalculatePrincipalPlusInterest(this->m_years - 1));
	// Subtract the value of specified year monthly contributions + interest from previous year (specified year's starting balance).
	contributionInterestForYear = (this->CalculateContributionInterestOnly(this->m_years) - this->CalculateContributionInterestOnly(this->m_years - 1));

	// Add the two values to get the total interest paid and return it.
	return (principalInterestForYear + contributionInterestForYear);
}


// Function to print report header.
void Investment::PrintReportHeader() {
	std::string reportTitle = "";
	if (this->m_monthlyContribution == 0) {
		reportTitle = "Balance and Interest Without Additional Monthly Deposits";
	}
	else {
		reportTitle = "Balance and Interest With Additional Monthly Deposits";
	}

	std::cout << CenterText(reportTitle, this->m_REPORT_TOTAL_COLS_WIDTH) << std::endl;
	std::cout << std::setw(this->m_REPORT_TOTAL_COLS_WIDTH) << std::setfill('=') << '=' << std::endl;
	std::cout << std::setw(this->m_REPORT_COL_1_WIDTH) << std::setfill(' ') << "Year";
	std::cout << std::setw(this->m_REPORT_COL_2_WIDTH) << std::setfill(' ') << "Year End Balance";
	std::cout << std::setw(this->m_REPORT_COL_3_WIDTH) << std::setfill(' ') << "Year End Earned Interest" << std::endl;
	std::cout << std::setw(this->m_REPORT_TOTAL_COLS_WIDTH) << std::setfill('-') << '-' << std::endl;
}

// Function to print report body. Specifies a start and end. This is for pagination for FULL reports.
void Investment::PrintReportBody(int t_start, int t_end) {
	unsigned int i;
	// stringstream used to aid in contatenating and formating dollar amounts.
	std::stringstream ss;
	for (i = t_start; i <= t_end; ++i) {
		std::cout << std::setw(this->m_REPORT_COL_1_WIDTH) << std::setfill(' ') << i;
		// stringstream used to aid in contatenating and formating dollar amounts.
		ss << '$' << std::fixed << std::setprecision(2) << this->CalculatePrincipalPlusInterest(i) + this->CalculateContributionPlusInterest(i);
		std::cout << std::setw(this->m_REPORT_COL_2_WIDTH) << std::setfill(' ') << ss.str();
		ss.str(std::string());
		// stringstream used to aid in contatenating and formating dollar amounts.
		ss << '$' << std::fixed << std::setprecision(2) << this->CalculateInterestForYear(i);
		std::cout << std::setw(this->m_REPORT_COL_3_WIDTH) << std::setfill(' ') << ss.str();
		std::cout << std::endl;
		ss.str(std::string());
		ss.clear();

	}
}


// Function that prints the yearly earning report. Takes a report type as an argument. FULL report is default report type.
void Investment::PrintYearlyEarningReport(Investment::ReportType t_reportType = Investment::ReportType::FULL) {
	this->PrintReportClear();
	
	// If we don't have more than the number specified for the HEAD and TAIL count, it is a FULL report.
	if ((this->m_years == this->m_REPORT_NUM_HEAD) || ((this->m_years - this->m_REPORT_NUM_TAIL) == 0)) {
		t_reportType = Investment::ReportType::FULL;
	}
	
	// Select which report type to output.	
	switch (t_reportType) {
		// Full report.
		case Investment::ReportType::FULL:
			unsigned int i;
			// Iterate over the span of years from 1 (0 + 1) until m_years and create yearly balance and interest amounts.
			for (i = 0; i <= std::ceil(1.0 * this->m_years / this->m_REPORT_PAGE_SIZE) - 1; ++i) {
				this->PrintReportClear();
				// Print header.
				this->PrintReportHeader();
				// Print report body. Calculate year based on current page and check that we do not exceed m_years.
				this->PrintReportBody((i * this->m_REPORT_PAGE_SIZE) + 1, ((i + 1) * this->m_REPORT_PAGE_SIZE) <= this->m_years ? ((i + 1) * this->m_REPORT_PAGE_SIZE) : this->m_years);
				std::cout << std::endl;
				// Print current page number.
				std::cout << "Page " << i + 1 << "/" << std::ceil(1.0 * this->m_years / this->m_REPORT_PAGE_SIZE) << std::endl;
				
				// Wait for input from user. Change verbiage based on if there are more pages to look through.
				if (i == std::ceil(1.0 * this->m_years / this->m_REPORT_PAGE_SIZE) - 1) {
					Wait("Press <ENTER> to continue...");
				}
				else {
					Wait("Press <ENTER> to go to next page.");
				}
				
			}

			break;

		// HEAD type report. Prints first year through m_REPORT_NUM_HEAD value.
		case Investment::ReportType::HEAD:
			this->PrintReportClear();
			this->PrintReportHeader();
			this->PrintReportBody(1, this->m_REPORT_NUM_HEAD);
			this->PrintReportTruncLine();
			std::cout << std::endl;
			break;
			// TAIL type report. Prints m_years - m_REPORT_NUM_TAIL year through m_year.
		case Investment::ReportType::TAIL:
			this->PrintReportClear();
			this->PrintReportHeader();
			this->PrintReportTruncLine();
			this->PrintReportBody(this->m_years - this->m_REPORT_NUM_TAIL, this->m_years);
			std::cout << std::endl;
			break;

		// HEAD and TAIL combined. Prints first set and last set (first 5 and last 5).
		case Investment::ReportType::HEAD_TAIL:
			this->PrintReportClear();
			this->PrintReportHeader();
			this->PrintReportBody(1, this->m_REPORT_NUM_HEAD);
			this->PrintReportTruncLine();
			this->PrintReportBody(this->m_years - this->m_REPORT_NUM_TAIL, this->m_years);
			std::cout << std::endl;
			break;
	
	}
}

// Outputs trunc line characters for HEAD, TAIL and HEAD_TAIL report types.
void Investment::PrintReportTruncLine() {
	std::cout << std::setw(this->m_REPORT_COL_1_WIDTH) << std::setfill(' ') << std::string(5, '.');
	std::cout << std::setw(this->m_REPORT_COL_2_WIDTH) << std::setfill(' ') << std::string(5, '.');
	std::cout << std::setw(this->m_REPORT_COL_3_WIDTH) << std::setfill(' ') << std::string(5, '.');
	std::cout << std::endl;
}

// Clears the screen between reports.
void Investment::PrintReportClear() {
	std::cout << "\033[2J\033[1;1H";
}

// Prints the summary of the initial investment data.
void Investment::PrintSummary() {
	std::stringstream ss;
	this->PrintReportClear();
	std::cout << std::setw(this->m_REPORT_TOTAL_COLS_WIDTH) << std::setfill('=') << '=' << std::endl;
	std::cout << std::setw(this->m_REPORT_TOTAL_COLS_WIDTH) << std::setfill(' ') << CenterText("Investment Summary", this->m_REPORT_TOTAL_COLS_WIDTH) << std::endl;
	std::cout << std::setw(this->m_REPORT_TOTAL_COLS_WIDTH) << std::setfill('-') << '-' << std::endl;
	std::cout << std::setw(this->m_REPORT_COL_2_WIDTH) << std::setfill(' ') << std::left << "Initial Investment Amount:";
	ss << '$' << std::fixed << std::setprecision(2) << this->m_principal;
	std::cout << std::setw(this->m_REPORT_COL_1_WIDTH) << std::setfill(' ') << ss.str() << std::endl;
	ss.str(std::string());
	std::cout << std::setw(this->m_REPORT_COL_2_WIDTH) << std::setfill(' ') << std::left << "Monthly Deposit:";
	ss << '$' << std::fixed << std::setprecision(2) << this->m_monthlyContribution;
	std::cout << std::setw(this->m_REPORT_COL_1_WIDTH) << std::setfill(' ') << ss.str() << std::endl;
	ss.str(std::string());
	std::cout << std::setw(this->m_REPORT_COL_2_WIDTH) << std::setfill(' ') << std::left << "Annual Interest:";
	ss << std::fixed << std::setprecision(2) << this->m_rate << '%';
	std::cout << std::setw(this->m_REPORT_COL_1_WIDTH) << std::setfill(' ') << ss.str() << std::endl;
	ss.str(std::string());
	std::cout << std::setw(this->m_REPORT_COL_2_WIDTH) << std::setfill(' ') << std::left << "Number of years:";
	std::cout << std::setw(this->m_REPORT_COL_1_WIDTH) << std::setfill(' ') << this->m_years << std::endl;
	ss.str(std::string());
	std::cout << std::right << std::endl;
	Wait("Press <ENTER> to continue...");
}