/**
 * Brief: Implementation of member methods, operators, and utilities for BankAccount.
 * Author: Henoc Kabeya
 * Date: October 5, 2026
 */

#include "BankAccount.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor initializing members to empty strings and a balance of 0.0.
 */
BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    Balance = 0.0;
}

/**
 * @brief Parameterized constructor assigning specified field values.
 * @param accNum Account number string.
 * @param accHolder Account holder name string.
 * @param initialBalance Initial balance value.
 */
BankAccount::BankAccount(string accNum, string accHolder, double initialBalance) {
    accountNumber = accNum;
    accountHolderName = accHolder;
    Balance = initialBalance;
}

/**
 * @brief Destructor for BankAccount.
 */
BankAccount::~BankAccount() {}

/**
 * @brief Copy constructor copying attributes from an existing instance.
 * @param other The existing BankAccount instance to copy.
 */
BankAccount::BankAccount(const BankAccount& other)
    : accountNumber(other.accountNumber), accountHolderName(other.accountHolderName), Balance(other.Balance) {}

/**
 * @brief Copy assignment operator guarding against self-assignment.
 * @param other The right-hand-side BankAccount to copy.
 * @return Reference to the current BankAccount instance (*this).
 */
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        Balance = other.Balance;
    }
    return *this;
}

/**
 * @brief Returns the account number.
 * @return String representation of the account number.
 */
string BankAccount::getAccountNumber() const {
    return accountNumber;
}

/**
 * @brief Returns the name of the account holder.
 * @return String containing the account holder's name.
 */
string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

/**
 * @brief Returns the current balance.
 * @return Balance as a double.
 */
double BankAccount::getBalance() const {
    return Balance;
}

/**
 * @brief Mutator method to set a new account holder name.
 * @param newName The updated holder name.
 */
void BankAccount::setAccountHolderName(string newName) {
    accountHolderName = newName;
}

/**
 * @brief Adds a valid positive amount to the account balance.
 * @param amount Numeric value to deposit.
 * @return Reference to the modified BankAccount object (*this).
 */
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0.0) {
        Balance += amount;
        cout << "The deposit was successfully processed." << endl;
    } else {
        cout << "The deposit was unsuccessful. It must be positive." << endl;
    }
    return *this;
}

/**
 * @brief Deducts an amount from balance if funds are sufficient and amount is positive.
 * @param amount Numeric value to withdraw.
 * @return Reference to the modified BankAccount object (*this).
 */
BankAccount& BankAccount::operator-=(double amount) {
    if (amount <= 0.0) {
        cout << "The withdrawal must be positive. Please, try again." << endl;
    } else if (amount > Balance) {
        cout << "Error. Insufficient funds in the account." << endl;
    } else {
        Balance -= amount;
        cout << "The withdrawal was successfully processed." << endl;
    }
    return *this;
}

/**
 * @brief Compares two account IDs for equality.
 * @param other The account to compare against.
 * @return true if account numbers match; false otherwise.
 */
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

/**
 * @brief Determines if this account holds less money than another.
 * @param other The account to compare against.
 * @return true if this account's balance is lower; false otherwise.
 */
bool BankAccount::operator<(const BankAccount& other) const {
    return Balance < other.Balance;
}

/**
 * @brief Determines if this account holds more money than another.
 * @param other The account to compare against.
 * @return true if this account's balance is higher; false otherwise.
 */
bool BankAccount::operator>(const BankAccount& other) const {
    return Balance > other.Balance;
}

/**
 * @brief Prints account number, holder name, and balance to the terminal.
 * @param account The BankAccount instance to print.
 */
void BankAccount::printAccount(const BankAccount& account) {
    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Account Holder: " << account.getAccountHolderName() << endl;
    cout << "Account Balance: $" << account.getBalance() << endl;
}

/**
 * @brief Collects user input from the console and instantiates a new account.
 * @return A newly constructed BankAccount instance populated with user data.
 */
BankAccount BankAccount::createAccountFromInput() {
    string accNum, accHolder;
    double initialBalance;
    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter account holder name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, accHolder);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    return BankAccount(accNum, accHolder, initialBalance);
}


