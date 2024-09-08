#include "DeliveryTruck.h"
#include "FarmUnit.h"
#include <iostream>

using namespace std;

// Update method specific for DeliveryTruck
void DeliveryTruck::update(FarmUnit* aUnit) {
    cout << "DeliveryTruck notified by farm unit: " << aUnit->_farmName << endl;

    // Check if the storage is near full and crops need to be collected
    if (aUnit->getTotalCapacity() - aUnit->getCurrentStored() <= 10) {
        cout << "Storage is nearing full in " << aUnit->_farmName << ". DeliveryTruck will collect crops." << endl;
        this->startEngine();
        // Logic for collecting harvested crops
        aUnit->triggerCropCollection();  // Assuming triggerCropCollection() is available in FarmUnit
    } else {
        cout << "No need to collect crops from " << aUnit->_farmName << endl;
    }
}

// Start the truck's engine for collecting crops
void DeliveryTruck::startEngine() {
    cout << "DeliveryTruck engine started. Collecting crops..." << endl;
    // Logic to simulate the truck collecting crops
}
