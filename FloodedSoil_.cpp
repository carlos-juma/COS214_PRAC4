#include "FloodedSoil_.h"
#include "Cropfield.h"
#include <iostream>

using namespace std;

// Constructor for FloodedSoil
FloodedSoil_::FloodedSoil_() {
    this->_name = "Flooded";
}

// Harvest crops based on flooded soil state
void FloodedSoil_::harvestCrops(Cropfield* cropField) {
    cout << "No crops can be harvested in flooded soil. Yield is 0." << endl;
    cropField->setCurrentStored(0);  // Reset crop storage as no crops can be harvested in flooded soil
}

// Simulate rain worsening the flooded soil
void FloodedSoil_::rain(Cropfield* cropField) {
    cout << "Rain worsens the flooding, damaging crops." << endl;
    
    // Logic to further degrade the crop state
    int currentStorage = cropField->getCurrentStored();
    int damagedCrops = currentStorage * 0.5; // Assuming 50% of the crops are damaged by the rain
    cropField->setCurrentStored(currentStorage - damagedCrops); // Reduce crop storage by the damaged amount
    cout << damagedCrops << " units of crops were damaged due to the flooding." << endl;
}

// Get the name of this soil state
string FloodedSoil_::getName() {
    return _name;
}
