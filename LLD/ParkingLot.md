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

