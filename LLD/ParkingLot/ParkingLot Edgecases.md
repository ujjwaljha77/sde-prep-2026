# Edge Cases

## Parking Full

No empty spot available.

Return:

Parking Full

---

## Invalid Spot Number

Vehicle tries to exit from non-existing spot.

Handle error.

---

## Double Parking

Same spot cannot be assigned twice.

Use:

isOccupied flag

---

## Wrong Vehicle Type

Truck should not park in BikeSpot.

Check:

vehicleType == spotType

---

## Payment Failure

Do not free spot until payment succeeds.

---

## Multiple Floors

Search floor by floor for empty spots.

---

## Duplicate Vehicle Entry

Same vehicle should not enter twice.

Track vehicle numbers.