# 🏦 Simple Banking System (C++ OOP)

## 📌 Overview
This project is a command-line banking system built in C++ that demonstrates core object-oriented programming concepts. It models multiple account types with shared behavior while allowing each type to define its own transaction rules.

The goal of this project is to apply inheritance, encapsulation, and polymorphism in a practical system rather than just isolated examples.

---

## 🚀 Key Features

- Random Account Number Generation  
- Deposit & Withdrawal System  
- Account-Specific Overdraft Rules:
  - Checking → allows overdraft with warning  
  - Savings → blocks overdraft  
  - Business → blocks overdraft  
- Savings Goal Tracking  
- Business Account Metadata (name + tax ID)  
- Polymorphic Behavior using virtual functions  

---

## 🧱 Architecture

### Base Class: Account
Handles shared functionality:
- Customer name and ID  
- Account balance  
- Auto-generated account number  
- Deposit handling  
- Virtual methods:
  - withdraw()
  - getAccountType()

---

### Derived Classes

#### Checking
- Allows overdraft
- Warns when balance goes negative

#### Savings
- Prevents overdraft
- Includes savings goal tracking

#### Business
- Prevents overdraft
- Stores business name and tax ID

---

## ⚙️ How It Works

Each account type overrides the withdraw() function, allowing behavior to differ without conditional logic.

Example:
account->withdraw(amount);

This automatically calls the correct version based on the object type.

---

## ▶️ Getting Started

### Compile
g++ main.cpp -o main

### Run
./main

---

## 📷 Example Output

Balance: $900  
Account Number: Xy7A9kL2Qp  
Name: Hunter Thomas  
ID: jgjdhdj12mkcvk  
Account Type: Checking Account  

Warning: Business account Cannot Be Overdrawn.  
Balance: $30  

---

## 🧠 Concepts Demonstrated

- Object-Oriented Programming (OOP)  
- Inheritance  
- Encapsulation  
- Polymorphism  
- Random number generation  

---

## ⚠️ Limitations

- No persistent storage  
- No user input  
- Minimal validation  
- Not production-level  

---

## 🔮 Future Improvements

- Add CLI menu system  
- Add database or file storage  
- Add transfer functionality  
- Improve validation  
- Build GUI or web interface  

---

## 👤 Author
Hunter Thomas
