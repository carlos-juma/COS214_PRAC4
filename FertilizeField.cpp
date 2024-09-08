#include "FertilizeField.h"
#include "SoilState.h"
#include "DrySoil_.h"
#include "FruitfulSoil_.h"
#include <iostream>

using namespace std;

// Increase production by applying fertilizer and transitioning from DrySoil to FruitfulSoil
void FertilizeField::increaseProduction() {
    if (_soilState->getName() == "Dry") {
        cout << "Applying fertilizer to the field. Transitioning from DrySoil to FruitfulSoil." << endl;
        _soilState = new FruitfulSoil_();  // Transition to fruitful soil after applying fertilizer
    } else {
        cout << "Fertilizer already applied or not required." << endl;
    }
}

// Harvest crops based on the current soil state
void FertilizeField::harvestCrops() {
    cout << "Harvesting crops from the fertilized field with soil state: " << _soilState->getName() << endl;
    _soilState->harvestCrops(this);  // Call the harvest method based on the current soil state
    _currentStorage = 0;  // Reset storage after harvesting
}

// Get the name of the current soil state
string FertilizeField::getSoilStateName() {
    return _soilState->getName();
}
