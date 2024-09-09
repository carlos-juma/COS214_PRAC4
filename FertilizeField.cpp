#include "FertilizeField.h"
#include "SoilState.h"
#include "DrySoil_.h"
#include "FruitfulSoil_.h"
#include <iostream>

using namespace std;

// Constructor for FertilizeField that decorates an existing Cropfield
FertilizeField::FertilizeField(Cropfield* baseField)
    : Cropfield(*baseField) {
    cout << "Fertilizing the field..." << endl;
    this->increaseProduction();  // Automatically apply fertilizer on creation
}

// Increase production by applying fertilizer and transitioning from DrySoil to FruitfulSoil
void FertilizeField::increaseProduction() {
    if (soilState->getName() == "Dry") {
        cout << "Applying fertilizer to the field. Transitioning from DrySoil to FruitfulSoil." << endl;
        delete soilState;  // Free the old DrySoil object
        soilState = new FruitfulSoil_();  // Transition to fruitful soil
    } else {
        cout << "Fertilizer already applied or not required." << endl;
    }
}

// Harvest crops based on the current soil state
void FertilizeField::harvestCrops() {
    if (currentStorage > 0) {
        cout << "Harvesting crops from the fertilized field with soil state: " << soilState->getName() << endl;
        soilState->harvestCrops(this);  // Call the harvest method based on the current soil state
        currentStorage = 0;  // Reset storage after harvesting
    } else {
        cout << "No crops to harvest." << endl;
    }
}

// Get the name of the current soil state
std::string FertilizeField::getSoilStateName() {
    return soilState->getName();
}
