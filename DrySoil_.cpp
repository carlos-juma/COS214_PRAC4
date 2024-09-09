#include "DrySoil_.h"
#include "Cropfield.h"
#include <iostream>

using namespace std;

DrySoil_::DrySoil_() : SoilState("Dry") {}

void DrySoil_::harvestCrops(Cropfield* cropField) {
    cout << "Harvesting crops in dry soil. Minimal yield." << endl;
    // Add logic to modify crop yield
}

void DrySoil_::rain(Cropfield* cropField) {
    cout << "Rain in dry soil. No significant effect." << endl;
    // Add logic to handle rain in dry soil
}

std::string DrySoil_::getName() const {
    return SoilState::getName();
}
