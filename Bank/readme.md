# 👋 Hello young guns, I am Saksham Bansal

Welcome to my **Bank Management System** project — a C++ console application that simulates simple banking operations using Object-Oriented Programming concepts. Whether you're new to C++ or brushing up your skills, this project is a great way to understand how classes, objects, and friend functions come together in action.

---

## 🏦 What does it do?

This system allows you to:

- 👤 Add multiple employee accounts
- 💰 Deposit and Withdraw funds
- ⚡ Make Fast Payments
- 💳 Check account balances and validate credit limits
- 📱 Store and view personal details (name, mobile number, city pin)
- 🧾 Use a friend class to ensure the credit policy is respected

---

## 🧠 Concepts Covered

- **Classes and Objects**
- **Friend Classes**
- **Static Members**
- **Menu-Driven Programs**
- **Input/Output Operations**
- **Basic Validation Logic**

---

## 📌 Class Structure

### `Employee`
- Stores account and personal details
- Handles transactions (deposit, withdraw, fast pay)
- Validates credit usage
- Uses a static `bankname` field shared across all objects

### `Credit`
- A friend class to `Employee`
- Accesses private data to check credit policy adherence

---

## 🚀 How to Run

1. Save the code in `bank_system.cpp`
2. Open terminal/command prompt
3. Compile the code:

```bash
g++ -o bank_system bank_system.cpp
./bank_system
```
