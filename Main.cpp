#include <iostream>
#include <limits>
#include "Banking.h"

using namespace std;

// Helper function to get validated double input
double getDouble(double min, const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min) break;
        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

// Helper function to get validated integer input
int getInteger(int min, const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min) break;
        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

int main() {
    char runAgain = 'Y';

    while (toupper(runAgain) == 'Y') {
        cout << "===========================================\n";
        cout << "     Welcome to the Airgead Banking App     \n";
        cout << "===========================================\n\n";

        double initialInvestment = getDouble(1, "Enter Initial Investment Amount (min $1): $");
        double monthlyDeposit = getDouble(0, "Enter Monthly Deposit (min $0): $");
        double annualInterest = getDouble(1, "Enter Annual Interest Rate (min 1%): ");
        int numYears = getInteger(1, "Enter Number of Years (min 1): ");

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

        Banking airgead(initialInvestment, monthlyDeposit, annualInterest, numYears);
        airgead.displayReports();

        cout << "\nWould you like to run another report? (Y/N): ";
        cin >> runAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
    }

    cout << "Thank you for using the Airgead Banking App!\n";
    return 0;
}