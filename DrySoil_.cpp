#include "DrySoil_.h"
#include "FruitfulSoil_.h" // For potential state transition after rain
#include "Cropfield.h" // Assuming this holds the state of the crop field
#include <iostream>

using namespace std;

// Constructor for DrySoil
DrySoil_::DrySoil_() {
    this->_name = "Dry";
}

// Harvest crops based on dry soil state
void DrySoil_::harvestCrops(Cropfield* cropField) {
    cout << "Harvesting crops in dry soil. Yield is minimal (x1)." << endl;
    int yield = cropField->getCurrentStored();  // Assuming Cropfield has getCurrentStored() method
    cropField->setCurrentStored(yield * 1);     // Minimal yield (1x)
}

// Simulate rain improving the dry soil
void DrySoil_::rain(Cropfield* cropField) {
    cout << "Rain improves the dry soil condition. Transitioning to Fruitful Soil." << endl;
    
    // Transition from DrySoil to FruitfulSoil after rain
    SoilState* fruitfulSoil = new FruitfulSoil_(); // Assuming FruitfulSoil_ is a valid soil state
    cropField->setSoilState(fruitfulSoil);        // Assuming Cropfield has setSoilState() method
}

// Get the name of this soil state
string DrySoil_::getName() {
    return _name;
}
