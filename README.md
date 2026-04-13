🏦 Simple Banking System (C++ OOP)
📌 Overview

This project is a simple banking system built in C++ using object-oriented programming principles. It models different types of bank accounts and demonstrates concepts such as inheritance, encapsulation, and polymorphism.

The program allows users to create and interact with:

Checking accounts (allow overdraft)
Savings accounts (no overdraft + savings goal tracking)
Business accounts (no overdraft + business info)
🚀 Features
🔢 Randomly generated account numbers
💰 Deposit and withdrawal functionality
⚠️ Overdraft handling (varies by account type)
🧠 Savings goal tracking
🏢 Business account metadata (name + tax ID)
🔄 Polymorphic behavior using virtual functions
🧱 Class Structure
Account (Base Class)
Stores common data:
Name
ID
Balance
Account Number
Provides:
Deposit functionality
Virtual withdraw() function
Virtual getAccountType() function
Checking (Derived)
Allows overdraft
Displays warning if balance goes negative
Savings (Derived)
Prevents overdraft
Includes:
Savings goal
Goal progress tracking
Business (Derived)
Prevents overdraft
Includes:
Business name
Business tax ID
🛠️ How It Works

Each account type overrides the withdraw() function to define its own behavior:

Checking: Can go negative (overdraft allowed)
Savings: Blocks withdrawal if insufficient funds
Business: Blocks withdrawal if insufficient funds

This uses polymorphism, so the correct function is called automatically based on the account type.

▶️ How to Run
1. Compile
g++ main.cpp -o main
2. Run
./main
📷 Example Output
Balance: $900
Account Number: A1b2C3d4E5
Name: Hunter Thomas
ID: jgjdhdj12mkcvk
Account Type: Checking Account

Warning: Business account Cannot Be Overdrawn.
Balance: $30
...
🧠 Concepts Used
Object-Oriented Programming (OOP)
Inheritance
Encapsulation
Polymorphism (virtual + override)
Random number generation (for account IDs)
⚠️ Limitations
No persistent storage (data resets on run)
No user input (hardcoded test cases)
Minimal validation on inputs
Not production-level banking logic
🔮 Future Improvements
Add user input system (menu-based interface)
Implement file or database storage
Improve validation (negative deposits, etc.)
Add transfer functionality between accounts
Create a UI (CLI or GUI)
👤 Author

Hunter Thomas