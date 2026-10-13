# Lab: Bank Account Management System (Inheritance & Polymorphism)

**Author:** Henoc Kabeya  
**Date:** October 13, 2026  
**Course:** CS 272  

---

## 📌 Overview

This project extends a C++ Bank Account Management System by implementing **object-oriented inheritance** and **runtime polymorphism**. The program manages different specialized account types (`CheckingAccount` and `SavingsAccount`) derived from a common base class (`BankAccount`) using dynamic memory allocation and a unified menu-driven command-line interface (CLI).

---

## 🏗️ System Architecture & Class Hierarchy

```text
              ┌──────────────────┐
              │   BankAccount    │ (Base Class)
              └────────┬─────────┘
                       │
         ┌─────────────┴─────────────┐
         ▼                           ▼
┌──────────────────┐        ┌──────────────────┐
│ CheckingAccount  │        │  SavingsAccount  │ (Derived Classes)
└──────────────────┘        └──────────────────┘
