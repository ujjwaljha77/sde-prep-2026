
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