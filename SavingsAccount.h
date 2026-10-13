//
// Created by Henoc Kabeya on 10/11/26.
//

#ifndef INHERITANCE_SAVINGSACCOUNT_H
#define INHERITANCE_SAVINGSACCOUNT_H

#include <string>
#include "BankAccount.h"

/**
 * @class SavingsAccount
 * @brief Represents an interest-bearing bank account derived from BankAccount.
 *
 * Inherits core banking attributes and behaviors from BankAccount while
 * adding interest rate tracking and compound interest accumulation.
 */
class SavingsAccount : public BankAccount {
private:
    /**
     * @brief Annual or periodic interest rate stored as a decimal (e.g., 0.05 for 5%).
     */
    double interestRate;

public:
    /**
     * @brief Constructs a new SavingsAccount instance.
     *
     * Chains to the parent BankAccount constructor to initialize core account
     * data and sets the account's interest rate.
     *
     * @param accNum Unique alphanumeric identifier for the account.
     * @param accHolder Full legal name of the account holder.
     * @param initialBalance Starting monetary balance for the account.
     * @param interest Interest rate expressed in decimal form (e.g., 0.05 for 5%).
     */
    SavingsAccount(string accNum, string accHolder, double initialBalance, double interest);

    /**
     * @brief Calculates interest accrued on the current balance and credits it to the account.
     *
     * Computes accrued interest (balance * interestRate) and deposits it directly
     * into the account balance using the inherited deposit functionality.
     */
    void calculateInterest();
};

#endif //INHERITANCE_SAVINGSACCOUNT_H

