/*
File: main.cpp
Authors: Nathan and ReVon
Date: December 14,2024
Purpose: This file contains the class declaration and members variables for the 
        management of income, expenses, and calculating savings.
*/

#include "BudgetHelper.h"   // Includes the BudgetHelper class
#include <iostream>         // For input/output operations

void addEntries(BudgetHelper& helper, bool isIncome) {
    int count = 0;
    std::cout << (isIncome ? "How many income entries do you want to add? " : "How many expense entries do you want to add? ");
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        double amount;
        std::cout << (isIncome ? "Enter income amount #" : "Enter expense amount #") << (i + 1) << ": ";
        std::cin >> amount;
        if (isIncome) {
            helper.addIncome(amount);
        } else {
            helper.addExpense(amount);
        }
    }
}

int main() {
// Introduction
    std::string name;
    std::cout << "Welcome to The Budget Helper!\nEnter your name: ";
    std::getline(std::cin, name);
    BudgetHelper helper(name);

// Displays the main menu
    char choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Income\n";
        std::cout << "2. Add Expenses\n";
        std::cout << "3. View Summary\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

// Handles menu options using a switch statement.
        switch (choice) {
            case '1':
                addEntries(helper, true);
                break;
            case '2':
                addEntries(helper, false);
                break;
            case '3':
                helper.displaySummary();    // Displays the budget summary
                break;
            case '4':
                std::cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
