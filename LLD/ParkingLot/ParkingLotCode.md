# Parking Lot - Basic C++ Design

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
    string vehicleNumber;
    string vehicleType;

    Vehicle(string number, string type) {
        vehicleNumber = number;
        vehicleType = type;
    }
};

class ParkingSpot {
public:
    int spotId;
    bool isOccupied;

    ParkingSpot(int id) {
        spotId = id;
        isOccupied = false;
    }

    void parkVehicle() {
        isOccupied = true;
    }

    void removeVehicle() {
        isOccupied = false;
    }
};

class Ticket {
public:
    int ticketId;

    Ticket(int id) {
        ticketId = id;
    }
};

class ParkingLot {
private:
    vector<ParkingSpot> spots;

public:

    ParkingLot(int totalSpots) {

        for(int i = 1; i <= totalSpots; i++) {
            spots.push_back(ParkingSpot(i));
        }
    }

    void parkVehicle(Vehicle &vehicle) {

        for(auto &spot : spots) {

            if(!spot.isOccupied) {

                spot.parkVehicle();

                cout << vehicle.vehicleNumber
                     << " parked at Spot "
                     << spot.spotId << endl;

                return;
            }
        }

        cout << "Parking Full" << endl;
    }

    void removeVehicle(int spotId) {

        for(auto &spot : spots) {

            if(spot.spotId == spotId) {

                spot.removeVehicle();

                cout << "Spot "
                     << spotId
                     << " is now free"
                     << endl;

                return;
            }
        }
    }
};

int main() {

    ParkingLot parkingLot(5);

    Vehicle car1("BR01AA1234", "Car");

    parkingLot.parkVehicle(car1);

    parkingLot.removeVehicle(1);

    return 0;
}
```