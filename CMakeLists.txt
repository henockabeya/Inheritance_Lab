cmake_minimum_required(VERSION 4.3)
project(Inheritance)

set(CMAKE_CXX_STANDARD 20)

add_executable(Inheritance main.cpp
        BankAccount.h
        BankAccount.cpp
        SavingsAccount.h
        CheckingAccount.h
        SavingsAccount.cpp
        CheckingAccount.cpp)
