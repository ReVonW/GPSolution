/*
File: BudgetHelper.h
Authors: Nathan and ReVon
Date: December 14,2024
Purpose: This file contains the class declaration and members variables for the 
        management of income, expenses, and calculating savings.
*/

#ifndef BUDGETHELPER_H
#define BUDGETHELPER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

/*
Purpose: This class ensures that the users are able to manage their budget
        budget by tracking their income and expenses, calculating their
        savings, and displaying a summary of the budget.
*/
class BudgetHelper {
private:
    std::vector<double> income;     // Stores all of the income amount entered by the user.
    std::vector<double> expenses;   // Stores all of the expenses entered by the user.
    std::string userName;           // Name of the user managing the budget.   

public:
    BudgetHelper(const std::string& name);  // Initializes the user name.

    void addIncome(double amount);          // Adds income amount to the budget.
    void addExpense(double amount);         // Adds expense amount to the budget.
    double calculateTotalIncome() const;    // Calculates the total income.
    double calculateTotalExpenses() const;  // Calculates the to expenses.
    double calculateSavings() const;        // Calculates the remaining amount of savings(income - expenses).
    void displaySummary() const;            // Displays the budget summary.
    void validateAmount(double& amount);    // Ensures that the entered amount is a positive number.
};

#endif
