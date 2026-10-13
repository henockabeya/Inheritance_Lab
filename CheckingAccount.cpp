//
// Created by Henoc Kabeya on 10/11/26.
//

#include "CheckingAccount.h"
#include <iostream>


/**
 * @brief Constructs a CheckingAccount instance with baseline details and a custom withdrawal fee.
 *
 * Chains to the parent BankAccount constructor via the member initializer list
 * to initialize the account number, account holder name, and starting balance,
 * then initializes the specialized transactionFee member.
 *
 * @param accNum Unique alphanumeric identification string for the account.
 * @param accHolder Legal name of the account holder.
 * @param initialBalance Starting monetary balance for the account.
 * @param fee Surcharge applied on top of each withdrawal transaction.
 */
CheckingAccount::CheckingAccount(string accNum, string accHolder, double initialBalance, double fee)
    : BankAccount(accNum, accHolder, initialBalance), transactionFee(fee) {}

/**
 * @brief Processes a withdrawal by adding the transaction fee to the requested amount.
 *
 * Computes the total deduction (amount + transactionFee) and delegates execution
 * to BankAccount::operator-=, which performs positive-value checks, balance validation,
 * and the actual deduction from the balance.
 *
 * @param amount Monetary amount requested for withdrawal.
 * @return BankAccount& Reference to the updated BankAccount instance (*this).
 */
BankAccount& CheckingAccount::operator-=(double amount) {
    double totalAmount = amount + transactionFee;
    return BankAccount::operator-=(totalAmount);
}