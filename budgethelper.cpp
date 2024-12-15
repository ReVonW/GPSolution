/*
File: BudgetHelper.cpp
Authors: Nathan and ReVon
Date: December 14,2024
Purpose: Implementation filt for the BudgetHelper class.
        This contains the definitions for all member functions.
*/

#include "BudgetHelper.h"

BudgetHelper::BudgetHelper(const std::string& name) : userName(name) {}
// Initializes the user name


/*
Function: addIncome
Purpose: This adds a validated income amount to the income vector.
- amount: A double representation of the income amount to be added.
*/
void BudgetHelper::addIncome(double amount) {
    validateAmount(amount);
    income.push_back(amount);
}


/*
Function: addExpense
Purpose: This adds a validated expense amount to the expense vector.
-amount: A double representation of the income amount to be added.
*/
void BudgetHelper::addExpense(double amount) {
    validateAmount(amount);     // Validates the input amount.
    expenses.push_back(amount); // Adds the amouunt into the income vector.
}


/*
Function: calculateTotalIncome
Purpose: This computes the total sum of all the income entries entered.
Return: Double representation of the total income
*/
double BudgetHelper::calculateTotalIncome() const {
    double total = 0.0;     // Initializes the total income to zero.
    for (double amount : income) {
        total += amount;    // Adds each income entry to the total.
    }
    return total;           // Returns the calculated total income.
}


/*
Function: calculateTotalExpense
Purpose: This computes the total sum of all the expenses entries entered.
Return: Double representation of the total expenses.
*/
double BudgetHelper::calculateTotalExpenses() const {
    double total = 0.0;     // Initializes the total expenses to zero.
    for (double amount : expenses) {
        total += amount;    // Adds each expense entry to the total.
    }
    return total;           // Returns the calculated total expenses.
}


/*
Function: calculateSavings
Purpose: Computes the remaining amount of savings as the total income minus the total expenses.
*/
double BudgetHelper::calculateSavings() const {
    return calculateTotalIncome() - calculateTotalExpenses();
}

/*
Function: displaySummary
Purpose: This displays a summary of the user's income, expenses, and savings.
*/
void BudgetHelper::displaySummary() const {
    std::cout << "Budget Summary for " << userName << ":\n";
    std::cout << "-------------------------\n";
    std::cout << "Total Income: $" << calculateTotalIncome() << '\n';
    std::cout << "Total Expenses: $" << calculateTotalExpenses() << '\n';
    std::cout << "Savings: $" << calculateSavings() << '\n';
    std::cout << "-------------------------\n";
}


/*
Function: validateAmount
Purpose: Makes sure that the entered amount is a positive number.
- amount: Refers to a double value representing the amount entered.
*/
void BudgetHelper::validateAmount(double& amount) {
    while (amount <= 0 || std::cin.fail()) {    // Makes sure that the input is greater than zero.
        std::cin.clear();                       // Clears errors
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin >> amount;                     // Re-enter the amount
    }
}
