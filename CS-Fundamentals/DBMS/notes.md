
# DBMS Notes Day 7

# Database

Database is an organized collection of data.

It is used to:
- store data
- manage data
- retrieve data

Examples:
- Instagram user data
- Bank account data
- College student records

---

# DBMS

DBMS = Database Management System

DBMS is software used to manage databases.

Functions of DBMS:
- insert data
- update data
- delete data
- search data
- provide security
- manage backup

Examples:
- MySQL
- Oracle
- PostgreSQL
- MongoDB

---

# RDBMS

RDBMS = Relational Database Management System

In RDBMS:
- data is stored in tables
- tables are related using keys

Example:

Students Table

| StudentID | Name |
|---|---|
| 1 | Ujjwal |

Marks Table

| StudentID | Marks |
|---|---|
| 1 | 95 |

StudentID connects both tables.

---

# Difference Between DBMS and RDBMS

| DBMS | RDBMS |
|---|---|
| General database system | Relational database system |
| Data may not have relations | Data stored in related tables |
| Less structured | More structured |
| Less security | Better security |

---

# ER Diagram

ER Diagram = Entity Relationship Diagram

It is used to design database structure.

Main Components:

## Entity
Real world object.

Examples:
- Student
- Teacher
- Course

---

## Attributes
Properties of entity.

Student:
- name
- age
- roll number

---

## Relationship
Connection between entities.

Example:
Student enrolls in Course.

---

# Primary Key

Primary Key uniquely identifies each row in a table.

Properties:
- unique
- cannot be NULL

Example:

| StudentID | Name |
|---|---|
| 1 | Ujjwal |
| 2 | Rahul |

StudentID is Primary Key.

---

# Foreign Key

Foreign Key is a primary key from another table used to create relationship.

Example:

Students Table

| StudentID | Name |
|---|---|
| 1 | Ujjwal |

Marks Table

| StudentID | Marks |
|---|---|
| 1 | 95 |

Marks.StudentID is Foreign Key.

---

# Candidate Key

Candidate Key means possible primary keys.

Example:

| RollNo | Email | Name |
|---|---|---|
| 101 | abc@gmail.com | Ujjwal |

Both:
- RollNo
- Email

can uniquely identify rows.

So both are Candidate Keys.

One of them becomes Primary Key.

---

# Composite Key

Composite Key means:
multiple columns together uniquely identify a row.

Example:

| StudentID | CourseID |
|---|---|
| 1 | C101 |

StudentID alone is not enough.
CourseID alone is not enough.

Together:
StudentID + CourseID

form Composite Key.

---

# Normalization

Normalization means organizing database to:
- reduce duplicate data
- improve consistency
- avoid anomalies

Problems without normalization:
- Update Anomaly
- Insert Anomaly
- Delete Anomaly

---

# First Normal Form (1NF)

Rules:
- one cell should contain only one value
- atomic values only

Bad Example:

| Student | Subjects |
|---|---|
| Ujjwal | DBMS, OS |

Good Example:

| Student | Subject |
|---|---|
| Ujjwal | DBMS |
| Ujjwal | OS |

Memory Trick:
ONE CELL = ONE VALUE

---

# Second Normal Form (2NF)

Rules:
- table must already be in 1NF
- remove partial dependency

Partial dependency means:
column depends only on part of composite key.

Example:

| StudentID | CourseID | StudentName |
|---|---|---|

Primary Key:
StudentID + CourseID

But:
StudentName depends only on StudentID.

This is partial dependency.

Solution:
create separate Student table.

Memory Trick:
FULL KEY dependency required.

---

# Third Normal Form (3NF)

Rules:
- table must already be in 2NF
- remove transitive dependency

Transitive dependency means:
non-key column depends on another non-key column.

Example:

| StudentID | DeptID | DeptName |
|---|---|---|

DeptName depends on DeptID,
not directly on StudentID.

Solution:
create separate Department table.

Memory Trick:
Non-key should not depend on another non-key.

---

````md id="dbms9xp"
# Indexing

# What is Indexing?

Indexing means:

data ko fast search karne ka technique.

It improves query performance.

---

# Real Life Example

Book ke end me:
index page hota hai.

Agar kisi topic ka page number pata hai,
to pura book search nahi karna padta.

Same concept database me use hota hai.

---

# Without Index

Database:
line by line rows search karta hai.

This is called:

```sql
Full Table Scan
```

It is slow for large databases.

---

# With Index

Database directly required row tak pahuchta hai.

Search becomes fast.

---

# Example

Students Table

| ID | Name |
|---|---|
| 1 | Rahul |
| 2 | Ujjwal |
| 3 | Aman |

Query:

```sql
SELECT * FROM students
WHERE id = 2;
```

Without index:
database checks every row.

With index:
database directly jumps to ID = 2.

---

# Why Indexing Speeds Queries

Because:
search space reduces.

Without index:
Time Complexity:

```cpp
O(n)
```

With indexing:
Time Complexity becomes approximately:

```cpp
O(log n)
```

---

# B-Tree Index

Most databases use:

```text
B-Tree
```

for indexing.

---

# Why B-Tree is Used

Because:
- sorted data
- fast searching
- fast insertion
- fast deletion

---

# B-Tree Structure Example

```text
          50
        /    \
      20      80
```

Search:
80

Instead of checking all elements,
directly move right.

---

# Advantages of Indexing

- faster search
- faster SELECT queries
- reduced query execution time

---

# Disadvantages of Indexing

- extra memory required
- insert/update/delete can become slower

Because:
index also needs updates.

---

# ACID Properties

Transactions in DBMS follow:

```text
ACID
```

---

# Transaction

Transaction means:

group of database operations.

Example:
money transfer.

---

# Atomicity

Atomicity means:

```text
all or nothing
```

If one operation fails:
entire transaction fails.

Example:
money deducted but not credited should not happen.

---

# Consistency

Database should always remain valid and correct.

Rules and constraints should not break.

---

# Isolation

Multiple transactions should not interfere with each other.

---

# Durability

Once transaction is committed:
data becomes permanent.

Even after crash or restart,
data should remain saved.

---

# Easy Memory Trick

A → All or Nothing

C → Correct State

I → Independent Transactions

D → Data Permanent
````

---

# SQL Joins

# What is JOIN?

JOIN is used to combine data from multiple tables.

It is used when related data exists in different tables.

---

# Example Tables

Students

| ID | Name |
|---|---|
| 1 | Ujjwal |
| 2 | Rahul |
| 3 | Aman |

Marks

| ID | Marks |
|---|---|
| 1 | 95 |
| 2 | 88 |
| 4 | 76 |

---

# INNER JOIN

Returns only matching records from both tables.

Query:

```sql
SELECT *
FROM Students
INNER JOIN Marks
ON Students.ID = Marks.ID;
```

Output:

| ID | Name | Marks |
|---|---|---|
| 1 | Ujjwal | 95 |
| 2 | Rahul | 88 |

---

# Memory Trick

INNER = INTERSECTION

Only common records.

---

# LEFT JOIN

Returns:
- all rows from left table
- matching rows from right table

If no match:
NULL

Query:

```sql
SELECT *
FROM Students
LEFT JOIN Marks
ON Students.ID = Marks.ID;
```

Output:

| ID | Name | Marks |
|---|---|---|
| 1 | Ujjwal | 95 |
| 2 | Rahul | 88 |
| 3 | Aman | NULL |

---

# Memory Trick

LEFT JOIN = LEFT TABLE FULL

Left table always complete.

---

# RIGHT JOIN

Returns:
- all rows from right table
- matching rows from left table

If no match:
NULL

Query:

```sql
SELECT *
FROM Students
RIGHT JOIN Marks
ON Students.ID = Marks.ID;
```

Output:

| ID | Name | Marks |
|---|---|---|
| 1 | Ujjwal | 95 |
| 2 | Rahul | 88 |
| 4 | NULL | 76 |

---

# Memory Trick

RIGHT JOIN = RIGHT TABLE FULL

Right table always complete.

---

# FULL JOIN

Returns:
- all rows from left table
- all rows from right table

Matching records combined.

Non-matching records get NULL.

Query:

```sql
SELECT *
FROM Students
FULL OUTER JOIN Marks
ON Students.ID = Marks.ID;
```

Output:

| ID | Name | Marks |
|---|---|---|
| 1 | Ujjwal | 95 |
| 2 | Rahul | 88 |
| 3 | Aman | NULL |
| 4 | NULL | 76 |

---

# Easy Visual

Students IDs

```text
1 2 3
```

Marks IDs

```text
1 2 4
```

---

INNER JOIN

```text
1 2
```

---

LEFT JOIN

```text
1 2 3
```

---

RIGHT JOIN

```text
1 2 4
```

---

FULL JOIN

```text
1 2 3 4
```

---

# Interview Question

Difference Between INNER and LEFT JOIN?

INNER JOIN:
returns only matching rows.

LEFT JOIN:
returns all rows from left table and matching rows from right table.

---

# Easy Revision Trick

INNER → Common Records

LEFT → All Left Records

RIGHT → All Right Records

FULL → Everything