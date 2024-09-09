#include "FloodedSoil_.h"
#include "Cropfield.h"
#include <iostream>

using namespace std;

FloodedSoil_::FloodedSoil_() : SoilState("Flooded") {}

void FloodedSoil_::harvestCrops(Cropfield* cropField) {
    cout << "No crops can be harvested in flooded soil. Yield is 0." << endl;
    cropField->storeCrops(0);  // Reset crop storage as no crops can be harvested in flooded soil
}

void FloodedSoil_::rain(Cropfield* cropField) {
    cout << "Rain worsens the flooding, damaging crops." << endl;
    
    int currentStorage = cropField->getCurrentStorage();
    int damagedCrops = currentStorage * 0.5; // Assuming 50% of the crops are damaged by the rain
    cropField->storeCrops(currentStorage - damagedCrops);
    cout << damagedCrops << " units of crops were damaged due to the flooding." << endl;
}

std::string FloodedSoil_::getName() const {
    return SoilState::getName();
}
