# Parking Lot Design

# Problem Statement

Design a Parking Lot System.

The system should support:

- vehicle entry
- vehicle exit
- parking spot allocation
- ticket generation
- payment processing

---

# Main Entities

## ParkingLot

Represents entire parking lot.

Responsibilities:
- manage floors
- manage entry gates
- manage exit gates

---

## ParkingFloor

Represents a floor inside parking lot.

Contains:
- parking spots

---

## ParkingSpot

Represents a parking space.

Properties:
- spotId
- spotType
- isOccupied

Functions:
- parkVehicle()
- removeVehicle()

---

## Vehicle

Base Class

Properties:
- vehicleNumber
- vehicleType

---

## Car

inherits Vehicle

---

## Bike

inherits Vehicle

---

## Truck

inherits Vehicle

---

## Ticket

Generated when vehicle enters.

Properties:
- ticketId
- entryTime
- parkingSpot

---

## Payment

Handles parking payment.

Properties:
- paymentId
- amount

Functions:
- makePayment()

---

## EntryGate

Responsibilities:
- generate ticket
- assign parking spot

---

## ExitGate

Responsibilities:
- calculate parking fee
- process exit

---

# Relationships

ParkingLot
|
|---- ParkingFloor
        |
        |---- ParkingSpot

Vehicle
|
|---- Car
|---- Bike
|---- Truck

EntryGate ---- Ticket

Ticket ---- Vehicle

ExitGate ---- Payment

---

# Class Diagram

```text
+------------------+
|   ParkingLot     |
+------------------+
| floors           |
+------------------+

         |
         |
         v

+------------------+
| ParkingFloor     |
+------------------+
| spots            |
+------------------+

         |
         |
         v

+------------------+
| ParkingSpot      |
+------------------+
| spotId           |
| spotType         |
| isOccupied       |
+------------------+

         ^
         |
         |

+------------------+
| Vehicle          |
+------------------+
| vehicleNumber    |
| vehicleType      |
+------------------+
         ^
         |
 ---------------------
 |         |         |
Car      Bike      Truck

+------------------+
| Ticket           |
+------------------+
| ticketId         |
| entryTime        |
+------------------+

+------------------+
| Payment          |
+------------------+
| amount           |
+------------------+

+------------------+
| EntryGate        |
+------------------+

+------------------+
| ExitGate         |
+------------------+
```

---

# Interview Discussion

Questions interviewer may ask:

1. How will you find empty spots?
2. How will you support multiple floors?
3. How will you support different vehicle types?
4. How will you calculate parking fees?
5. How will you avoid assigning same spot twice?

---

# Easy Summary

Vehicle enters
→ EntryGate

EntryGate
→ creates Ticket

Ticket
→ assigned ParkingSpot

Vehicle exits
→ ExitGate

ExitGate
→ calculates fee

Payment completed
→ spot becomes free again

---

# Interview Discussion Answers

## 1. How will you find empty spots?

Maintain a list of parking spots.

Each ParkingSpot will have:

- spotId
- isOccupied

When vehicle enters:

- find first spot where isOccupied = false
- assign vehicle
- mark isOccupied = true

When vehicle exits:

- mark isOccupied = false

---

## 2. How will you support multiple floors?

ParkingLot will contain:

- List<ParkingFloor>

Each ParkingFloor contains:

- List<ParkingSpot>

Structure:

ParkingLot
|
|---- Floor1
|       |---- Spots
|
|---- Floor2
|       |---- Spots

This makes system scalable.

---

## 3. How will you support different vehicle types?

Create Vehicle as base class.

Derived classes:

- Car
- Bike
- Truck

ParkingSpot will also have:

- spotType

Examples:

CarSpot
BikeSpot
TruckSpot

Vehicle can only park in compatible spot.

---

## 4. How will you calculate parking fees?

Ticket stores:

- entryTime

At exit:

CurrentTime - EntryTime

Fee Formula:

Fee = Hours × Rate

Example:

2 Hours × ₹20

Fee = ₹40

Different vehicle types can have different rates.

---

## 5. How will you avoid assigning same spot twice?

Use:

- isOccupied flag

Before assigning:

check:

isOccupied == false

If occupied:

skip spot

After assignment:

isOccupied = true

This ensures one spot gets assigned to only one vehicle.