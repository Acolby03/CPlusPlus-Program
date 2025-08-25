// Banking.cpp
#include <iostream>
#include <iomanip>
#include "Banking.h"

using namespace std;

// Constructor
Banking::Banking(double initialInvestment, double monthlyDeposit,
    double annualInterest, int numYears) {
    this->InitialInvestment = initialInvestment;
    this->MonthlyDeposit = monthlyDeposit;
    this->AnnualInterest = annualInterest;
    this->NumYears = numYears;
}

// Setters
void Banking::setInitialInvestment(double initialInvestment) {
    this->InitialInvestment = initialInvestment;
}

void Banking::setMonthlyDeposit(double monthlyDeposit) {
    this->MonthlyDeposit = monthlyDeposit;
}

void Banking::setAnnualInterest(double annualInterest) {
    this->AnnualInterest = annualInterest;
}

void Banking::setNumYears(int numYears) {
    this->NumYears = numYears;
}

// Utility function to print investment details
void printDetails(int year, double yearEndBalance, double interestEarned) {
    cout << fixed << setprecision(2);
    cout << year << "\t\t$" << yearEndBalance << "\t\t$" << interestEarned << endl;
}

// Calculates and prints balance without monthly deposits
double Banking::calculateBalanceWithoutMonthlyDeposit()const {
    double balance = InitialInvestment;
    double monthlyRate = (AnnualInterest * 0.01) / 12;
    double monthlyInterest, yearlyInterest;

    cout << "\nYear\t\tYear End Balance\t\tInterest Earned" << endl;

    for (int year = 1; year <= NumYears; ++year) {
        yearlyInterest = 0;

        for (int month = 1; month <= 12; ++month) {
            monthlyInterest = balance * monthlyRate;
            balance += monthlyInterest;
            yearlyInterest += monthlyInterest;
        }

        printDetails(year, balance, yearlyInterest);
    }

    return balance;
}

// Calculates and prints balance with monthly deposits
double Banking::balanceWithMonthlyDeposit()const {
    double balance = InitialInvestment;
    double monthlyRate = (AnnualInterest * 0.01) / 12;
    double monthlyInterest, yearlyInterest;

    cout << "\nYear\t\tYear End Balance\t\tInterest Earned" << endl;

    for (int year = 1; year <= NumYears; ++year) {
        yearlyInterest = 0;

        for (int month = 1; month <= 12; ++month) {
            balance += MonthlyDeposit;
            monthlyInterest = balance * monthlyRate;
            balance += monthlyInterest;
            yearlyInterest += monthlyInterest;
        }

        printDetails(year, balance, yearlyInterest);
    }

    return balance;
}

// Displays both reports
void Banking::displayReports() const {
    cout << "\n  Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================" << endl;
    calculateBalanceWithoutMonthlyDeposit();

    cout << "\n  Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    balanceWithMonthlyDeposit();
}
