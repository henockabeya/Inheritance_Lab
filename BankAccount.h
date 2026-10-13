/**
 * Brief: Class declaration and interface for BankAccount.
 * Author: Henoc Kabeya
 * @date October 5, 2026
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

/**
 * @class BankAccount
 * @brief Represents a customer bank account with balance tracking and operator overloads.
 */
class BankAccount {
private:
    string accountNumber; /**< Unique alphanumeric identifier for the account. */
    string accountHolderName; /**< Full legal name of the account holder. */
    double Balance; /**< Current monetary balance stored in the account. */

    // ==========================================
    // Constructors & Rule of Three
    // ==========================================

    /**
     * @brief Constructs a new BankAccount object with default empty values and zero balance.
     */
public:
    // Constructors
    BankAccount(); // Declaration of default constructor
    BankAccount(string accNum, string accHolder, double initialBalance); // Declaration of parametrized constructor

    // Rule of Three
    /**
     * @brief Destructor for BankAccount object cleanup.
     */
    virtual ~BankAccount();

    /**
     * @brief Copy constructor that initializes an account from another existing instance.
     * @param other The BankAccount instance to copy from.
     */
    BankAccount(const BankAccount& other);

    /**
     * @brief Copy assignment operator performing deep assignment from another account.
     * @param other The BankAccount instance whose state will be assigned.
     * @return Reference to the updated BankAccount instance (*this).
     */
    BankAccount& operator=(const BankAccount& other);

    // ==========================================
    // Accessors (Getters) & Mutators (Setters)
    // ==========================================

    /**
     * @brief Retrieves the unique account number.
     * @return The account number string.
     */
    string getAccountNumber() const;

    /**
     * @brief Retrieves the name of the account holder.
     * @return The account holder's full name.
     */
    string getAccountHolderName() const;

    /**
     * @brief Retrieves the current account balance.
     * @return The balance as a double-precision floating-point number.
     */
    double getBalance() const;

    /**
     * @brief Updates the account holder's name.
     * @param newName The updated account holder name.
     */
    void setAccountHolderName(string newName);

    // ==========================================
    // Overloaded Operators
    // ==========================================

    /**
     * @brief Deposits funds into the account in-place using addition assignment.
     * @param amount The monetary value to deposit (must be strictly positive).
     * @return Reference to the calling BankAccount instance.
     */
    BankAccount& operator+=(double amount);

    /**
     * @brief Withdraws funds from the account in-place using subtraction assignment.
     * @param amount The monetary value to withdraw (must be positive and <= balance).
     * @return Reference to the calling BankAccount instance.
     */
    virtual BankAccount& operator-=(double amount);

    /**
     * @brief Tests equality between two accounts based on account number.
     * @param other The target BankAccount to compare against.
     * @return true if both accounts share the same account number; false otherwise.
     */
    bool operator==(const BankAccount& other) const;

    /**
     * @brief Compares whether this account balance is strictly less than another.
     * @param other The target BankAccount to compare against.
     * @return true if this account's balance is less than other's balance; false otherwise.
     */
    bool operator<(const BankAccount& other) const;

    /**
     * @brief Compares whether this account balance is strictly greater than another.
     * @param other The target BankAccount to compare against.
     * @return true if this account's balance is greater than other's balance; false otherwise.
     */
    bool operator>(const BankAccount& other) const;

    // ==========================================
    // Static Utility Functions
    // ==========================================

    /**
     * @brief Outputs an account's details (number, holder, and balance) to standard output.
     * @param account Constant reference to the BankAccount to display.
     */
    static void printAccount(const BankAccount& account);

    /**
     * @brief Prompts user for details via console input, validates, and instantiates an account.
     * @return A newly constructed BankAccount instance containing user-entered data.
     */
    static BankAccount createAccountFromInput();
};

#endif