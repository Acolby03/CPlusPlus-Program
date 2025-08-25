// Banking.h
#ifndef BANKING_H_
#define BANKING_H_

class Banking {
public:
    // Constructor
    Banking(double initialInvestment, double monthlyDeposit,
        double annualInterest, int numYears);

    // Setters
    void setInitialInvestment(double initialInvestment);
    void setMonthlyDeposit(double monthlyDeposit);
    void setAnnualInterest(double annualInterest);
    void setNumYears(int numYears);

    // Calculation methods
    double calculateBalanceWithoutMonthlyDeposit() const;
    double balanceWithMonthlyDeposit()const;

    // Display report
    void displayReports() const;

private:
    double InitialInvestment;
    double MonthlyDeposit;
    double AnnualInterest;
    int NumYears;
};

// Global utility function
void printDetails(int year, double yearEndBalance, double interestEarned);

#endif // BANKING_H_
