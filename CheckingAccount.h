//
// Created by Henoc Kabeya on 10/11/26.
//

#ifndef INHERITANCE_CHECKINGACCOUNT_H
#define INHERITANCE_CHECKINGACCOUNT_H

#include <string>
#include "BankAccount.h"

/**
 * @class CheckingAccount
 * @brief Represents a transaction-based checking account derived from BankAccount.
 *
 * Inherits fundamental account attributes and behaviors from BankAccount while
 * enforcing an additional transaction surcharge on withdrawal operations.
 */
class CheckingAccount : public BankAccount {
private:
    /**
     * @brief Flat fee deducted on every withdrawal transaction.
     */
    double transactionFee;

public:
    /**
     * @brief Constructs a new CheckingAccount object.
     *
     * Passes common account properties to the base BankAccount constructor
     * via member initializer list and initializes the custom transaction fee.
     *
     * @param accNum Unique alphanumeric identification string for the account.
     * @param accHolder Full legal name of the account holder.
     * @param initialBalance Starting monetary balance deposited into the account.
     * @param fee Surcharge amount applied to each withdrawal.
     */
    CheckingAccount(string accNum, string accHolder, double initialBalance, double fee);

    /**
     * @brief Withdraws funds by deducting the requested amount plus the transaction fee.
     *
     * Overrides BankAccount::operator-= polymorphically to compute the total
     * deduction (amount + transactionFee) before executing balance validation
     * and withdrawal through the base class.
     *
     * @param amount The monetary amount to withdraw from the account.
     * @return BankAccount& Reference to the updated BankAccount instance (*this).
     */
    virtual BankAccount& operator-=(double amount) override;
};

#endif //INHERITANCE_CHECKINGACCOUNT_H

