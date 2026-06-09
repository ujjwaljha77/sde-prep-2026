# Splitwise Design

# Problem Statement

Design a Splitwise System.

The system should support:

- creating users
- creating groups
- adding expenses
- splitting expenses
- tracking balances
- settling debts

---

# Main Entities

## User

Represents a user in Splitwise.

Properties:

- userId
- name
- email

---

## Group

Represents a group.

Examples:

- Goa Trip
- Flatmates
- Friends

Properties:

- groupId
- groupName
- users

---

## Expense

Represents a transaction.

Properties:

- expenseId
- amount
- paidBy
- participants

Functions:

- splitExpense()

---

## Balance

Stores money owed between users.

Example:

A paid ₹1000

B owes ₹500

C owes ₹500

Properties:

- lender
- borrower
- amount

---

# Relationships

Group
|
|---- Users

Expense
|
|---- Paid By User

Expense
|
|---- Shared Among Users

Balance
|
|---- User ↔ User

---

# Class Diagram

+------------------+
| User             |
+------------------+
| userId           |
| name             |
| email            |
+------------------+

+------------------+
| Group            |
+------------------+
| groupId          |
| groupName        |
| users            |
+------------------+

+------------------+
| Expense          |
+------------------+
| expenseId        |
| amount           |
| paidBy           |
+------------------+

+------------------+
| Balance          |
+------------------+
| lender           |
| borrower         |
| amount           |
+------------------+

---

# Expense Flow

Example:

Users:

A
B
C

Expense:

₹900

Paid By:

A

Shared Equally:

A
B
C

Each Share:

₹300

Result:

B owes A ₹300

C owes A ₹300

---

# Interview Discussion

## 1. How will you split equally?

Amount / Number of users

Example:

₹900 / 3

= ₹300 each

---

## 2. How will you support percentage split?

Store percentage.

Example:

A = 50%
B = 30%
C = 20%

Calculate share accordingly.

---

## 3. How will you track balances?

Use Balance object.

Example:

B owes A ₹300

Store:

borrower = B
lender = A
amount = 300

---

## 4. How will users settle debts?

Payment made.

Balance updated.

Example:

B pays A ₹300

Balance becomes 0.

---

## 5. How will you support groups?

Group contains:

- users
- expenses

Each expense belongs to a group.

---

# Easy Summary

User creates Group

↓

Users join Group

↓

Expense added

↓

Expense split

↓

Balances updated

↓

Users settle debts

↓

Balance becomes 0