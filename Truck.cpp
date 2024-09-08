#include "Truck.h"
#include "FarmUnit.h"
#include <iostream>

using namespace std;

// Respond to an update from a FarmUnit
void Truck::update(FarmUnit* aUnit) {
    cout << "Truck is notified about the update in FarmUnit: " << aUnit->_farmName << endl;
    
    // Check specific conditions and decide whether the truck needs to act
    // For example, if the FarmUnit's storage is near full, the truck will collect the crops
    if (aUnit->getTotalCapacity() - aUnit->getCurrentStored() <= 10) { // Assuming threshold for storage is 10 units
        cout << "Storage is near full. Truck will start collecting crops from " << aUnit->_farmName << "." << endl;
        this->startEngine();
    }
}

// Start the truck's engine for operations (e.g., delivering fertilizers or collecting crops)
void Truck::startEngine() {
    cout << "Truck engine started. Ready to perform the operation (either delivering fertilizer or collecting crops)." << endl;
    // Logic to initiate the truck's operation could go here
}
