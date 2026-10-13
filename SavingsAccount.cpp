//
// Created by Henoc Kabeya on 10/11/26.
//

#include "SavingsAccount.h"
#include <iostream>

/**
 * @brief Constructs a new SavingsAccount object by initializing base account details
 *        and setting the interest rate.
 *
 * Invokes the base BankAccount constructor via the member initializer list
 * to set the account number, holder name, and starting balance, then initializes
 * the specialized interestRate member.
 *
 * @param accNum Unique identification string for the account.
 * @param accHolder Legal name of the account holder.
 * @param initialBalance Starting monetary balance for the account.
 * @param rate Annual/periodic interest rate expressed in decimal form (e.g., 0.05 for 5%).
 */
SavingsAccount::SavingsAccount(string accNum, string accHolder, double initialBalance, double rate)
    : BankAccount(accNum, accHolder, initialBalance), interestRate(rate) {
}

/**
 * @brief Calculates accrued interest based on the current balance and deposits it.
 *
 * Computes interest as (balance * interestRate) and credits the resulting amount
 * directly back into the account balance using the inherited BankAccount::operator+=.
 */
void SavingsAccount::calculateInterest() {
    double interest = getBalance() * interestRate;
    *this += interest;
}