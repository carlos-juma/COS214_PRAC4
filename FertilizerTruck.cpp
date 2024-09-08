#include "FertilizerTruck.h"
#include "FarmUnit.h"
#include "SoilState.h"
#include <iostream>

using namespace std;

// Update method specific for FertilizerTruck
void FertilizerTruck::update(FarmUnit* aUnit) {
    cout << "FertilizerTruck notified by farm unit: " << aUnit->_farmName << endl;

    // Check if the soil state is "Dry" and needs fertilization
    if (aUnit->getSoilStateName() == "Dry") {
        cout << "Soil is dry. FertilizerTruck will deliver fertilizer to " << aUnit->_farmName << endl;
        this->startEngine();
        // Logic for delivering fertilizer
        aUnit->triggerFertilization();  // Assuming triggerFertilization() is available in FarmUnit
    } else {
        cout << "No need for fertilizer in " << aUnit->_farmName << endl;
    }
}

// Start the truck's engine for delivering fertilizer
void FertilizerTruck::startEngine() {
    cout << "FertilizerTruck engine started. Delivering fertilizer..." << endl;
    // Logic to simulate the truck delivering fertilizer
}
