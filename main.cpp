/**
 * Brief: Interactive console controller for the Bank of Modesto account management system.
 * Author: Henoc Kabeya
 * Date: October 12, 2026
 *
 * Purpose:
 *   - Encapsulate individual account state within a BankAccount class.
 *   - Manage a dynamic list of BankAccount objects using std::vector.
 *   - Provide an interactive, menu-driven CLI for account creation,
 *     deposits, withdrawals, and account record retrieval.
 */

#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief Main entry point of the banking application.
 *        Executes a loop-driven interactive CLI allowing users to create accounts,
 *        deposit/withdraw money, and display individual account records.
 * @return Exit status integer (0 for successful termination).
 */
int main() {
    // Dynamic array to store multiple customer accounts
    vector <BankAccount*> accounts;
    int choice = 0;
    do {
        // Display Menu Options
        cout << "\n=========================================\n";
        cout << "               Bank of Modesto             \n";
        cout << "===========================================\n";
        cout << "1. Create a New Account" << endl;
        cout << "2. Deposit Funds" << endl;
        cout << "3. Withdraw Funds" << endl;
        cout << "4. Display Account Details " << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice(1-5): ";

        // Menu choice validation
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
            switch (choice) {
        // =================================================================
        // Case 1: Account Creation (Polymorphic Dynamic Allocation)
        // =================================================================
        /**
         * Prompts the user to select an account subtype (Standard, Checking,
         * or Savings), collects shared base details (account number, holder
         * name, opening balance), and dynamically allocates the appropriate
         * derived object on the heap before storing its pointer in the vector.
         */
        case 1: {
            int typeChoice;
            cout << "\nEnter account type: \n";
            cout << "1. Standard Bank Account\n";
            cout << "2. Checking Account\n";
            cout << "3. Savings Account\n";
            cout << "Choice: ";
            cin >> typeChoice;

            string accNum, accHolder;
            double initialBalance;

            // Prompt and read shared base account attributes
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter account holder name: ";
            // Discard trailing newline before reading full name via getline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, accHolder);
            cout << "Enter initial balance: ";
            cin >> initialBalance;

            // Branch based on account subtype selection
            if (typeChoice == 1) {
                // Dynamically allocate base BankAccount instance
                accounts.push_back(new BankAccount(accNum, accHolder, initialBalance));
            } else if (typeChoice == 2) {
                // Collect Checking-specific attribute and instantiate CheckingAccount
                double fee;
                cout << "Enter transaction fee: ";
                cin >> fee;
                accounts.push_back(new CheckingAccount(accNum, accHolder, initialBalance, fee));
            } else if (typeChoice == 3) {
                // Collect Savings-specific attribute and instantiate SavingsAccount
                double rate;
                cout << "Enter interest rate (e.g., 0.05 for 5%): ";
                cin >> rate;
                accounts.push_back(new SavingsAccount(accNum, accHolder, initialBalance, rate));
            } else {
                cout << "Invalid account type selected.\n";
            }
            break;
        }

        // =================================================================
        // Case 2: Deposit Funds (In-place Operator Overload)
        // =================================================================
        /**
         * Performs a linear search across the pointer collection matching by
         * account number. Once found, deposits funds using the overloaded +=
         * operator directly on the dereferenced object.
         */
        case 2: {
            string searchAccNum;
            cout << "Enter account number: ";
            cin >> searchAccNum;

            bool found = false;
            // Iterate through the vector of base pointers
            for (auto & accountPtr : accounts) {
                if (accountPtr->getAccountNumber() == searchAccNum) {
                    found = true;
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    // Dereference pointer to invoke overloaded operator+=
                    *accountPtr += amount;
                    break;
                }
            }
            if (!found) {
                cout << "Account number not found. Please try again." << endl;
            }
            break;
        }

        // =================================================================
        // Case 3: Withdraw Funds (Polymorphic Dynamic Dispatch)
        // =================================================================
        /**
         * Performs a linear search for a target account and applies a withdrawal.
         * Dereferencing accountPtr with operator-= triggers dynamic binding,
         * ensuring overridden rules (e.g., CheckingAccount transaction fees)
         * execute correctly at runtime.
         */
        case 3: {
            string searchAccNum;
            cout << "Enter account number: ";
            cin >> searchAccNum;

            bool found = false;
            for (auto & accountPtr : accounts) {
                if (accountPtr->getAccountNumber() == searchAccNum) {
                    found = true;
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    // Dereference pointer to invoke virtual operator-= (polymorphic call)
                    *accountPtr -= amount;
                    break;
                }
            }
            if (!found) {
                cout << "Account number not found. Please try again." << endl;
            }
            break;
        }

        // =================================================================
        // Case 4: Display Account Details (Static Utility Invocation)
        // =================================================================
        /**
         * Searches for a record by account number and outputs account
         * details using the static utility method BankAccount::printAccount.
         */
        case 4: {
            string searchAccNum;
            cout << "Enter account number: ";
            cin >> searchAccNum;

            bool found = false;
            for (const auto & accountPtr : accounts) {
                if (accountPtr->getAccountNumber() == searchAccNum) {
                    found = true;
                    // Pass dereferenced object into static utility function
                    BankAccount::printAccount(*accountPtr);
                    break;
                }
            }

            if (!found) {
                cout << "Account not found." << endl;
            }
            break;
        }

        // =================================================================
        // Case 5: Memory Cleanup & Exit
        // =================================================================
        /**
         * Traverses the vector to delete all dynamically allocated objects on
         * the heap (invoking virtual destructors), clears the vector pointers,
         * and prepares the program to exit the menu loop.
         */
        case 5: {
            // Free all heap-allocated objects to prevent memory leaks
            for (BankAccount* accountPtr : accounts) {
                delete accountPtr;
            }
            accounts.clear(); // Clear dangling pointers from vector
            cout << "Thank you for choosing Bank of Modesto." << endl;
            break;
        }

        // =================================================================
        // Default Case: Input Fallback
        // =================================================================
        default:
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            break;
    }

        } while (choice != 5);
            return 0;
}



