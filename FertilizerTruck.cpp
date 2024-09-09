#include "FertilizerTruck.h"
#include <iostream>

using namespace std;

// Update method specific for FertilizerTruck
void FertilizerTruck::update(FarmUnit* aUnit) {
    cout << "FertilizerTruck [" << getName() << "] notified by farm unit: " << aUnit->getName() << endl;

    // Check if the soil state is "Dry" and needs fertilization
    if (aUnit->getSoilStateName() == "Dry") {
        cout << "Soil is dry. Delivering fertilizer." << endl;
        this->startEngine();
        aUnit->triggerFertilization();  // Assuming triggerFertilization exists in FarmUnit

        // After fertilization, ensure the state changes to avoid an infinite loop
        if (aUnit->getSoilStateName() == "Fruitful") {
            cout << "Fertilization successful. Soil is now Fruitful." << endl;
        }
    } else {
        cout << "No need for fertilizer." << endl;
    }
}
