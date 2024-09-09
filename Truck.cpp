#include "Truck.h"
#include <iostream>

using namespace std;

// Respond to updates from a FarmUnit
void Truck::update(FarmUnit* aUnit) {
    cout << "Truck [" << name << "] is notified about the update in the FarmUnit." << endl;
    // Logic for updating the truck based on the farm unit's state can go here
}

// Start the truck's engine
void Truck::startEngine() {
    cout << "Truck [" << name << "] engine started." << endl;
}
